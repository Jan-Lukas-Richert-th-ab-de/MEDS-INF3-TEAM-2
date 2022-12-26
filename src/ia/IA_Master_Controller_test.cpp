#include "IA_Master_Controller_test.h"
#include <iostream>

IA_Master_Controller_test::IA_Master_Controller_test(
    IA_test_Room_Controller &a_test_Room_Controller, IA_test_Doctor_Controller &a_test_Doctor_Controller,
    IA_test_Patient_Controller &a_test_Patient_Controller, IA_test_Appointment_Controller &a_test_Appointment_Controller,
    IA_test_Room_Presenter &a_view
    ,IA_test_Summary_Statistics_Controller &a_test_Summary_Statistics_Controller)
    : test_Room_Controller(a_test_Room_Controller), test_Patient_Controller(a_test_Patient_Controller),
      test_Doctor_Controller(a_test_Doctor_Controller), test_Appointment_Controller(a_test_Appointment_Controller),
      view(a_view),
      test_Summary_Statistics_Controller(a_test_Summary_Statistics_Controller)
      {};

void IA_Master_Controller_test::control_application_start()
{
    system("cls");
    control_menu_choice();
};

void IA_Master_Controller_test::control_menu_choice()
{
    while (true)
    {
        system("cls");
        view.present_all();
        show_menu_message_prompt();
        char choice;
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
            test_Appointment_Controller.control_application_start();
            continue;
        }
        if (choice == '5')
        { test_Summary_Statistics_Controller.control_application_start();
            continue;
        }
    
      if (choice == '6')
        {
            break;
        }
        show_menu_message_unexpected_input();
    }
};

void IA_Master_Controller_test::show_menu_message_prompt()
{
    std::cout << "Please enter the number of the option you choose: ";
};
void IA_Master_Controller_test::show_menu_message_unexpected_input()
{
    std::cout << "Unexpected Input! Please try again!\n";
    system("pause");
    system("cls");
};