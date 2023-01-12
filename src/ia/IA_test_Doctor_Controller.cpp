#include "IA_test_Doctor_Controller.h"
#include <iostream>

IA_test_Doctor_Controller::IA_test_Doctor_Controller(IA_Doctor_Controller &a_doctor_Controller)
    : doctor_Controller(a_doctor_Controller){};

void IA_test_Doctor_Controller::control_application_start()
{
    system("cls");
    // doctor_Controller.control_list_all();
    choose_Doctor();
};

void IA_test_Doctor_Controller::choose_Doctor()
{
    while (true)
    {
        system("cls");
        doctor_Controller.control_list_all();
        show_menu_message_prompt();
        char choice;
        std::cin >> choice;
        if (choice == '1')
        {
            doctor_Controller.control_create();
            continue;
        }
        if (choice == '2')
        {
            doctor_Controller.control_update();
            continue;
        }
        if (choice == '3')
        {
            doctor_Controller.control_remove();
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

void IA_test_Doctor_Controller::show_menu_message_prompt()
{
    std::cout << "Please enter the number of the option you choose: ";
};
void IA_test_Doctor_Controller::show_menu_message_unexpected_input()
{
    std::cout << "Unexpected Input! Please try again!\n";
};