#include "IA_Options_Presenter.h"

IA_Options_Presenter::IA_Options_Presenter(FD_Resource_View_test &view)
    : resource_view_test(view){};
void IA_Options_Presenter::present_all()
{
    resource_view_test.show_list_view();
};