#include "IA_Person_Presenter.h"

IA_Person_Presenter::IA_Person_Presenter(FD_Resource_View& view)
            : resource_view(view) {};
void IA_Person_Presenter::present_all(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view.show_list_view(data);
};
