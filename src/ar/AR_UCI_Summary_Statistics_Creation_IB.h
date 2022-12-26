#ifndef AR_UCI_SUMMARY_STATISTICS_CREATION_IB_H
#define AR_UCI_SUMMARY_STATISTICS_CREATION_IB_H
#include <string>

class AR_UCI_Summary_Statistics_Creation_IB {
public:
virtual void list_all() = 0;
virtual void report_doctor_Summary_Statistics(unsigned int id, std::string day, std::string month, std::string year) = 0;
virtual void report_room_occupancy_Summary_Statistics(unsigned int id, std::string day, std::string month, std::string year) = 0;

virtual ~AR_UCI_Summary_Statistics_Creation_IB() = default;
AR_UCI_Summary_Statistics_Creation_IB() = default;
AR_UCI_Summary_Statistics_Creation_IB(const AR_UCI_Summary_Statistics_Creation_IB&) = default;
AR_UCI_Summary_Statistics_Creation_IB& operator=(const AR_UCI_Summary_Statistics_Creation_IB&) = default;
};

#endif