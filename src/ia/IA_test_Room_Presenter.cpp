#include "IA_test_Room_Presenter.h"

IA_test_Room_Presenter::IA_test_Room_Presenter(FD_Resource_View_test &view)
    : resource_view_test(view){};
void IA_test_Room_Presenter::present_all()
{
    resource_view_test.show_list_view();
};