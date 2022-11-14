#ifndef IA_MASTER_CONTROLLER
#define IA_MASTER_CONTROLLER
#include "IA_Person_Controller.h"

class IA_Master_Controller {
    public:
        IA_Master_Controller(
            IA_Person_Controller& a_person_controller);
        void control_application_start();
        void control_menu_choice();
    private:
        IA_Person_Controller& person_controller;

        void show_menu_message_prompt();
        void show_menu_message_unexpected_input();
      
};
#endif /* IA_MASTER_CONTROLLER */