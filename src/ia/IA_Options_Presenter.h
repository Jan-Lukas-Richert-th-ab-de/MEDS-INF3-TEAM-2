#ifndef IA_Options_PRESENTER_H
#define IA_Options_PRESENTER_H
#include "FD_Resource_View_test.h"
#include <vector>
#include <map>

class IA_Options_Presenter
{
public:
    IA_Options_Presenter(FD_Resource_View_test &view);
    void present_all();

private:
    FD_Resource_View_test &resource_view_test;
};
#endif /* IA_Options_PRESENTER_H */