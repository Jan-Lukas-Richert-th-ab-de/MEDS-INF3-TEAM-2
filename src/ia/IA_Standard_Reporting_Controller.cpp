#include "IA_Standard_Reporting_Controller.h"
#include <iostream>
#include <string>



IA_Standard_Reporting_Controller::IA_Standard_Reporting_Controller (AR_UCI_Standard_Reporting_IB &uci)
    : resource_uci(uci){};
    void IA_Standard_Reporting_Controller::control_list_all()
{
    resource_uci.list_all();
};
void IA_Standard_Reporting_Controller::control_report_doctor_timeplan()
{
    std::cout << MESSAGE_CREATE_Standard_Reporting_D_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_CREATE_Standard_Reporting_DAY_PROMPT;
    std::string day{};
    std::cin >> day;
    std::cout << MESSAGE_CREATE_Standard_Reporting_MONTH_PROMPT;
    std::string month{};
    std::cin >> month;
    std::cout << MESSAGE_CREATE_Standard_Reporting_YEAR_PROMPT;
    std::string year{};
    std::cin >> year;
    resource_uci.report_doctor_timeplan(id, day, month, year );
};



void IA_Standard_Reporting_Controller::control_report_room_occupancy_plan()
{
     std::cout << MESSAGE_CREATE_Standard_Reporting_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_CREATE_Standard_Reporting_DAY_PROMPT;
    std::string day{};
    std::cin >> day;
    std::cout << MESSAGE_CREATE_Standard_Reporting_MONTH_PROMPT;
    std::string month{};
    std::cin >> month;
    std::cout << MESSAGE_CREATE_Standard_Reporting_YEAR_PROMPT;
    std::string year{};
    std::cin >> year;
    resource_uci.report_room_occupancy_plan(id, day, month, year );
};

void IA_Standard_Reporting_Controller::control_report_doctor_timeplan_week()
{
    std::cout << MESSAGE_CREATE_Standard_Reporting_D_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_CREATE_Standard_Reporting_DAY_PROMPT;
    std::string day{};
    std::cin >> day;
    std::cout << MESSAGE_CREATE_Standard_Reporting_MONTH_PROMPT;
    std::string month{};
    std::cin >> month;
    std::cout << MESSAGE_CREATE_Standard_Reporting_YEAR_PROMPT;
    std::string year{};
    std::cin >> year;
    resource_uci.report_doctor_timeplan_week(id, day, month, year );
};



void IA_Standard_Reporting_Controller::control_report_room_occupancy_plan_week()
{
     std::cout << MESSAGE_CREATE_Standard_Reporting_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_CREATE_Standard_Reporting_DAY_PROMPT;
    std::string day{};
    std::cin >> day;
    std::cout << MESSAGE_CREATE_Standard_Reporting_MONTH_PROMPT;
    std::string month{};
    std::cin >> month;
    std::cout << MESSAGE_CREATE_Standard_Reporting_YEAR_PROMPT;
    std::string year{};
    std::cin >> year;
    resource_uci.report_room_occupancy_plan_week(id, day, month, year );
};

