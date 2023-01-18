#include "IA_Summary_Statistics_Presenter.h"
#include "FD_Resource_View.h"
#include "AR_UCI_Summary_Statistics_Creation_OB.h"


void IA_Summary_Statistics_Presenter::present_all(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_S.show_list_view(data);};
void IA_Summary_Statistics_Presenter::present_report_doctor_Summary_Statistics(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_S.show_doctor_summary(data);};
void IA_Summary_Statistics_Presenter::present_report_room_occupancy_Summary_Statistics(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_S.show_room_occupancy_summary(data);
    
};
void IA_Summary_Statistics_Presenter::present_report_doctor_Summary_Statistics_per_week(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_S.show_doctor_summary_per_week(data);};
void IA_Summary_Statistics_Presenter::present_report_room_occupancy_Summary_Statistics_per_week(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_S.show_room_occupancy_summary_per_week(data);
    
};

