#ifndef IA_MASTER_CONTROLLER
#define IA_MASTER_CONTROLLER
#include "IA_Patient_Controller.h"

class IA_Master_Controller
{
public:
    IA_Master_Controller(
        IA_Patient_Controller &a_patient_controller);
    void control_application_start();
    void control_menu_choice();

private:
    IA_Patient_Controller &patient_controller;

    void show_menu_message_prompt();
    void show_menu_message_unexpected_input();
};
#endif /* IA_MASTER_CONTROLLER */