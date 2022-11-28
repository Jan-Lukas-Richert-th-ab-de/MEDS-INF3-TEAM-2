#ifndef IA_TEST_DOCTOR_CONTROLLER
#define IA_TEST_DOCTOR_CONTROLLER
#include "IA_Doctor_Controller.h"

class IA_test_Doctor_Controller
{
public:
    IA_test_Doctor_Controller(
        IA_Doctor_Controller &a_doctor_Controller);
    void control_application_start();
    void choose_Doctor();

private:
    IA_Doctor_Controller &doctor_Controller;

    void show_menu_message_prompt();
    void show_menu_message_unexpected_input();
};
#endif /* TEST_CONTROlLER */