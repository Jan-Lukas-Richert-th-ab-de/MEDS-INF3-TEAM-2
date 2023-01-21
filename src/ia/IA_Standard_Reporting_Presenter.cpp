<<<<<<< HEAD
#include "IA_Standard_Reporting_Presenter.h"

void IA_Standard_Reporting_Presenter::present_all(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_R.show_list_view(data);};


void IA_Standard_Reporting_Presenter::present_report_doctor_time_plan(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_R.show_view_report_doctor(data);
    
};
void IA_Standard_Reporting_Presenter::present_report_room_occupancy_plan(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_R.show_view_report_room(data);
    
};

void IA_Standard_Reporting_Presenter::present_report_doctor_time_plan_week(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_R.show_view_report_doctor_week(data);
    
};
void IA_Standard_Reporting_Presenter::present_report_room_occupancy_plan_week(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_R.show_view_report_room_week(data);
    
};


=======
#include "IA_Standard_Reporting_Presenter.h"

void IA_Standard_Reporting_Presenter::present_all(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_R.show_list_view(data);};


void IA_Standard_Reporting_Presenter::present_report_doctor_time_plan(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_R.show_view_report_doctor(data);
    
};
void IA_Standard_Reporting_Presenter::present_report_room_occupancy_plan(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_R.show_view_report_room(data);
    
};

void IA_Standard_Reporting_Presenter::present_report_doctor_time_plan_week(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_R.show_view_report_doctor_week(data);
    
};
void IA_Standard_Reporting_Presenter::present_report_room_occupancy_plan_week(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_R.show_view_report_room_week(data);
    
};


>>>>>>> d289d3180ae708c0aab45052855144bb90287495
