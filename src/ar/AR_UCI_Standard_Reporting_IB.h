#ifndef AR_UCI_STANDARD_REPORTING_IB_H
#define AR_UCI_STANDARD_REPORTING_IB_H
#include <string>

class AR_UCI_Standard_Reporting_IB {
public:
  virtual void list_all() = 0;

  virtual void report_doctor_timeplan(unsigned int id, const std::string& day, const std::string& month, const std::string& year)= 0; 
  virtual void report_room_occupancy_plan(unsigned int id, const std::string& day, const std::string& month, const std::string& year)= 0; 
  virtual void report_doctor_timeplan_week(unsigned int id, const std::string& day, const std::string& month, const std::string& year)= 0; 
  virtual void report_room_occupancy_plan_week(unsigned int id, const std::string& day, const std::string& month, const std::string& year)= 0; 


  virtual ~AR_UCI_Standard_Reporting_IB() = default;
  AR_UCI_Standard_Reporting_IB() = default;
  AR_UCI_Standard_Reporting_IB(const AR_UCI_Standard_Reporting_IB&) = default;
  AR_UCI_Standard_Reporting_IB& operator=(const AR_UCI_Standard_Reporting_IB&) = default;
};

#endif /* AR_UCI_STANDARD_REPORTING_IB_H */