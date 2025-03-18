#pragma once

#include "Add_Income.g.h"
#include <winrt/Microsoft.UI.Xaml.Controls.h>

namespace winrt::Haris::implementation
{
    struct Add_Income : Add_IncomeT<Add_Income>
    {
        Add_Income()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void AddIncomeButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        void BackButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        /*void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);*/
    };
}

namespace winrt::Haris::factory_implementation
{
    struct Add_Income : Add_IncomeT<Add_Income, implementation::Add_Income>
    {
    };
}
