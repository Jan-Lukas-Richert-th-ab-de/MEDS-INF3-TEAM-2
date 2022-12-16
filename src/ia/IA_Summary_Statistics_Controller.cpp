#include "IA_Summary_Statistics_Controller.h"
#include <iostream>
#include <string>

IA_Summary_Statistics_Controller::IA_Summary_Statistics_Controller (AR_UCI_Summary_Statistics_Reporting_IB &uci)
    : resource_uci(uci){};
void IA_Summary_Statistics_Controller::control_list_all()
{
    resource_uci.list_all();
};



void IA_Summary_Statistics_Controller::control_report()
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
    resource_uci.report(id, day, month, year );
};

