<<<<<<< HEAD
#include "FD_Standard_Reporting_View.h"
#include <iostream>
#include <iomanip>
void FD_Standard_Reporting_View::show_list_view(const std::vector<std::map<std::string, std::string>> &data) {
   

if (data.empty()){
std::cout << "No data found." << std::endl;
} else {

}
show_separator();
show_menu();
}


void FD_Standard_Reporting_View::show_view_report_doctor(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

if (data.empty()){
show_list_empty_message();
} else {
   system("cls");

    

    std::cout << std::left << std::setfill(' ') << std::setw(3) << "ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(25) << "Doctor Name";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(15) << "Room Number";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Date";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Time";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Room ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Patient ID";
    std::cout << '\n';
    for(auto current_element : data){
        std::cout << std::left << std::setfill(' ') << std::setw(3) << current_element["ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(25) << current_element["Doctor Name"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(15) << current_element["Room Number"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Date"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Time"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Room ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Patient ID"];
        std::cout << '\n';
    }
}

};




inline void FD_Standard_Reporting_View::show_view_report_room(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

if (data.empty()){
show_list_empty_message();
} else {
   system("cls");

    

    std::cout << std::left << std::setfill(' ') << std::setw(3) << "ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(25) << "Doctor Name";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(15) << "Room Number";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Date";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Time";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Room ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Patient ID";
    std::cout << '\n';
    for(auto current_element : data){
        std::cout << std::left << std::setfill(' ') << std::setw(3) << current_element["ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(25) << current_element["Doctor Name"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(15) << current_element["Room Number"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Date"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Time"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Room ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Patient ID"];
        std::cout << '\n';
    }
}
};
void FD_Standard_Reporting_View::show_view_report_doctor_week(const std::vector<std::map<std::string, std::string>> &data) {
      system("cls");

if (data.empty()){
show_list_empty_message();
} else {
   system("cls");

    

    std::cout << std::left << std::setfill(' ') << std::setw(3) << "ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(25) << "Doctor Name";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(15) << "Room Number";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Date";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Time";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Room ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Patient ID";
    std::cout << '\n';
    for(auto current_element : data){
        std::cout << std::left << std::setfill(' ') << std::setw(3) << current_element["ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(25) << current_element["Doctor Name"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(15) << current_element["Room Number"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Date"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Time"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Room ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Patient ID"];
        std::cout << '\n';
    }
}
};
inline void FD_Standard_Reporting_View::show_view_report_room_week(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

if (data.empty()){
show_list_empty_message();
} else {
   system("cls");

    

    std::cout << std::left << std::setfill(' ') << std::setw(3) << "ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(25) << "Doctor Name";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(15) << "Room Number";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Date";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Time";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Room ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Patient ID";
    std::cout << '\n';
    for(auto current_element : data){
        std::cout << std::left << std::setfill(' ') << std::setw(3) << current_element["ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(25) << current_element["Doctor Name"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(15) << current_element["Room Number"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Date"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Time"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Room ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Patient ID"];
        std::cout << '\n';
    }
}
};


inline void FD_Standard_Reporting_View::show_list_empty_message() {
std::cout << "No data stored!" << '\n';
}
=======
#include "FD_Standard_Reporting_View.h"
#include <iostream>
#include <iomanip>
void FD_Standard_Reporting_View::show_list_view(const std::vector<std::map<std::string, std::string>> &data) {
   

if (data.empty()){
std::cout << "No data found." << std::endl;
} else {

}
show_separator();
show_menu();
}


void FD_Standard_Reporting_View::show_view_report_doctor(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

if (data.empty()){
show_list_empty_message();
} else {
   system("cls");

    

    std::cout << std::left << std::setfill(' ') << std::setw(3) << "ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(25) << "Doctor Name";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(15) << "Room Number";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Date";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Time";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Room ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Patient ID";
    std::cout << '\n';
    for(auto current_element : data){
        std::cout << std::left << std::setfill(' ') << std::setw(3) << current_element["ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(25) << current_element["Doctor Name"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(15) << current_element["Room Number"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Date"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Time"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Room ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Patient ID"];
        std::cout << '\n';
    }
}

};




inline void FD_Standard_Reporting_View::show_view_report_room(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

if (data.empty()){
show_list_empty_message();
} else {
   system("cls");

    

    std::cout << std::left << std::setfill(' ') << std::setw(3) << "ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(25) << "Doctor Name";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(15) << "Room Number";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Date";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Time";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Room ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Patient ID";
    std::cout << '\n';
    for(auto current_element : data){
        std::cout << std::left << std::setfill(' ') << std::setw(3) << current_element["ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(25) << current_element["Doctor Name"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(15) << current_element["Room Number"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Date"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Time"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Room ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Patient ID"];
        std::cout << '\n';
    }
}
};
void FD_Standard_Reporting_View::show_view_report_doctor_week(const std::vector<std::map<std::string, std::string>> &data) {
      system("cls");

if (data.empty()){
show_list_empty_message();
} else {
   system("cls");

    

    std::cout << std::left << std::setfill(' ') << std::setw(3) << "ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(25) << "Doctor Name";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(15) << "Room Number";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Date";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Time";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Room ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Patient ID";
    std::cout << '\n';
    for(auto current_element : data){
        std::cout << std::left << std::setfill(' ') << std::setw(3) << current_element["ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(25) << current_element["Doctor Name"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(15) << current_element["Room Number"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Date"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Time"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Room ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Patient ID"];
        std::cout << '\n';
    }
}
};
inline void FD_Standard_Reporting_View::show_view_report_room_week(const std::vector<std::map<std::string, std::string>> &data) {
   system("cls");

if (data.empty()){
show_list_empty_message();
} else {
   system("cls");

    

    std::cout << std::left << std::setfill(' ') << std::setw(3) << "ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(25) << "Doctor Name";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(15) << "Room Number";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Date";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Time";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Room ID";
    std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "Patient ID";
    std::cout << '\n';
    for(auto current_element : data){
        std::cout << std::left << std::setfill(' ') << std::setw(3) << current_element["ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(25) << current_element["Doctor Name"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(15) << current_element["Room Number"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Date"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Time"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Room ID"];
        std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Patient ID"];
        std::cout << '\n';
    }
}
};


inline void FD_Standard_Reporting_View::show_list_empty_message() {
std::cout << "No data stored!" << '\n';
}
>>>>>>> d289d3180ae708c0aab45052855144bb90287495
