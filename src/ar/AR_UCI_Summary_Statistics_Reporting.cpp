#include "AR_UCI_Summary_Statistics_Reporting.h"
#include <vector>
#include <map>
#include <cmath> 

#include <string>
#include <algorithm>
#include "ER_doctor.h"
#include "ER_Room.h"
#include "ER_appointment.h"
#include "AR_DAI_Appointment_Repository.h"
#include "AR_DAI_Doctor_Repository.h"
#include "AR_DAI_Room_Repository.h"


AR_UCI_Summary_Statistics_Reporting::AR_UCI_Summary_Statistics_Reporting(
    AR_UCI_Summary_Statistics_Reporting_OB& doctor_presenter
    , AR_UCI_Summary_Statistics_Reporting_OB& room_presenter
    
          , AR_DAI_Doctor_Repository& doctor_repository
          , AR_DAI_Room_Repository& room_repository)
            : doctor_resource_presenter(doctor_presenter) 
            , room_resource_presenter(room_presenter) 
             
            , doctor_resource_repository (doctor_repository)
            , room_resource_repository (room_repository)
            {};

           


void AR_UCI_Summary_Statistics_Reporting::report_doctor_Summary_Statistics(){
  std::vector<ER_Doctor> resources_list = doctor_resource_repository.find_all();
  size_t doctor_Summary_Statistics = resources_list.size();
  doctor_resource_presenter.present_report_doctor_Summary_Statistics(doctor_Summary_Statistics);

};            

void AR_UCI_Summary_Statistics_Reporting::report_room_occupancy_Summary_Statistics(){
  std::vector<ER_Room> resources_list = room_resource_repository.find_all();
  size_t room_occupancy_Summary_Statistics = resources_list.size();
  room_resource_presenter.present_report_room_occupancy_Summary_Statistics(room_occupancy_Summary_Statistics);
  
};    


 std::map<std::string, double> AR_Summary_Statistics::get_average_room_occupancy(const std::vector<ER_Appointment>& appointments,const std::vector<ER_Room>& rooms, const std::string& week) 
{
  std::map<std::string, double> result;

 
  for (const ER_Room& room : rooms)
  {
     double total_duration = 0.0;
     int appointment_count = 0;

   
     for (const ER_Appointment& appointment : appointments)
     {
        if (appointment.get_id() == room.get_room_id()/* && appointment.get_week() == week*/)
        {
           //total_duration += appointment.get_time();
           appointment_count++;
        }
     }

       if (appointment_count > 0)
       {
        result[room.get_full_name()] = total_duration / appointment_count;
       }
  }
    return result;
}

std::map<std::string, double> get_average_doctor_utilization(const std::vector<ER_Appointment>& appointments, const std::vector<ER_Doctor>& doctors, const std::string& week) 
{
std::map<std::string, double> result;


  
  for (const ER_Doctor& doctor : doctors)
  {
      double total_duration = 0.0;
     int appointment_count = 0;

     
    for (const ER_Appointment& appointment : appointments)
     {
        if (appointment.get_id() == doctor.get_id() /*&& appointment.get_week() == week*/)
        {
          // total_duration += appointment.get_time();
           appointment_count++;
        }
     }

       if (appointment_count > 0)
       {
        result[doctor.get_full_name()] = total_duration / appointment_count;
       }
  }

  
  if (result.empty())
  {
    return std::map<std::string, double>();
  }

  return result;
}

