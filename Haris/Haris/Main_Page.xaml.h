#pragma once

#include "Main_Page.g.h"

namespace winrt::Haris::implementation
{
    struct Main_Page : Main_PageT<Main_Page>
    {
        Main_Page()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void addMonthlyIncomeButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void incomeButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void outIncomeButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void reportButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        
        
    };
}

namespace winrt::Haris::factory_implementation
{
    struct Main_Page : Main_PageT<Main_Page, implementation::Main_Page>
    {
    };
}
