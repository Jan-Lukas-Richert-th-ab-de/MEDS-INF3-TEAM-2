#ifndef AR_UCI_SUMMARY_STATISTICS_ADMINISTRATION_H
#define AR_UCI_SUMMARY_STATISTICS_ADMINISTRATION_H
#include "FD_Resource_View.h"
#include "AR_UCI_Summary_Statistics_Administration_IB.h"
#include "AR_UCI_Summary_Statistics_Administration_OB.h"
#include "ER_appointment.h"


class AR_UCI_Summary_Statistics_Administration : public AR_UCI_Summary_Statistics_Administration_IB {
    public:
        AR_UCI_Summary_Statistics_Administration(
            AR_UCI_Summary_Statistics_Administration_OB& presenter
          );
        void list_all();
        void update(unsigned int id, std::string day, std::string month, std::string year, std::string time_start, std::string time);
        
    private:
        AR_UCI_Summary_Statistics_Administration_OB& resource_presenter;
        ;
        std::map<std::string, std::string> get_data_map_for_Summary_Statistics(const ER_Appointment& a_appointment);
        void sort_Summary_Statisticss_by_id (std::vector<ER_Appointment>& Summary_Statistics_list);
};
#endif /* AR_UCI_Summary_Statistics_ADMINISTRATION_H */