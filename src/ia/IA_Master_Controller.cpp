#include "IA_Master_Controller.h"
#include <iostream>

IA_Master_Controller::IA_Master_Controller(
    IA_test_Room_Controller &a_test_Room_Controller, IA_test_Doctor_Controller &a_test_Doctor_Controller,
    IA_test_Patient_Controller &a_test_Patient_Controller, IA_test_Appointment_Controller &a_test_Appointment_Controller,
    IA_Master_Presenter &a_view)
    : test_Room_Controller(a_test_Room_Controller), test_Patient_Controller(a_test_Patient_Controller),
      test_Doctor_Controller(a_test_Doctor_Controller), test_Appointment_Controller(a_test_Appointment_Controller),
      view(a_view){};

void IA_Master_Controller::control_application_start()
{
    system("cls");
    control_menu_choice();
};

void IA_Master_Controller::control_menu_choice()
{
    while (true)
    {
        system("cls");
        view.present_all_MAIN();
        show_menu_message_prompt();
        char choice;
        std::cin >> choice;
        if (choice == '1')
        {
            system("cls");
            view.present_all_CORE_RESURCES();
            std::cin >> choice;
            if (choice == '1')
            {
                test_Patient_Controller.control_application_start();
                continue;
            }
            if (choice == '2')
            {
                test_Doctor_Controller.control_application_start();
                continue;
            }
            if (choice == '3')
            {
                test_Room_Controller.control_application_start();
                continue;
            }
            if (choice == '4')
            {
                continue;
            }
        }
        if (choice == '2')
        {
            system("cls");
            test_Appointment_Controller.control_application_start();
            continue;
        }
        if (choice == '3')
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
    system("pause");
    system("cls");
};