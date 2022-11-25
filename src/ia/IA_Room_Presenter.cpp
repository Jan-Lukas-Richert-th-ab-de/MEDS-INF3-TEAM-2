#include "IA_Room_Presenter.h"

IA_Room_Presenter::IA_Room_Presenter(FD_Resource_View &view)
    : resource_view(view){};
void IA_Room_Presenter::present_all(const std::vector<std::map<std::string, std::string>> &data)
{
    resource_view.show_list_view(data);
};
