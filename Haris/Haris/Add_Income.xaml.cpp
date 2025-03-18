#include "pch.h"
#include "Add_Income.xaml.h"
#if __has_include("Add_Income.g.cpp")
#include "Add_Income.g.cpp"
#include"Main_Page.xaml.h"
#endif
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <fstream>
#include <string>
#include <winrt/Windows.Storage.h>
#include <Windows.h>

using namespace std;
using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::Storage;


using namespace winrt;
using namespace Microsoft::UI::Xaml;


using namespace std;




// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Haris::implementation
{
    int32_t Add_Income::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Add_Income::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void Add_Income::AddIncomeButton_Click(IInspectable const& , Microsoft::UI::Xaml::RoutedEventArgs const& )
    {

        // Get the current working directory (where the .exe is located)
        char buffer[MAX_PATH];
        GetModuleFileNameA(NULL, buffer, MAX_PATH);
        string exePath = string(buffer);
        string exeDir = exePath.substr(0, exePath.find_last_of("\\/")); // Get directory path

        // Define the file path in the root folder (same directory as the .exe)
        string filePath = exeDir + "\\income.txt";

        // Get the input values from UI
        hstring incomeText = IncomeInput().Text();
        double amount = 0.0;

        try {
            amount = stod(to_string(incomeText)); // Convert to double
            if (amount <= 0) {
                throw invalid_argument("Invalid input");
            }
        }
        catch (...) {
            OutputMessage().Text(L"? Please enter a valid positive numeric value for income.");
            return;
        }

        // Determine the selected income type
        string source;
        if (SalaryRadio().IsChecked().Value()) {
            source = "Salary";
        }
        else if (BusinessRadio().IsChecked().Value()) {
            source = "Business";
        }
        else if (InvestmentRadio().IsChecked().Value()) {
            source = "Investment";
        }
        else {
            OutputMessage().Text(L"? Please select an income type.");
            return;
        }

        // Save to file
        ofstream file(filePath, ios::app);
        if (!file) {
            OutputMessage().Text(L"? Error opening income.txt for writing.");
            return;
        }

        file << amount << " - " << source << endl;
        file.close();

        // Show success message
        OutputMessage().Text(L"? Income added successfully! File saved at: " + to_hstring(filePath));

        // Clear input fields after adding
        IncomeInput().Text(L"");
    }

    void Add_Income::BackButton_Click(IInspectable const& , Microsoft::UI::Xaml::RoutedEventArgs const& )
    {

        auto frame = winrt::Microsoft::UI::Xaml::Controls::Frame();
        this->Content(frame);
        frame.Navigate(winrt::xaml_typename<Haris::Main_Page>());
    }

    /*void Add_Income::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }*/
}
