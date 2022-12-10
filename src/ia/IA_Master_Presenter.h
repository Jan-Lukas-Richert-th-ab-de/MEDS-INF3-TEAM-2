#ifndef IA_MASTER_PRESENTER_TEST_H
#define IA_MASTER_PRESENTER_TEST_H
#include "FD_Resource_View_test.h"
#include <vector>
#include <map>

class IA_Master_Presenter
{
public:
    IA_Master_Presenter(FD_Resource_View_test &view);
    // void present_all();
    void present_all_CORE_RESURCES();
    void present_all_MAIN();

private:
    FD_Resource_View_test &resource_view_test;
};
#endif /* IA_ROOM_PRESENTER_H */