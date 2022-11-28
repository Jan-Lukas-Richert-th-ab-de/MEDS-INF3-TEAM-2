#ifndef IA_MAIN_PRESENTER_TEST_H
#define IA_MAIN_PRESENTER_TEST_H
#include "FD_Resource_View_test.h"
#include <vector>
#include <map>

class IA_test_Room_Presenter
{
public:
    IA_test_Room_Presenter(FD_Resource_View_test &view);
    void present_all();

private:
    FD_Resource_View_test &resource_view_test;
};
#endif /* IA_ROOM_PRESENTER_H */