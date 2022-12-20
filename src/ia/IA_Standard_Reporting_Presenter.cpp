#include "IA_Standard_Reporting_Presenter.h"


IA_Standard_Reporting_Presenter::IA_Standard_Reporting_Presenter(FD_Resource_View& view)
            : resource_view(view) {};
void IA_Standard_Reporting_Presenter::present_all(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view.show_list_view(data);
};

void IA_Standard_Reporting_Presenter::present_report_room(size_t room) {
   resource_view.show_view_report_room(room);

};

void IA_Standard_Reporting_Presenter::present_report_doctor(size_t doctor) {
   resource_view.show_view_report_doctor(doctor);

};

void IA_Standard_Reporting_Presenter::present_report_appointment(size_t appointment) {
   resource_view.show_view_report_appointment(appointment);

};