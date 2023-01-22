#include "FD_Summary_Statistics_View.h"
#include <iostream>
#include <iomanip>
#include "ER_appointment.h"

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
//when (data.size() > 0) { show data in table view and 
    if (data.size() == 0){
show_list_empty_message();
} else {
   
std::cout << "Average occupancy time of a doctor per day: " << std::endl;
for (const auto& row : data) {
std::cout << "Doctor ID: " << row.at("ID") << std::endl;
std::cout << "Name: " << row.at("Name") << std::endl;
std::cout << "specialization: " << row.at("Specialization") << std::endl;
double avgDoctorDuration = std::stod(row.at("Avg Doctor Duration"));
std::cout << "Average use of the doctor: " << std::setprecision(2) << std::fixed << avgDoctorDuration<< " minutes" << std::endl;}
}}



inline void FD_Summary_Statistics_View::show_room_occupancy_summary(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

    if (data.size() == 0){
show_list_empty_message();
} else {
    
std::cout << "Average occupancy time of a room per day: " << std::endl;

for (const auto& row : data) {
std::cout << "Room ID: " << row.at("ID") << std::endl;
std::cout << "Name: " << row.at("Name") << std::endl;
std::cout << "Number: " << row.at("Number") << std::endl;
double avgR = std::stod(row.at("Avg Room Duration"));
std::cout << "Average duration of use of the room: " << std::setprecision(2) << std::fixed << avgR << " minutes"<<std::endl;
}
}
}
void FD_Summary_Statistics_View::show_doctor_summary_per_week(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

    if (data.size() == 0){
   show_list_empty_message();
} else {
std::cout << "Average occupancy time of a doctor per week: " << std::endl;
for (const auto& row : data) {
std::cout << "Doctor ID: " << row.at("ID") << std::endl;
std::cout << "Name: " << row.at("Name") << std::endl;
std::cout << "specialization: " << row.at("Specialization") << std::endl;
double avgDoctorDuration = std::stod(row.at("Avg Doctor Duration"));
std::cout << "Average use of the doctor: " << std::setprecision(2) << std::fixed << avgDoctorDuration<< " minutes" << std::endl;}
}}

inline void FD_Summary_Statistics_View::show_room_occupancy_summary_per_week(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

    if (data.size() == 0){
show_list_empty_message();
} else {
    
std::cout << "Average occupancy time of a room per day: " << std::endl;

for (const auto& row : data) {
std::cout << "Room ID: " << row.at("ID") << std::endl;
std::cout << "Name: " << row.at("Name") << std::endl;
std::cout << "Number: " << row.at("Number") << std::endl;
double avgR = std::stod(row.at("Avg Room Duration"));
std::cout << "Average duration of use of the room: " << std::setprecision(2) << std::fixed << avgR << " minutes"<< std::endl;
}
}
}


void FD_Summary_Statistics_View::show_column_header() {
std::cout << std::left << std::setfill('-') << std::setw(60) << "" << std::endl;
}
inline void FD_Summary_Statistics_View::show_list_empty_message() {
std::cout << "No data stored!" << '\n';
}
