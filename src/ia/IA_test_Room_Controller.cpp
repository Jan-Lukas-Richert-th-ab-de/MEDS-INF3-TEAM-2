#include "IA_test_Room_Controller.h"
#include <iostream>

IA_test_Room_Controller::IA_test_Room_Controller(IA_Room_Controller &a_room_Controller)
    : room_Controller(a_room_Controller){};

void IA_test_Room_Controller::control_application_start()
{
    chooce_Room();
};

void IA_test_Room_Controller::chooce_Room()
{
    while (true)
    {
        system("cls");
        room_Controller.control_list_all();
        show_menu_message_prompt();
        char choice;
        std::cin >> choice;
        if (choice == '1')
        {
            room_Controller.control_create();
            continue;
        }
        if (choice == '2')
        {
            room_Controller.control_update();
            continue;
        }
        if (choice == '3')
        {
            room_Controller.control_remove();
            continue;
        }
        if (choice == '4')
        {
            break;
        }
        show_menu_message_unexpected_input();
    }
};

void IA_test_Room_Controller::show_menu_message_prompt()
{
    std::cout << "Please enter the number of the option you choose: ";
};
void IA_test_Room_Controller::show_menu_message_unexpected_input()
{
    std::cout << "Unexpected Input! Please try again!\n";
};