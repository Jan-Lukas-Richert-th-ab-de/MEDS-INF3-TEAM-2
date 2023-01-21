#include "AR_UCI_Standard_Reporting.h"
#include "ER_appointment.h"
#include "ER_doctor.h"
#include "ER_Room.h"
#include "AR_DAI_Appointment_Repository.h"
#include "AR_DAI_Doctor_Repository.h"
#include "AR_DAI_Room_Repository.h"
#include "AR_UCI_Standard_Reporting.h"
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
AR_UCI_Standard_Reporting::AR_UCI_Standard_Reporting(AR_UCI_Standard_Reporting_OB& presenter,
AR_DAI_Appointment_Repository& appointment_repository,
AR_DAI_Doctor_Repository& doctor_repository,
AR_DAI_Room_Repository& room_repository)
    : presenter(presenter),
    doctor_repository(doctor_repository),
    room_repository(room_repository),
    appointment_repository(appointment_repository) {}

void AR_UCI_Standard_Reporting::list_all() {
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

void AR_UCI_Standard_Reporting::report_doctor_timeplan(unsigned int doctor_id, const std::string& day, const std::string& month, const std::string& year) {
    // Find all appointments that match the given date
    std::vector<ER_Appointment> appointments = appointment_repository.find_all();
    std::vector<ER_Appointment> filtered_appointments;
    std::vector<ER_Room> rooms = room_repository.find_all();
    for (const ER_Appointment &appointment : appointments) {
        if (appointment.get_day() == day && appointment.get_month() == month && appointment.get_year() == year ) {
            filtered_appointments.push_back(appointment);
        }
    }

    // Find the doctor object by id
   ER_Doctor doctor = doctor_repository.find(doctor_id);




    // Filter appointments by room id
    std::vector<ER_Appointment> doctor_appointments;
    for (const ER_Appointment &appointment : filtered_appointments) {
        if (appointment.get_doctor() == doctor_id) {
            doctor_appointments.push_back(appointment);
        }
    }

    // Prepare the data for presentation
    std::vector<std::map<std::string, std::string>> data;
    for (const auto &appointment : doctor_appointments) {
        std::map<std::string, std::string> row;
        row["ID"] = std::to_string(appointment.get_id());
        row["Doctor Name"] = doctor_repository.find(appointment.get_doctor()).get_full_name();
                        row["Room Number"] = room_repository.find(appointment.get_room()).get_room_number();

        row["Date"] = appointment.get_date();
        row["Time"] = appointment.get_time();
        row["Room ID"] = std::to_string(appointment.get_room());
        row["Patient ID"] = std::to_string(appointment.get_patient());
        data.push_back(row);
    }


          
presenter.present_report_doctor_time_plan(data);
}
        
void AR_UCI_Standard_Reporting::report_room_occupancy_plan(unsigned int room_id, const std::string& day, const std::string& month, const std::string& year) {
    // Find all appointments that match the given date
    std::vector<ER_Appointment> appointments = appointment_repository.find_all();
    std::vector<ER_Appointment> filtered_appointments;
    for (const ER_Appointment &appointment : appointments) {
        if (appointment.get_day() == day && appointment.get_month() == month && appointment.get_year() == year) {
            filtered_appointments.push_back(appointment);
        }
    }

    // Find the room object by id
    ER_Room room = room_repository.find(room_id);

    // Filter appointments by room id
    std::vector<ER_Appointment> room_appointments;
    for (const ER_Appointment &appointment : filtered_appointments) {
        if (appointment.get_room() == room_id) {
            room_appointments.push_back(appointment);
        }
    }

    // Prepare the data for presentation
    std::vector<std::map<std::string, std::string>> data;
    for (const auto &appointment : room_appointments) {
        std::map<std::string, std::string> row;
        row["ID"] = std::to_string(appointment.get_id());
        row["Room Number"] = room.get_room_number();
        row["Doctor Name"] = doctor_repository.find(appointment.get_doctor()).get_full_name();
        row["Date"] = appointment.get_date();
        row["Time"] = appointment.get_time();
        row["Room ID"] = std::to_string(appointment.get_room());
        row["Patient ID"] = std::to_string(appointment.get_patient());
        data.push_back(row);
    }
    presenter.present_report_room_occupancy_plan(data);
}

        
void AR_UCI_Standard_Reporting::report_doctor_timeplan_week(unsigned int doctor_id, const std::string& day, const std::string& month, const std::string& year) {
    // Find all appointments that match the given date
    std::vector<ER_Appointment> appointments = appointment_repository.find_all();
    std::vector<ER_Appointment> filtered_appointments;
    std::vector<ER_Room> rooms = room_repository.find_all();
    for (const ER_Appointment &appointment : appointments) {
        if (stoi(appointment.get_day()) <= (stoi(day) + 6) && appointment.get_month() == month && appointment.get_year() == year ) {
            filtered_appointments.push_back(appointment);
        }
    }

    // Find the doctor object by id
   ER_Doctor doctor = doctor_repository.find(doctor_id);




    // Filter appointments by room id
    std::vector<ER_Appointment> doctor_appointments;
    for (const ER_Appointment &appointment : filtered_appointments) {
        if (appointment.get_doctor() == doctor_id) {
            doctor_appointments.push_back(appointment);
        }
    }

    // Prepare the data for presentation
    std::vector<std::map<std::string, std::string>> data;
    for (const auto &appointment : doctor_appointments) {
        std::map<std::string, std::string> row;
        row["ID"] = std::to_string(appointment.get_id());
        row["Doctor Name"] = doctor_repository.find(appointment.get_doctor()).get_full_name();
                row["Room Number"] = room_repository.find(appointment.get_room()).get_room_number();

        row["Date"] = appointment.get_date();
        row["Time"] = appointment.get_time();
        row["Room ID"] = std::to_string(appointment.get_room());
        row["Patient ID"] = std::to_string(appointment.get_patient());
        data.push_back(row);
    }


          
presenter.present_report_doctor_time_plan_week(data);
}
void AR_UCI_Standard_Reporting:: report_room_occupancy_plan_week(unsigned int room_id, const std::string& day, const std::string& month, const std::string& year) {
    // Find all appointments that match the given date
    std::vector<ER_Appointment> appointments = appointment_repository.find_all();
    std::vector<ER_Appointment> filtered_appointments;
    for (const ER_Appointment &appointment : appointments) {
      
      
       
       
        if (stoi(appointment.get_day()) <= (stoi(day) + 6) && appointment.get_month() == month && appointment.get_year() == year ) {
            
                   
            filtered_appointments.push_back(appointment);
        }
    }

    // Find the room object by id
    ER_Room room = room_repository.find(room_id);

    // Filter appointments by room id
    std::vector<ER_Appointment> room_appointments;
    for (const ER_Appointment &appointment : filtered_appointments) {
        if (appointment.get_room() == room_id) {
            room_appointments.push_back(appointment);
        }
    }

    // Prepare the data for presentation
    std::vector<std::map<std::string, std::string>> data;
    for (const auto &appointment : room_appointments) {
        std::map<std::string, std::string> row;
        row["ID"] = std::to_string(appointment.get_id());
        row["Room Number"] = room.get_room_number();
        row["Doctor Name"] = doctor_repository.find(appointment.get_doctor()).get_full_name();
        row["Date"] = appointment.get_date();
        row["Time"] = appointment.get_time();
        row["Room ID"] = std::to_string(appointment.get_room());
        row["Patient ID"] = std::to_string(appointment.get_patient());
        data.push_back(row);
    }
    presenter.present_report_room_occupancy_plan_week(data);
}