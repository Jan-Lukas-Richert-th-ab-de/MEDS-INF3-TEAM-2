#include "IA_Summary_Statistics_Controller.h"
#include <iostream>
#include <string>
#include <regex>

IA_Summary_Statistics_Controller::IA_Summary_Statistics_Controller (AR_UCI_Summary_Statistics_Creation_IB &uci)
    : resource_uci(uci){};
void IA_Summary_Statistics_Controller::control_list_all()
{
    resource_uci.list_all();
};
void IA_Summary_Statistics_Controller::control_report_doctor_Summary_Statistics()
{
    
            const std::__cxx11::regex pattern{R"((3[01]|[12][0-9]|0?[1-9])\.(1[012]|0?[1-9])\.(20\d{2}))"};
    std::string try_regex_date{};
   
    std::cout << MESSAGE_CREATE_Summary_Statistics_D_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::string  day{};
   std::string  month{};
    std::string year{};
    do {
        try_regex_date = "";
        std::cout << MESSAGE_CREATE_Summary_Statistics_DATE_PROMPT;
        std::cin >> day >> month >> year;
        try_regex_date.append(day);
        try_regex_date.append(".");
        try_regex_date.append(month);
        try_regex_date.append(".");
        try_regex_date.append(year);
        if (!regex_match(try_regex_date, pattern)) {
            std::cout << MESSAGE_CREATE_Summary_Statistics_DATE_PROMPT;
        }
    } while(!regex_match(try_regex_date, pattern));
    resource_uci.report_doctor_Summary_Statistics(id, day, month, year );
};



void IA_Summary_Statistics_Controller::control_report_room_occupancy_Summary_Statistics()
{
   
            const std::__cxx11::regex pattern{R"((3[01]|[12][0-9]|0?[1-9])\.(1[012]|0?[1-9])\.(20\d{2}))"};
    std::string try_regex_date{};
   
    std::cout << MESSAGE_CREATE_Summary_Statistics_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::string  day{};
   std::string  month{};
    std::string year{};
    do {
        try_regex_date = "";
        std::cout << MESSAGE_CREATE_Summary_Statistics_DATE_PROMPT;
        std::cin >> day >> month >> year;
        try_regex_date.append(day);
        try_regex_date.append(".");
        try_regex_date.append(month);
        try_regex_date.append(".");
        try_regex_date.append(year);
        if (!regex_match(try_regex_date, pattern)) {
            std::cout << MESSAGE_CREATE_Summary_Statistics_DATE_PROMPT;
        }
    } while(!regex_match(try_regex_date, pattern));
    resource_uci.report_room_occupancy_Summary_Statistics(id, day, month, year );
};
void IA_Summary_Statistics_Controller::control_report_doctor_Summary_Statistics_per_week()
{
    
            const std::__cxx11::regex pattern{R"((3[01]|[12][0-9]|0?[1-9])\.(1[012]|0?[1-9])\.(20\d{2}))"};
    std::string try_regex_date{};
   
    std::cout << MESSAGE_CREATE_Summary_Statistics_D_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::string  day{};
   std::string  month{};
    std::string year{};
    do {
        try_regex_date = "";
        std::cout << MESSAGE_CREATE_Summary_Statistics_DATE_PROMPT;
        std::cin >> day >> month >> year;
        try_regex_date.append(day);
        try_regex_date.append(".");
        try_regex_date.append(month);
        try_regex_date.append(".");
        try_regex_date.append(year);
        if (!regex_match(try_regex_date, pattern)) {
            std::cout << MESSAGE_CREATE_Summary_Statistics_DATE_PROMPT;
        }
    } while(!regex_match(try_regex_date, pattern));
};
void IA_Summary_Statistics_Controller::control_report_room_occupancy_Summary_Statistics_per_week()
{
    
            const std::__cxx11::regex pattern{R"((3[01]|[12][0-9]|0?[1-9])\.(1[012]|0?[1-9])\.(20\d{2}))"};
    std::string try_regex_date{};
   
    std::cout << MESSAGE_CREATE_Summary_Statistics_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::string  day{};
   std::string  month{};
    std::string year{};
    do {
        try_regex_date = "";
        std::cout << MESSAGE_CREATE_Summary_Statistics_DATE_PROMPT;
        std::cin >> day >> month >> year;
        try_regex_date.append(day);
        try_regex_date.append(".");
        try_regex_date.append(month);
        try_regex_date.append(".");
        try_regex_date.append(year);
        if (!regex_match(try_regex_date, pattern)) {
            std::cout << MESSAGE_CREATE_Summary_Statistics_DATE_PROMPT;
        }
    } while(!regex_match(try_regex_date, pattern));
    resource_uci.report_room_occupancy_Summary_Statistics_pre_week(id, day, month, year );
};
