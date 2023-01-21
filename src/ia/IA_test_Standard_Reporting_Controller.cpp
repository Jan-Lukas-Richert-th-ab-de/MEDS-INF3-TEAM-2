#include "IA_test_Standard_Reporting_Controller.h"
#include <iostream>

IA_test_Standard_Reporting_Controller::IA_test_Standard_Reporting_Controller(IA_Standard_Reporting_Controller &a_Standard_Reporting_Controller)
    : Standard_Reporting_Controller(a_Standard_Reporting_Controller){};


void IA_test_Standard_Reporting_Controller::control_application_start()
{
    system("cls");
     chooce_Standard_Reporting();
};

void IA_test_Standard_Reporting_Controller::chooce_Standard_Reporting()
{
    while (true)
    {
        
        Standard_Reporting_Controller.control_list_all();
        show_menu_message_prompt();
        char choice;
        std::cin >> choice;
        if (choice == '1')
        {
            Standard_Reporting_Controller.control_report_room_occupancy_plan();
            continue;
        }
        if (choice == '2')
        {
            Standard_Reporting_Controller.control_report_room_occupancy_plan_week();
            continue;
        }
        if (choice == '3')
        {
        Standard_Reporting_Controller.control_report_doctor_timeplan();
            continue;
        }
        if (choice == '4')
        {
        Standard_Reporting_Controller.control_report_doctor_timeplan_week();
            continue;
        }
       
     if (choice == '5')
        {system("cls");
            break;
        }
        show_menu_message_prompt();
    }
};

void IA_test_Standard_Reporting_Controller::show_menu_message_prompt()
{
    std::cout << "Please enter the number of the option you choose: ";
};
void IA_test_Standard_Reporting_Controller::show_menu_message_unexpected_input()
{
    std::cout << "Unexpected Input! Please try again!\n";
    system("pause");
    system("cls");
};