#ifndef AR_UCI_STANDARD_REPORTING_OB_H
#define AR_UCI_STANDARD_REPORTING_OB_H
#include <vector>
#include <map>
#include <string>

class AR_UCI_Standard_Reporting_OB {
public:
 virtual void present_all(const std::vector<std::map<std::string, std::string>> &data) {};

 virtual void present_report_doctor_time_plan(const std::vector<std::map<std::string, std::string>>& data){}; 
 virtual void present_report_room_occupancy_plan(const std::vector<std::map<std::string, std::string>>& data){}; 
   virtual void present_report_doctor_time_plan_week(const std::vector<std::map<std::string, std::string>>& data){}; 
 virtual void present_report_room_occupancy_plan_week(const std::vector<std::map<std::string, std::string>>& data){}; 


  virtual ~AR_UCI_Standard_Reporting_OB() = default;
  AR_UCI_Standard_Reporting_OB() = default;
  AR_UCI_Standard_Reporting_OB(const AR_UCI_Standard_Reporting_OB&) = default;
  AR_UCI_Standard_Reporting_OB& operator=(const AR_UCI_Standard_Reporting_OB&) = default;
};

#endif /* AR_UCI_STANDARD_REPORTING_OB_H */