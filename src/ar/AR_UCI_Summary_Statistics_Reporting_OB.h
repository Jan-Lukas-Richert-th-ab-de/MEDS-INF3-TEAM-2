#ifndef AR_UCI_SUMMARY_STATISTICS_REPORTING_OB_H
#define AR_UCI_SUMMARY_STATISTICS_REPORTING_OB_H
#include <vector>
#include <string> //string include

class AR_UCI_Summary_Statistics_Reporting_OB {
   public:
     virtual void present_all(const std::vector<std::map<std::string, std::string>>& data) = 0; 

      virtual void present_report_doctor_Summary_Statistics(size_t doctor_timeplan) = 0; 
      virtual void present_report_room_occupancy_Summary_Statistics(size_t room_occupancy_plan) = 0; 
      
      virtual ~AR_UCI_Summary_Statistics_Reporting_OB() = default;
      AR_UCI_Summary_Statistics_Reporting_OB() = default;
      AR_UCI_Summary_Statistics_Reporting_OB(const AR_UCI_Summary_Statistics_Reporting_OB&) = default;
      AR_UCI_Summary_Statistics_Reporting_OB& operator=(const AR_UCI_Summary_Statistics_Reporting_OB&) = default;
};

#endif 