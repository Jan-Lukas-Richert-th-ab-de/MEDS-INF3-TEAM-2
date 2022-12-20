#include "FD_Summary_Statistics_View.h"
#include "AR_Summary_Statistics.h"
#include <iostream>
#include <iomanip>



void FD_Summary_Statistics_View::show_list_view(const std::vector<std::map<std::string, std::string>> &data)
{
    show_header();
    show_list_header();
    if (data.size() == 0)
    {
        show_list_empty_message();
    }
    else
    {
        show_column_header();
    }
    show_list_contents(data);
    show_separator();
    show_menu();
};

void FD_Summary_Statistics_View::show_list_empty_message()
{
    std::cout << "No data stored!" << '\n';
};
void FD_Summary_Statistics_View::show_list_header()
{
    std::cout << "Data List:" << '\n';
};
void FD_Summary_Statistics_View::show_column_header()
{
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Description";
  
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Total Appointments";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Average Appointments";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Average duration";
    std::cout << '\n';
};
void FD_Summary_Statistics_View::show_list_contents(const std::vector<std::map<std::string, std::string>> &data)
{
    for (auto current_element : data)
    {
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["id"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(20) << current_element["description"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(20) << current_element["appointment_count"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(20) << current_element["result"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(20) << current_element["average_duration"];
        std::cout << '\n';
    };
};








