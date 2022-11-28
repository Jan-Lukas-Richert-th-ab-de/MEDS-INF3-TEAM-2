#ifndef IA_MASTER_CONTROLLER
#define IA_MASTER_CONTROLLER
#include "IA_Room_Controller.h"

class IA_Master_Controller
{
public:
    IA_Master_Controller(
        IA_Room_Controller &a_room_controller);
    void control_application_start();
    void control_menu_choice();

private:
    IA_Room_Controller &room_controller;

    void show_menu_message_prompt();
    void show_menu_message_unexpected_input();
};
#endif /* IA_MASTER_CONTROLLER */