#include "AR_UCI_Summary_Statistics_Creation.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "FD_Resource_View.h"
#include "AR_DAI_Doctor_Repository.h"
#include "AR_DAI_Appointment_Repository.h"
#include "AR_DAI_Room_Repository.h"
#include "ER_doctor.h"
#include "ER_Room.h"
#include "ER_appointment.h"
#include "AR_UCI_Summary_Statistics_Creation_OB.h"
#include "AR_UCI_Summary_Statistics_Creation_IB.h"
#include <ctime>
#include <sstream>
#include <iomanip>


AR_UCI_Summary_Statistics_Creation::AR_UCI_Summary_Statistics_Creation(
AR_UCI_Summary_Statistics_Creation_OB &presenter,
AR_DAI_Appointment_Repository &appointment_repository,
AR_DAI_Doctor_Repository &doctor_repository,
AR_DAI_Room_Repository &room_repository)
: presenter(presenter),
doctor_repository(doctor_repository),
room_repository(room_repository),
appointment_repository(appointment_repository) {}

void AR_UCI_Summary_Statistics_Creation::list_all() {
std::vector<ER_Doctor> doctors = doctor_repository.find_all();
std::vector<ER_Room> rooms = room_repository.find_all();
std::vector<ER_Appointment> appointments = appointment_repository.find_all();

std::vector<std::map<std::string, std::string>> data;
for (const auto& doctor : doctors) {
std::map<std::string, std::string> row;
row["ID"] = std::to_string(doctor.get_id());
row["Name"] = doctor.get_full_name();
row["Specialization"] = doctor.get_doctors_specialties();
data.push_back(row);
}
for (const auto& room : rooms) {
std::map<std::string, std::string> row;
row["ID"] = std::to_string(room.get_room_id());
row["Name"] = room.get_full_name();
row["Description"] = room.get_room_description();
data.push_back(row);
}
for (const auto& appointment : appointments) {
std::map<std::string, std::string> row;
row["ID"] = std::to_string(appointment.get_id());
row["Date"] = appointment.get_date();
row["Time"] = appointment.get_time();
//row["Doctor"] = appointment.get_doctor_name();
//row["Room"] = appointment.get_room_name();
data.push_back(row);
}

presenter.present_all(data);
}

void AR_UCI_Summary_Statistics_Creation::report_doctor_Summary_Statistics(unsigned int id, const std::string &day, const std::string &month, const std::string &year) {
    std::vector<ER_Appointment> appointments = appointment_repository.find_all();
    std::vector<ER_Doctor> doctors = doctor_repository.find_all();

    double total_room_duration = 0;
    int total_room_appointments = 0;
    double total_doctor_duration = 0;
    int total_doctor_appointments = 0;

    for (const ER_Appointment &appointment : appointments) {
        if (appointment.get_day() == day && appointment.get_month() == month && appointment.get_year() == year) {
            if (appointment.get_doctor() == id) {
                total_doctor_duration += stoi(appointment.get_time());
                total_doctor_appointments++;
            }
           
        }
    }

    double avg_room_duration = total_room_duration / total_room_appointments;
    double avg_doctor_duration = total_doctor_duration / total_doctor_appointments;

    std::vector<std::map<std::string, std::string>> data;
    std::map<std::string, std::string> row;
    row["ID"] = std::to_string(doctors[id - 1].get_id());
    row["Name"] = doctors[id - 1].get_full_name();
    row["Specialization"] = doctors[id - 1].get_doctors_specialties();
    row["Avg Doctor Duration"] = std::to_string(avg_doctor_duration);
    data.push_back(row);
    presenter.present_all(data);
   
presenter.present_report_doctor_Summary_Statistics(data);
}
void AR_UCI_Summary_Statistics_Creation:: report_room_occupancy_Summary_Statistics(unsigned int id, const std::string& day, const std::string& month, const std::string& year) {
    std::vector<ER_Appointment> appointments = appointment_repository.find_all();
    std::vector<ER_Room> rooms = room_repository.find_all();

    double total_room_duration = 0;
    int total_room_appointments = 0;

    for (const ER_Appointment &appointment : appointments) {
        if (appointment.get_day() == day && appointment.get_month() == month && appointment.get_year() == year) {
       
            if (appointment.get_room() == id) {
                total_room_duration += stoi(appointment.get_time());
                total_room_appointments++;
            }
        }
    }

    double avg_room_duration = total_room_duration / total_room_appointments;

    std::vector<std::map<std::string, std::string>> data;
    std::map<std::string, std::string> row;
    row["ID"] = std::to_string(rooms[id - 1].get_room_id());
    row["Name"] = rooms[id - 1].get_full_name();
    row["Number"] = rooms[id - 1].get_room_number();
    row["Avg Room Duration"] = std::to_string(avg_room_duration);
    data.push_back(row);
   
presenter.present_report_room_occupancy_Summary_Statistics(data);
}
void AR_UCI_Summary_Statistics_Creation::report_doctor_Summary_Statistics_pre_week(unsigned int id, const std::string &day, const std::string &month, const std::string &year) {
    std::vector<ER_Appointment> appointments = appointment_repository.find_all();
    std::vector<ER_Doctor> doctors = doctor_repository.find_all();

    double total_doctor_duration = 0;
    int total_doctor_appointments = 0;

    for (const ER_Appointment &appointment : appointments) {
if (appointment.get_month() == month && appointment.get_year() == year  && stoi( appointment.get_day()) <= (stoi(day) + 7)) {         
       if (appointment.get_doctor() == id) {
                total_doctor_duration += stoi(appointment.get_time());
                total_doctor_appointments++;
            }
           
        }
    }

    double avg_doctor_duration = total_doctor_duration / total_doctor_appointments;

    std::vector<std::map<std::string, std::string>> data;
    std::map<std::string, std::string> row;
    row["ID"] = std::to_string(doctors[id - 1].get_id());
    row["Name"] = doctors[id - 1].get_full_name();
    row["Specialization"] = doctors[id - 1].get_doctors_specialties();
    row["Avg Doctor Duration"] = std::to_string(avg_doctor_duration);
    data.push_back(row);
   
presenter.present_report_doctor_Summary_Statistics_per_week(data);
}
void AR_UCI_Summary_Statistics_Creation:: report_room_occupancy_Summary_Statistics_pre_week(unsigned int id, const std::string& day, const std::string& month, const std::string& year) {
    std::vector<ER_Appointment> appointments = appointment_repository.find_all();
    std::vector<ER_Room> rooms = room_repository.find_all();

    double total_room_duration = 0;
    int total_room_appointments = 0;

    for (const ER_Appointment &appointment : appointments) {
if (appointment.get_month() == month && appointment.get_year() == year  && stoi( appointment.get_day()) <= (stoi(day) + 7)) {         
       
            if (appointment.get_room() == id) {
                total_room_duration += stoi(appointment.get_time());
                total_room_appointments++;
            }
        }
    }

    double avg_room_duration = total_room_duration / total_room_appointments;

    std::vector<std::map<std::string, std::string>> data;
    std::map<std::string, std::string> row;
    row["ID"] = std::to_string(rooms[id - 1].get_room_id());
    row["Name"] = rooms[id - 1].get_full_name();
    row["Number"] = rooms[id - 1].get_room_number();
    row["Avg Room Duration"] = std::to_string(avg_room_duration);
    data.push_back(row);
   
presenter.present_report_room_occupancy_Summary_Statistics_per_week(data);
}


