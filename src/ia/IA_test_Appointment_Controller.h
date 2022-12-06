#ifndef IA_TEST_APPOINTMENT_CONTROLLER
#define IA_TEST_APPOINTMENT_CONTROLLER
#include "IA_Appointment_Controller.h"

class IA_test_Appointment_Controller
{
public:
    IA_test_Appointment_Controller(
        IA_Appointment_Controller &a_appointment_Controller);
    void control_application_start();
    void chooce_Appointment();

private:
    IA_Appointment_Controller &appointment_Controller;

    void
    show_menu_message_prompt();
    void show_menu_message_unexpected_input();
};
#endif /* test_Appointment_Controller */