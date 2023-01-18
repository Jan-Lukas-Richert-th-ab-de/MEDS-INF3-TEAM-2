#include "FD_Summary_Statistics_View.h"
#include <iostream>
#include <iomanip>

void FD_Summary_Statistics_View::show_list_view(const std::vector<std::map<std::string, std::string>> &data) {
   
show_header();
show_column_header();
if (data.empty()){
std::cout << "No data found." << std::endl;
} else {

}
show_separator();
show_menu();
}


void FD_Summary_Statistics_View::show_doctor_summary(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

if (data.empty()){
show_list_empty_message();
} else {
std::cout << "Average occupancy time of a doctor per day: " << std::endl;
for (const auto& row : data) {
std::cout << "ID: " << row.at("ID") << std::endl;
std::cout << "Name: " << row.at("Name") << std::endl;
std::cout << "specialization: " << row.at("Specialization") << std::endl;
//std::cout << Average occupancy of the consulting room: " << row.at("Avg Room Duration") << std::endl;
std::cout << "Average duration of use of the doctor: " << row.at("Avg Doctor Duration") << std::endl;
}
}}



inline void FD_Summary_Statistics_View::show_room_occupancy_summary(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

if (data.empty()){
show_list_empty_message();
} else {
    
std::cout << "Average occupancy time of a room per day: " << std::endl;

for (const auto& row : data) {
std::cout << "ID: " << row.at("ID") << std::endl;
std::cout << "Name: " << row.at("Name") << std::endl;
std::cout << "Number: " << row.at("Number") << std::endl;
std::cout << "Average occupancy of the consulting room: " << row.at("Avg Room Duration") << std::endl;
}
}
}
void FD_Summary_Statistics_View::show_doctor_summary_per_week(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

if (data.empty()){
   show_list_empty_message();
} else {
std::cout << "Average occupancy time of a doctor per day: " << std::endl;
for (const auto& row : data) {
std::cout << "ID: " << row.at("ID") << std::endl;
std::cout << "Name: " << row.at("Name") << std::endl;
std::cout << "specialization: " << row.at("Specialization") << std::endl;
//std::cout << Average occupancy of the consulting room: " << row.at("Avg Room Duration") << std::endl;
std::cout << "Average duration of use of the doctor: " << row.at("Avg Doctor Duration") << std::endl;
}
}}

inline void FD_Summary_Statistics_View::show_room_occupancy_summary_per_week(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

if (data.empty()){
show_list_empty_message();
} else {
    
std::cout << "Average occupancy time of a room per day: " << std::endl;

for (const auto& row : data) {
std::cout << "ID: " << row.at("ID") << std::endl;
std::cout << "Name: " << row.at("Name") << std::endl;
std::cout << "Number: " << row.at("Number") << std::endl;
std::cout << "Average occupancy of the consulting room: " << row.at("Avg Room Duration") << std::endl;
}
}
}


void FD_Summary_Statistics_View::show_column_header() {
std::cout << std::left << std::setfill('-') << std::setw(60) << "" << std::endl;
}
inline void FD_Summary_Statistics_View::show_list_empty_message() {
std::cout << "No data stored!" << '\n';
}
