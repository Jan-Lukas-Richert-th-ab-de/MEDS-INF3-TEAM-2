#include "IA_Master_Controller.h"
#include <iostream>

IA_Master_Controller::IA_Master_Controller(IA_Patient_Controller &a_patient_controller)
    : patient_controller(a_patient_controller){};

void IA_Master_Controller::control_application_start()
{
    patient_controller.control_list_all();
    control_menu_choice();
};

void IA_Master_Controller::control_menu_choice()
{
    while (true)
    {
        show_menu_message_prompt();
        char choice;
        std::cin >> choice;
        if (choice == '1')
        {
            patient_controller.control_create();
            continue;
        }
        if (choice == '2')
        {
            patient_controller.control_update();
            continue;
        }
        if (choice == '3')
        {
            patient_controller.control_remove();
            continue;
        }
        if (choice == '4')
        {
            break;
        }
        show_menu_message_unexpected_input();
    }
};

void IA_Master_Controller::show_menu_message_prompt()
{
    std::cout << "Please enter the number of the option you choose: ";
};
void IA_Master_Controller::show_menu_message_unexpected_input()
{
    std::cout << "Unexpected Input! Please try again!\n";
};