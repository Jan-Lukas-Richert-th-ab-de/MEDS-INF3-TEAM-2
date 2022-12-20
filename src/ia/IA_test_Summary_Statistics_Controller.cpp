#include "IA_test_Summary_Statistics_Controller.h"
#include <iostream>

IA_test_Summary_Statistics_Controller::IA_test_Summary_Statistics_Controller(IA_Summary_Statistics_Controller &a_Summary_Statistics_Controller)
    : Summary_Statistics_Controller(a_Summary_Statistics_Controller){};

void IA_test_Summary_Statistics_Controller::control_application_start()
{
    system("cls");
    Summary_Statistics_Controller.control_list_all();
    chooce_Summary_Statistics();
};

void IA_test_Summary_Statistics_Controller::chooce_Summary_Statistics()
{
    while (true)
    {
        system("cls");
        Summary_Statistics_Controller.control_list_all();
        show_menu_message_prompt();
        char choice;
        std::cin >> choice;
      
        if (choice == '2')
        {
            Summary_Statistics_Controller.control_report();
            continue;
        }
      
        if (choice == '4')
        {
            break;
        }
        show_menu_message_unexpected_input();
    }
};

void IA_test_Summary_Statistics_Controller::show_menu_message_prompt()
{
    std::cout << "Please enter the number of the option you choose: ";
};
void IA_test_Summary_Statistics_Controller::show_menu_message_unexpected_input()
{
    std::cout << "Unexpected Input! Please try again!\n";
};