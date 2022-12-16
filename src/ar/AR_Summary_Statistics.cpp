#include "AR_Summary_Statistics.h"
#include "AR_Summary_Statistics.h"
#include <map>
#include <string>
#include <cmath> 
#include <memory>


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

std::unique_ptr<AR_Summary_Statistics> AR_Summary_Statistics::create()
{
    return std::unique_ptr<AR_Summary_Statistics>();
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


