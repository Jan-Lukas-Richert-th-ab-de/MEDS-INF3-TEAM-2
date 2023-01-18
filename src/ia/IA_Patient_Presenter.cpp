#include "IA_Patient_Presenter.h"

IA_Patient_Presenter::IA_Patient_Presenter(FD_Resource_View &view)
    : resource_view(view){};
void IA_Patient_Presenter::present_all(const std::vector<std::map<std::string, std::string>> &data)
{
    resource_view.show_list_view(data);
};
void IA_Patient_Presenter::present_all_data(const std::vector<std::map<std::string, std::string>> &data)
{
    resource_view.show_list_view_data(data);
};
