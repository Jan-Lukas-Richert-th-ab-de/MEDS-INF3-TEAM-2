#include "FD_Appointment_View.h"
#include <iostream>
#include <iomanip>

void FD_Appointment_View::show_list_view(const std::vector<std::map<std::string, std::string>> &data)
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
void FD_Appointment_View::show_list_view_data(const std::vector<std::map<std::string, std::string>> &data)
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
};

void FD_Appointment_View::show_list_empty_message()
{
    std::cout << "No appointments stored!" << '\n';
};
void FD_Appointment_View::show_list_header()
{
    std::cout << "Appointment List:" << '\n';
};
void FD_Appointment_View::show_column_header() // Position, Abstand
{
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Date";
    std::cout << " . ";
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Month";
    std::cout << " . ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Month";
    std::cout << " . ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Year";
    std::cout << " . ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Time_start";
    std::cout << " . ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Time";
    std::cout << " . ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Doctor_id";
    std::cout << " . ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Patient_id";
    std::cout << " . ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Room_id";
    std::cout << '\n';
};
void FD_Appointment_View::show_list_contents(const std::vector<std::map<std::string, std::string>> &data)
{
    for (auto current_element : data)
    {
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["id"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["day"];
        std::cout << " . ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["month"];
        std::cout << " . ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["year"];
        std::cout << " . ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["time_start"];
        std::cout << " . ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["time"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["doctor"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["patient"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["room"];
        std::cout << '\n';
    };
};
