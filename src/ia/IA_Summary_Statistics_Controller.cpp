#include "IA_Summary_Statistics_Controller.h"
#include <iostream>
#include <string>

IA_Summary_Statistics_Controller::IA_Summary_Statistics_Controller (AR_UCI_Summary_Statistics_Creation_IB &uci)
    : resource_uci(uci){};
void IA_Summary_Statistics_Controller::control_list_all()
{
    resource_uci.list_all();
};
void IA_Summary_Statistics_Controller::control_report_doctor_Summary_Statistics()
{
    std::cout << MESSAGE_CREATE_Summary_Statistics_D_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_CREATE_Summary_Statistics_DAY_PROMPT;
    std::string day{};
    std::cin >> day;
    std::cout << MESSAGE_CREATE_Summary_Statistics_MONTH_PROMPT;
    std::string month{};
    std::cin >> month;
    std::cout << MESSAGE_CREATE_Summary_Statistics_YEAR_PROMPT;
    std::string year{};
    std::cin >> year;
    resource_uci.report_doctor_Summary_Statistics(id, day, month, year );
};



void IA_Summary_Statistics_Controller::control_report_room_occupancy_Summary_Statistics()
{
    std::cout << MESSAGE_CREATE_Summary_Statistics_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_CREATE_Summary_Statistics_DAY_PROMPT;
    std::string day{};
    std::cin >> day;
    std::cout << MESSAGE_CREATE_Summary_Statistics_MONTH_PROMPT;
    std::string month{};
    std::cin >> month;
    std::cout << MESSAGE_CREATE_Summary_Statistics_YEAR_PROMPT;
    std::string year{};
    std::cin >> year;
    resource_uci.report_room_occupancy_Summary_Statistics(id, day, month, year );
};
void IA_Summary_Statistics_Controller::control_report_doctor_Summary_Statistics_per_week()
{
    std::cout << MESSAGE_CREATE_Summary_Statistics_D_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_CREATE_Summary_Statistics_DAY_PROMPT;
    std::string day{};
    std::cin >> day;
    std::cout << MESSAGE_CREATE_Summary_Statistics_MONTH_PROMPT;
    std::string month{};
    std::cin >> month;
    std::cout << MESSAGE_CREATE_Summary_Statistics_YEAR_PROMPT;
    std::string year{};
    std::cin >> year;
    resource_uci.report_doctor_Summary_Statistics_pre_week(id, day, month, year );
};
void IA_Summary_Statistics_Controller::control_report_room_occupancy_Summary_Statistics_per_week()
{
    std::cout << MESSAGE_CREATE_Summary_Statistics_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_CREATE_Summary_Statistics_DAY_PROMPT;
    std::string day{};
    std::cin >> day;
    std::cout << MESSAGE_CREATE_Summary_Statistics_MONTH_PROMPT;
    std::string month{};
    std::cin >> month;
    std::cout << MESSAGE_CREATE_Summary_Statistics_YEAR_PROMPT;
    std::string year{};
    std::cin >> year;
    resource_uci.report_room_occupancy_Summary_Statistics_pre_week(id, day, month, year );
};
