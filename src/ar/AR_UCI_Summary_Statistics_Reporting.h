#ifndef AR_UCI_SUMMARY_STATISTICS_REPORTING_H
#define AR_UCI_SUMMARY_STATISTICS_REPORTING_H
#include "FD_Resource_View.h"
#include "AR_UCI_Summary_Statistics_Reporting_IB.h"
#include "AR_UCI_Summary_Statistics_Reporting_OB.h"
#include "AR_DAI_Doctor_Repository.h"
#include "AR_DAI_Appointment_Repository.h"
#include "AR_DAI_Room_Repository.h"
#include <vector>
#include <map>
#include <string>
#include "ER_doctor.h"
#include "ER_Room.h"
#include "ER_appointment.h"
#include <memory>



class AR_UCI_Summary_Statistics_Reporting : public AR_UCI_Summary_Statistics_Reporting_IB {
    public:
        AR_UCI_Summary_Statistics_Reporting(
            AR_UCI_Summary_Statistics_Reporting_OB& doctor_presenter
          , AR_UCI_Summary_Statistics_Reporting_OB& room_presenter
          , AR_DAI_Doctor_Repository& doctor_repository
          , AR_DAI_Room_Repository& room_repository);
          

        void list_all();
         void control_report(unsigned int id, std::string first_name, std::string last_name);

        void report_doctor_Summary_Statistics(); 
        void report_room_occupancy_Summary_Statistics(); 
        
        
        
    private:
        AR_UCI_Summary_Statistics_Reporting_OB& doctor_resource_presenter;
        AR_UCI_Summary_Statistics_Reporting_OB& room_resource_presenter;
        



        AR_DAI_Doctor_Repository& doctor_resource_repository;
        AR_DAI_Room_Repository& room_resource_repository;
        

};
class AR_Summary_Statistics
{
public:

  virtual std::map<std::string, double> get_average_room_occupancy(const std::vector<ER_Appointment>& appointments, const std::vector<ER_Room>& rooms, const std::string& week) = 0;

  virtual std::map<std::string, double> get_average_doctor_utilization(const std::vector<ER_Appointment>& appointments, const std::vector<ER_Doctor>& doctors, const std::string& week) = 0;

  virtual ~AR_Summary_Statistics() = default;
  AR_Summary_Statistics() = default;
  AR_Summary_Statistics(const AR_Summary_Statistics &) = default;
  AR_Summary_Statistics &operator=(const AR_Summary_Statistics &) = default;
   static std::unique_ptr<AR_Summary_Statistics> control_report(unsigned int id, std::string first_name, std::string last_name);
};

#endif /* AR_UCI_Summary_Statistics_Reporting_H */
