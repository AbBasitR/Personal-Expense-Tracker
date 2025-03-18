#pragma once

#include "Expense_Page.g.h"

namespace winrt::Haris::implementation
{
    struct Expense_Page : Expense_PageT<Expense_Page>
    {
        Expense_Page()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
        // Event handlers for button clicks
        void AddExpenseButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        void BackButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        //void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::Haris::factory_implementation
{
    struct Expense_Page : Expense_PageT<Expense_Page, implementation::Expense_Page>
    {
    };
}
