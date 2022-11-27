#ifndef IA_TEST_PATIENT_CONTROLLER
#define IA_TEST_PATIENT_CONTROLLER
#include "IA_Patient_Controller.h"

class IA_test_Patient_Controller
{
public:
    IA_test_Patient_Controller(
        IA_Patient_Controller &a_patient_Controller);
    void control_application_start();
    void choose_Patient();

private:
    IA_Patient_Controller &patient_Controller;

    void show_menu_message_prompt();
    void show_menu_message_unexpected_input();
};
#endif /* TEST_CONTROlLER */