#include "IA_test_Appointment_Controller.h"
#include <iostream>

IA_test_Appointment_Controller::IA_test_Appointment_Controller(IA_Appointment_Controller &a_appointment_Controller)
    : appointment_Controller(a_appointment_Controller){};

void IA_test_Appointment_Controller::control_application_start()
{
    system("cls");
    // appointment_Controller.control_list_all();
    chooce_Appointment();
};

void IA_test_Appointment_Controller::chooce_Appointment()
{
    while (true)
    {
        system("cls");
        appointment_Controller.control_list_all();
        show_menu_message_prompt();
        char choice;
        std::cin >> choice;
        if (choice == '1')
        {
            appointment_Controller.control_create();
            continue;
        }
        if (choice == '2')
        {
            appointment_Controller.control_update();
            continue;
        }
        if (choice == '3')
        {
            appointment_Controller.control_remove();
            continue;
        }
        if (choice == '4')
        {
            system("cls");
            break;
        }
        show_menu_message_unexpected_input();
    }
};

void IA_test_Appointment_Controller::show_menu_message_prompt()
{
    std::cout << "Please enter the number of the option you choose: ";
};
void IA_test_Appointment_Controller::show_menu_message_unexpected_input()
{
    std::cout << "Unexpected Input! Please try again!\n";
};