#include "IA_Standard_Reporting_Presenter.h"

IA_Standard_Reporting_Presenter::IA_Standard_Reporting_Presenter(FD_Resource_View& view)
            : resource_view(view) {};
void IA_Standard_Reporting_Presenter::present_all(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view.show_list_view(data);
};
