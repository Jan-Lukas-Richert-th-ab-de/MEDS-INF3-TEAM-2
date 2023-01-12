#include "FD_Room_View.h"
#include <iostream>
#include <iomanip>

void FD_Room_View::show_list_view(const std::vector<std::map<std::string, std::string>> &data)
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

void FD_Room_View::show_list_empty_message()
{
    std::cout << "No rooms stored!" << '\n';
};
void FD_Room_View::show_list_header()
{
    std::cout << "Room List:" << '\n';
};
void FD_Room_View::show_column_header()
{
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Room ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Room Description";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Room Number";
    std::cout << '\n';
};
void FD_Room_View::show_list_contents(const std::vector<std::map<std::string, std::string>> &data)
{
    for (auto current_element : data)
    {
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["id"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(20) << current_element["room_description"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(20) << current_element["room_number"];
        std::cout << '\n';
    };
};
