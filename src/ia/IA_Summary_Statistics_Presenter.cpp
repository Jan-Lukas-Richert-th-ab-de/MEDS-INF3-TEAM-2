#include "IA_Summary_Statistics_Presenter.h"

void IA_Summary_Statistics_Presenter::present_all(const std::vector<std::map<std::string, std::string>>& data) {
    resource_view_S.show_list_view(data);
    
};