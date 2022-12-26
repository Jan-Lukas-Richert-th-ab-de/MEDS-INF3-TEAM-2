#include "ER_Appointment.h"
#include "ER_Doctor.h"
#include "ER_Room.h"
#include "AR_DAI_Appointment_Repository.h"
#include "AR_DAI_Doctor_Repository.h"
#include "AR_DAI_Room_Repository.h"
#include "AR_UCI_Summary_Statistics_Creation.h"
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>

AR_UCI_Summary_Statistics_Creation::AR_UCI_Summary_Statistics_Creation(
AR_UCI_Summary_Statistics_Creation_OB& presenter,
AR_DAI_Appointment_Repository& appointment_repository,
AR_DAI_Doctor_Repository& doctor_repository,
AR_DAI_Room_Repository& room_repository)
: resource_presenter(presenter),
doctor_resource_repository(doctor_repository),
room_resource_repository(room_repository),
appointment_resource_repository(appointment_repository) {}

void AR_UCI_Summary_Statistics_Creation::list_all() {
std::vector<ER_Doctor> doctors = doctor_resource_repository.find_all();
std::vector<ER_Room> rooms = room_resource_repository.find_all();
std::vector<ER_Appointment> appointments = appointment_resource_repository.find_all();

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

resource_presenter.present_all(data);
}

void AR_UCI_Summary_Statistics_Creation::report_room_occupancy_Summary_Statistics(unsigned int id, std::string day, std::string month, std::string year) {
std::vector<ER_Appointment> appointments = appointment_resource_repository.find_all();
std::vector<ER_Room> rooms = room_resource_repository.find_all();
std::string week = ""; // Replace with code to determine week based on day, month, and year
std::map<std::string, double> room_occupancy = get_average_room_occupancy(appointments, rooms, week);

std::vector<std::map<std::string, std::string>> data;
for (const auto& [room_name, occupancy] : room_occupancy) {
std::map<std::string, std::string> row;
row["Name"] = room_name;
row["Occupancy"] = std::to_string(occupancy);
data.push_back(row);
}

resource_presenter.present_report_room_occupancy_Summary_Statistics(data);
}

void AR_UCI_Summary_Statistics_Creation::report_doctor_Summary_Statistics(unsigned int id, std::string day, std::string month, std::string year) {
std::vector<ER_Appointment> appointments = appointment_resource_repository.find_all();
std::vector<ER_Doctor> doctors = doctor_resource_repository.find_all();
std::string week = ""; // Replace with code to determine week based on day, month, and year
std::map<std::string, double> doctor_statistics = get_doctor_statistics(appointments, doctors, week);

std::vector<std::map<std::string, std::string>> data;
for (const auto& [doctor_name, statistics] : doctor_statistics) {
std::map<std::string, std::string> row;
row["Name"] = doctor_name;
row["Statistics"] = std::to_string(statistics);
data.push_back(row);
}

resource_presenter.present_report_doctor_Summary_Statistics(data);
}

std::map<std::string, double> AR_UCI_Summary_Statistics_Creation::get_average_room_occupancy(
const std::vector<ER_Appointment>& appointments,
const std::vector<ER_Room>& rooms,
const std::string& week) {
std::map<std::string, double> room_occupancy;
for (const auto& room : rooms) {
double total_duration = 0;
int appointment_count = 0;
for (const auto& appointment : appointments) {
/*if (appointment.get_room_name() == room.get_full_name() && appointment.get_week() == week) {
total_duration += appointment.get_duration();
appointment_count++;
}*/
}
double average_duration = total_duration / appointment_count;
room_occupancy[room.get_full_name()] = average_duration;
}
return room_occupancy;
}

std::map<std::string, double> AR_UCI_Summary_Statistics_Creation::get_doctor_statistics(
const std::vector<ER_Appointment>& appointments,
const std::vector<ER_Doctor>& doctors,
const std::string& week) {
std::map<std::string, double> doctor_statistics;
for (const auto& doctor : doctors) {
double total_duration = 0;
int appointment_count = 0;
for (const auto& appointment : appointments) {
/*if (appointment.get_doctor_name() == doctor.get_full_name() && appointment.get_week() == week) {
total_duration += appointment.get_duration();
appointment_count++;
}*/
}
double average_duration = total_duration / appointment_count;
doctor_statistics[doctor.get_full_name()] = average_duration;
}
return doctor_statistics;
}