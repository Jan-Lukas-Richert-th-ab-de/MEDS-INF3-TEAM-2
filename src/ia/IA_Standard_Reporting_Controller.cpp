#include "IA_Standard_Reporting_Controller.h"
#include <iostream>
#include <string>

IA_Standard_Reporting_Controller::IA_Standard_Reporting_Controller(AR_UCI_Standard_Reporting_IB &uci, AR_UCI_Doctor_Administration_IB &doctor_uci, AR_UCI_Patient_Administration_IB &patient_uci, AR_UCI_Room_Administration_IB &room_uci)
    : resource_uci(uci), resource_doctor_uci(doctor_uci), resource_patient_uci(patient_uci), resource_room_uci(room_uci){};
void IA_Standard_Reporting_Controller::control_list_all()
{
    resource_uci.list_all();
};
void IA_Standard_Reporting_Controller::control_report_doctor_timeplan()
{
    std::cout << MESSAGE_CREATE_Standard_Reporting_D_ID_PROMPT;
    resource_doctor_uci.list_all_data();
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
    resource_uci.report_doctor_timeplan(id, day, month, year);
};

void IA_Standard_Reporting_Controller::control_report_room_occupancy_plan()
{
    std::cout << MESSAGE_CREATE_Standard_Reporting_ID_PROMPT;
    resource_room_uci.list_all_data();
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
    resource_uci.report_room_occupancy_plan(id, day, month, year);
};

void IA_Standard_Reporting_Controller::control_report_doctor_timeplan_week()
{
    std::cout << MESSAGE_CREATE_Standard_Reporting_D_ID_PROMPT;
    resource_doctor_uci.list_all_data();
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
    resource_uci.report_doctor_timeplan_week(id, day, month, year);
};

void IA_Standard_Reporting_Controller::control_report_room_occupancy_plan_week()
{
    std::cout << MESSAGE_CREATE_Standard_Reporting_ID_PROMPT;
    resource_room_uci.list_all_data();
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
    resource_uci.report_room_occupancy_plan_week(id, day, month, year);
};
