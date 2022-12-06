#include "FD_View.h"
#include <iostream>
#include <iomanip>

void FD_View::show_header()
{
    std::cout << std::setfill('*') << std::setw(60) << '*' << '\n';
};
void FD_View::show_separator()
{
    std::cout << std::setfill('-') << std::setw(60) << '-' << '\n';
};
void FD_View::show_menu()
{
    int option_number{1};
    std::cout << OPTIONS_HEADER << '\n';
    for (auto current_option : OPTIONS_LIST)
    {
        std::cout << std::setfill(' ') << std::setw(2) << option_number << ": " << current_option << '\n';
        ++option_number;
    }
};
void FD_View::show_menu_CORE_RESSURCES()
{
    int option_number{1};
    std::cout << OPTIONS_HEADER << '\n';
    for (auto current_option : OPTIONS_LIST_CORE_RESSURCES)
    {
        std::cout << std::setfill(' ') << std::setw(2) << option_number << ": " << current_option << '\n';
        ++option_number;
    }
};
void FD_View::show_menu_MAIN()
{
    int option_number{1};
    std::cout << OPTIONS_HEADER << '\n';
    for (auto current_option : OPTIONS_LIST_MAIN)
    {
        std::cout << std::setfill(' ') << std::setw(2) << option_number << ": " << current_option << '\n';
        ++option_number;
    }
};
