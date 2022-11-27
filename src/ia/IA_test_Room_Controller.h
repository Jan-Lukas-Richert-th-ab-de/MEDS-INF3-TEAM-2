#ifndef IA_TEST_ROOM_CONTROLLER
#define IA_TEST_ROOM_CONTROLLER
#include "IA_Room_Controller.h"

class IA_test_Room_Controller
{
public:
    IA_test_Room_Controller(
        IA_Room_Controller &a_room_Controller);
    void control_application_start();
    void chooce_Room();

private:
    IA_Room_Controller &room_Controller;

    void
    show_menu_message_prompt();
    void show_menu_message_unexpected_input();
};
#endif /* test_Room_Controller */