#ifndef IA_SUMMARY_STATISTICS_PRESENTER_H
#define IA_SUMMARY_STATISTICS_PRESENTER_H
#include "FD_Resource_View.h"
#include "AR_UCI_Summary_Statistics_Creation_OB.h"
#include <vector>
#include <map>


class IA_Summary_Statistics_Presenter : public AR_UCI_Summary_Statistics_Creation_OB {
   
    private:
        FD_Resource_View_S &resource_view_S;
        void present_all(const std::vector<std::map<std::string, std::string>>& data)override;
        void present_report_doctor_Summary_Statistics(const std::vector<std::map<std::string, std::string>>& data) override;;
        void present_report_room_occupancy_Summary_Statistics(const std::vector<std::map<std::string, std::string>>& data) override;
        void present_report_doctor_Summary_Statistics_per_week(const std::vector<std::map<std::string, std::string>>& data) override;;
        void present_report_room_occupancy_Summary_Statistics_per_week(const std::vector<std::map<std::string, std::string>>& data) override;
  
    public:
        IA_Summary_Statistics_Presenter(FD_Resource_View_S& view_S) : resource_view_S(view_S) {};
};
#endif /* IA_Summary_Statistics_PRESENTER_H */


