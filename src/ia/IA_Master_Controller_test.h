#ifndef IA_MASTER_CONTROLLER_TEST
#define IA_MASTER_CONTROLLER_TEST
#include "IA_test_Room_Controller.h"
#include "IA_test_Doctor_Controller.h"
#include "IA_test_Patient_Controller.h"
#include "IA_test_Appointment_Controller.h"
#include "IA_test_Room_Presenter.h"
#include "IA_test_summary_statistics_controller.h"

class IA_Master_Controller_test
{
public:
    IA_Master_Controller_test(
        IA_test_Room_Controller &a_test_Room_Controller, IA_test_Doctor_Controller &a_test_Doctor_Controller,
        IA_test_Patient_Controller &a_test_Patient_Controller, IA_test_Appointment_Controller &a_test_Appointment_Controller,
        IA_test_Room_Presenter &a_view
        ,IA_test_Summary_Statistics_Controller &a_test_Summary_Statistics_Controller
        );
    void control_application_start();
    void control_menu_choice();

private:
    IA_test_Room_Controller &test_Room_Controller;
    IA_test_Doctor_Controller &test_Doctor_Controller;
    IA_test_Patient_Controller &test_Patient_Controller;
    IA_test_Appointment_Controller &test_Appointment_Controller;
    IA_test_Room_Presenter &view;
    IA_test_Summary_Statistics_Controller &test_Summary_Statistics_Controller;

    void show_menu_message_prompt();
    void show_menu_message_unexpected_input();
};
#endif /* IA_MASTER_CONTROLLER */