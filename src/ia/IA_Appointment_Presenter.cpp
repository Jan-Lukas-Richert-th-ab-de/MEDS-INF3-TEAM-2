#include "IA_Appointment_Presenter.h"

IA_Appointment_Presenter::IA_Appointment_Presenter(FD_Resource_View& view)
            : resource_view(view) {};
void IA_Appointment_Presenter::present_all(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view.show_list_view(data);
};
