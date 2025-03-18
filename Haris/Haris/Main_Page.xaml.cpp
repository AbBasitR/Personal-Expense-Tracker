#include "pch.h"
#include "Main_Page.xaml.h"
#if __has_include("Main_Page.g.cpp")
#include "Main_Page.g.cpp"
#include "Add_Income.xaml.h"
#include "Expense_Page.xaml.h"
#include "Report_Page.xaml.h"
#endif
#include <winrt/Windows.UI.Xaml.Interop.h>
//#include <Main_Page.xaml.g.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Haris::implementation
{
    int32_t Main_Page::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Main_Page::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void Main_Page::addMonthlyIncomeButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        auto frame = winrt::Microsoft::UI::Xaml::Controls::Frame();
        this->Content(frame);
        frame.Navigate(winrt::xaml_typename<Haris::Add_Income>());
    }
    void Main_Page::incomeButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        auto frame = winrt::Microsoft::UI::Xaml::Controls::Frame();
        this->Content(frame);
        frame.Navigate(winrt::xaml_typename<Haris::Expense_Page>());
    }
    void Main_Page::outIncomeButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        outIncomeButton().Content(box_value(L"Coming Soon"));
    }
    void Main_Page::reportButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        auto frame = winrt::Microsoft::UI::Xaml::Controls::Frame();
        this->Content(frame);
        frame.Navigate(winrt::xaml_typename<Haris::Report_Page>());

        
    }
}
