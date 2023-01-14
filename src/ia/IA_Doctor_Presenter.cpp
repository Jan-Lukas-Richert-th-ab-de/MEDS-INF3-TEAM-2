#include "IA_Doctor_Presenter.h"

IA_Doctor_Presenter::IA_Doctor_Presenter(FD_Resource_View &view)
    : resource_view(view){};
void IA_Doctor_Presenter::present_all(const std::vector<std::map<std::string, std::string>> &data)
{
    resource_view.show_list_view(data);
};
void IA_Doctor_Presenter::present_all_data(const std::vector<std::map<std::string, std::string>> &data)
{
    resource_view.show_list_view_data(data);
};
