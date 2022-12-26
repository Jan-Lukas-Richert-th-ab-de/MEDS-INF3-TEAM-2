#include "IA_Summary_Statistics_Presenter.h"

IA_Summary_Statistics_Presenter::IA_Summary_Statistics_Presenter(FD_Resource_View_S& view)
            : resource_view(view) {};
void IA_Summary_Statistics_Presenter::present_all(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view.show_list_view(data);
};
