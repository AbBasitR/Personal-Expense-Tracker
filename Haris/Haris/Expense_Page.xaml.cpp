#include "pch.h"
#include "Expense_Page.xaml.h"
#include "Expense_Page.g.cpp"
#if __has_include("Expense_Page.g.cpp")
#include"Main_Page.xaml.h"
#endif


#include <fstream>
#include <string>
#include <Windows.h>




#include <winrt/Windows.UI.Xaml.Interop.h>

using namespace std;
using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::Storage;


using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Haris::implementation
{
    int32_t Expense_Page::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Expense_Page::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void Expense_Page::AddExpenseButton_Click(IInspectable const& , Microsoft::UI::Xaml::RoutedEventArgs const& )
    {
        // Get the current working directory (where the .exe is located)
        char buffer[MAX_PATH];
        GetModuleFileNameA(NULL, buffer, MAX_PATH);
        string exePath = string(buffer);
        string exeDir = exePath.substr(0, exePath.find_last_of("\\/")); // Get directory path

        // Define the file path in the root folder (same directory as the .exe)
        string filePath = exeDir + "\\expense.txt";

        // Get the input values from UI
        hstring expenseText = ExpenseInput().Text();
        double amount = 0.0;

        try {
            amount = stod(to_string(expenseText)); // Convert to double
            if (amount <= 0) {
                throw invalid_argument("Invalid input");
            }
        }
        catch (...) {
            OutputMessage().Text(L"? Please enter a valid positive numeric value for expense.");
            return;
        }

        // Determine the selected expense category
        string category;
        if (FoodRadio().IsChecked().Value()) {
            category = "Food";
        }
        else if (RentRadio().IsChecked().Value()) {
            category = "Rent";
        }
        else if (BillsRadio().IsChecked().Value()) {
            category = "Bills";
        }
        else {
            OutputMessage().Text(L"? Please select an expense category.");
            return;
        }

        // Save to file
        ofstream file(filePath, ios::app);
        if (!file) {
            OutputMessage().Text(L"? Error opening expense.txt for writing.");
            return;
        }

        file << amount << " - " << category << endl;
        file.close();

        // Show success message
        OutputMessage().Text(L"? Expense added successfully! File saved at: " + to_hstring(filePath));

        // Clear input fields after adding
        ExpenseInput().Text(L"");

    }

    void Expense_Page::BackButton_Click(IInspectable const& , Microsoft::UI::Xaml::RoutedEventArgs const& )
    {

        auto frame = winrt::Microsoft::UI::Xaml::Controls::Frame();
        this->Content(frame);
        frame.Navigate(winrt::xaml_typename<Haris::Main_Page>());
    }

    /*void Expense_Page::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }*/
}
