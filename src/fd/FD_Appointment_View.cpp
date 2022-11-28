#include "FD_Appointment_View.h"
#include <iostream>
#include <iomanip>

void FD_Appointment_View::show_list_view(const std::vector<std::map<std::string, std::string>>& data){
    show_header();
    show_list_header();
    if(data.size()==0){
        show_list_empty_message();
    } else {
        show_column_header();
    }
    show_list_contents(data);
    show_separator();
    show_menu();
}; 

void FD_Appointment_View::show_list_empty_message(){
    std::cout << "No appointments stored!" << '\n';
};
void FD_Appointment_View::show_list_header(){
    std::cout << "Appointment List:" << '\n';
};
void FD_Appointment_View::show_column_header(){
    std::cout << std::left << std::setfill(' ') << std::setw(3) << "ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Day";
    std::cout << " . ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Month";
    std::cout << " . ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Year";
    std::cout << '\n';
};
void FD_Appointment_View::show_list_contents(const std::vector<std::map<std::string, std::string>>& data){
    for(auto current_element : data){
        std::cout << std::left << std::setfill(' ') << std::setw(3) << current_element["id"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["day"];
        std::cout << " . ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["month"];
        std::cout << " . ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["year"];
        std::cout << '\n';
    };
};
