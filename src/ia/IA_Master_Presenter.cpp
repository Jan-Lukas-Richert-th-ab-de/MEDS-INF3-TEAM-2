#include "IA_Master_Presenter.h"

IA_Master_Presenter::IA_Master_Presenter(FD_Resource_View_test &view)
    : resource_view_test(view){};
/*void IA_Master_Presenter::present_all()
{
    resource_view.show_list_view();
};*/
void IA_Master_Presenter::present_all_MAIN()
{
    resource_view_test.show_list_view_MAIN();
};
void IA_Master_Presenter::present_all_CORE_RESURCES()
{
    resource_view_test.show_list_view_CORE_RESSURCES();
};