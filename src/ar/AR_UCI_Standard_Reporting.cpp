#include "AR_UCI_Standard_Reporting.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "ER_doctor.h"
#include "ER_Room.h"
#include "ER_appointment.h"
#include "AR_DAI_Appointment_Repository.h"
#include "AR_DAI_Doctor_Repository.h"
#include "AR_DAI_Room_Repository.h"


AR_UCI_Standard_Reporting::AR_UCI_Standard_Reporting(
    AR_UCI_Standard_Reporting_OB& doctor_presenter
    , AR_UCI_Standard_Reporting_OB& room_presenter
    , AR_UCI_Standard_Reporting_OB& appointment_presenter
          , AR_DAI_Doctor_Repository& doctor_repository
          , AR_DAI_Room_Repository& room_repository
          , AR_DAI_Appointment_Repository& appointment_repository)
            : doctor_resource_presenter(doctor_presenter) 
            , room_resource_presenter(room_presenter) 
            , appointment_resource_presenter(appointment_presenter) 
            , doctor_resource_repository (doctor_repository)
            , room_resource_repository (room_repository)
            , appointment_resource_repository (appointment_repository) {};


void AR_UCI_Standard_Reporting::report_doctor_timeplan(){
  std::vector<ER_Doctor> resources_list = doctor_resource_repository.find_all();
  size_t doctor_timeplan = resources_list.size();
  doctor_resource_presenter.present_report_doctor_timeplan(doctor_timeplan);

};            

void AR_UCI_Standard_Reporting::report_room_occupancy_plan(){
  std::vector<ER_Room> resources_list = room_resource_repository.find_all();
  size_t room_occupancy_plan = resources_list.size();
  room_resource_presenter.present_report_room_occupancy_plan(room_occupancy_plan);
  
};    

void AR_UCI_Standard_Reporting::report_appointment(){
  std::vector<ER_Appointment> resources_list = appointment_resource_repository.find_all();
  size_t appointment = resources_list.size();
  appointment_resource_presenter.present_report_appointment (appointment);
};    
