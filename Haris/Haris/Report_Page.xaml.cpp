#include "pch.h"
#include "Report_Page.xaml.h"
#if __has_include("Report_Page.g.cpp")
#include "Report_Page.g.cpp"
#endif
#include <fstream>
#include <string>
#include <sstream>
#include <winrt/Windows.Foundation.h>
using namespace std;
#include "Main_Page.xaml.h"
#include <windows.h>
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.UI.Xaml.Controls.h"
#include <winrt/Windows.UI.Xaml.Interop.h>


using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::Foundation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Haris::implementation
{
    int32_t Report_Page::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Report_Page::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    // Function to read total amount from file
    double ReadTotalFromFile(const string& filePath, hstring& detailsOutput) {
        ifstream file(filePath);
        if (!file) {
            detailsOutput = L"Error: Unable to open file!";
            return 0.0;
        }

        string line;
        double totalAmount = 0.0;
        wstringstream detailsStream;

        while (getline(file, line)) {
            size_t pos = line.find(" - ");
            if (pos != string::npos) {
                double amount = stod(line.substr(0, pos)); // Extract amount
                totalAmount += amount;
                detailsStream << winrt::to_hstring(line) << L"\n"; // Convert line to hstring
            }
        }

        file.close();
        detailsOutput = detailsStream.str();
        return totalAmount;
    }


    void Report_Page::ReportButton_Click(IInspectable const&, RoutedEventArgs const&)
    {

        char buffer[MAX_PATH];
        GetModuleFileNameA(NULL, buffer, MAX_PATH);
        string exePath = string(buffer);
        string exeDir = exePath.substr(0, exePath.find_last_of("\\/"));

        // File paths
        string incomeFilePath = exeDir + "\\income.txt";
        string expenseFilePath = exeDir + "\\expense.txt";

        // Read income and expenses
        hstring incomeDetails, expenseDetails;
        double totalIncome = ReadTotalFromFile(incomeFilePath, incomeDetails);
        double totalExpense = ReadTotalFromFile(expenseFilePath, expenseDetails);
        double remainingAmount = totalIncome - totalExpense;
        //std::wstring remainingText = L"Remaining: $" + std::to_wstring(remainingAmount);
        // ✅ Correct way to access UI elements
        IncomeText().Text(incomeDetails);
        ExpenseText().Text(expenseDetails);
        winrt::hstring displayText = L"Remaining: $" + winrt::to_hstring(remainingAmount);
        RemainingAmountText().Text(displayText);
    }

    void Report_Page::BackButton_Click(IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&)
    {

        auto frame = winrt::Microsoft::UI::Xaml::Controls::Frame();
        this->Content(frame);
        frame.Navigate(winrt::xaml_typename<Haris::Main_Page>());
    }
}
