#pragma once
#ifndef IA_TEST_STANDARD_REPORTING_CONTROLLER_H
#define IA_TEST_STANDARD_REPORTING_CONTROLLER_H
#include "IA_Standard_Reporting_Controller.h"

class IA_test_Standard_Reporting_Controller
{
public:
    IA_test_Standard_Reporting_Controller(
        IA_Standard_Reporting_Controller &a_Standard_Reporting_Controller);
    void control_application_start();
    void chooce_Standard_Reporting();

private:
    IA_Standard_Reporting_Controller &Standard_Reporting_Controller;

      void show_menu_message_prompt();
    void show_menu_message_unexpected_input();
};
#endif /* IA_test_Standard_Reporting_Controller */