#pragma once

#include "Report_Page.g.h"

namespace winrt::Haris::implementation
{
    struct Report_Page : Report_PageT<Report_Page>
    {
        Report_Page()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ReportButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void BackButton_Click(IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);
    };
}

namespace winrt::Haris::factory_implementation
{
    struct Report_Page : Report_PageT<Report_Page, implementation::Report_Page>
    {
    };
}
