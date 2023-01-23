#include "IA_Display_Patient_Controller.h"
#include <iostream>

IA_Display_Patient_Controller::IA_Display_Patient_Controller(IA_Patient_Controller &a_patient_Controller)
    : patient_Controller(a_patient_Controller){};

void IA_Display_Patient_Controller::control_application_start()
{
    system("cls");
    choose_Patient();
};

void IA_Display_Patient_Controller::choose_Patient()
{
    while (true)
    {
        system("cls");
        patient_Controller.control_list_all();
        show_menu_message_prompt();
        char choice;
        std::cin >> choice;
        if (choice == '1')
        {
            patient_Controller.control_create();
            continue;
        }
        if (choice == '2')
        {
            patient_Controller.control_update();
            continue;
        }
        if (choice == '3')
        {
            patient_Controller.control_remove();
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

void IA_Display_Patient_Controller::show_menu_message_prompt()
{
    std::cout << "Please enter the number of the option you choose: ";
};
void IA_Display_Patient_Controller::show_menu_message_unexpected_input()
{
    std::cout << "Unexpected Input! Please try again!\n";
    system("pause");
    system("cls");
};