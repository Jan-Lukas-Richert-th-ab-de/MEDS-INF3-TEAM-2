#ifndef AR_UCI_SUMMARY_STATISTICS_CREATION_OB_H
#define AR_UCI_SUMMARY_STATISTICS_CREATION_OB_H
#include <vector>
#include <string> //string include
class AR_UCI_Summary_Statistics_Creation_OB {
public:
virtual void present_all(const std::vector<std::map<std::string, std::string>> &data) =0;
virtual void present_report_doctor_Summary_Statistics(const std::vector<std::map<std::string, std::string>>& data) =0;
virtual void present_report_room_occupancy_Summary_Statistics(const std::vector<std::map<std::string, std::string>>& data) =0;
virtual void present_report_doctor_Summary_Statistics_per_week(const std::vector<std::map<std::string, std::string>>& data) =0;
virtual void present_report_room_occupancy_Summary_Statistics_per_week(const std::vector<std::map<std::string, std::string>>& data) =0;

virtual ~AR_UCI_Summary_Statistics_Creation_OB() = default;
AR_UCI_Summary_Statistics_Creation_OB() = default;
AR_UCI_Summary_Statistics_Creation_OB(const AR_UCI_Summary_Statistics_Creation_OB&) = default;
AR_UCI_Summary_Statistics_Creation_OB& operator=(const AR_UCI_Summary_Statistics_Creation_OB&) = default;
};
#endif