#include "IA_Appointment_Controller.h"
#include <iostream>
#include <string>

IA_Appointment_Controller::IA_Appointment_Controller(AR_UCI_Appointment_Administration_IB &uci)
    : resource_uci(uci){};
void IA_Appointment_Controller::control_list_all()
{
    resource_uci.list_all();
};

void IA_Appointment_Controller::control_create()
{
    std::cout << MESSAGE_CREATE_APPOINTMENT_DAY_PROMPT;
    std::string day{};
    std::cin >> day;
    std::cout << MESSAGE_CREATE_APPOINTMENT_MONTH_PROMPT;
    std::string month{};
    std::cin >> month;
    std::cout << MESSAGE_CREATE_APPOINTMENT_YEAR_PROMPT;
    std::string year{};
    std::cin >> year;
    std::cout << MESSAGE_CREATE_APPOINTMENT_TIME_START_PROMPT;
    std::string time_start{};
    std::cin >> time_start;
    std::cout << MESSAGE_CREATE_APPOINTMENT_TIME_PROMPT;
    std::string time{};
    std::cin >> time;
    std::cout << MESSAGE_CREATE_APPOINTMENT_DOCTOR_ID_PROMPT;
    unsigned int doctor_id{};
    std::cin >> doctor_id;
    std::cout << MESSAGE_CREATE_APPOINTMENT_PATIENT_ID_PROMPT;
    unsigned int patient_id{};
    std::cin >> patient_id;
    std::cout << MESSAGE_CREATE_APPOINTMENT_ROOM_ID_PROMPT;
    unsigned int room_id{};
    std::cin >> room_id;
    resource_uci.create(day, month, year, time_start, time, doctor_id, patient_id, room_id);
};

void IA_Appointment_Controller::control_update()
{
    std::cout << MESSAGE_UPDATE_APPOINTMENT_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_UPDATE_APPOINTMENT_DAY_PROMPT;
    std::string day{};
    std::cin >> day;
    std::cout << MESSAGE_UPDATE_APPOINTMENT_MONTH_PROMPT;
    std::string month{};
    std::cin >> month;
    std::cout << MESSAGE_UPDATE_APPOINTMENT_YEAR_PROMPT;
    std::string year{};
    std::cin >> year;
    std::cout << MESSAGE_UPDATE_APPOINTMENT_TIME_START_PROMPT;
    std::string time_start{};
    std::cin >> time_start;
    std::cout << MESSAGE_UPDATE_APPOINTMENT_TIME_PROMPT;
    std::string time{};
    std::cin >> time;
    std::cout << MESSAGE_UPDATE_APPOINTMENT_DOCTOR_ID_PROMPT;
    unsigned int doctor_id{};
    std::cin >> doctor_id;
    std::cout << MESSAGE_UPDATE_APPOINTMENT_PATIENT_ID_PROMPT;
    unsigned int patient_id{};
    std::cin >> patient_id;
    std::cout << MESSAGE_UPDATE_APPOINTMENT_ROOM_ID_PROMPT;
    unsigned int room_id{};
    std::cin >> room_id;
    resource_uci.update(id, day, month, year, time_start, time, doctor_id, patient_id, room_id);
};

void IA_Appointment_Controller::control_remove()
{
    std::cout << MESSAGE_REMOVE_APPOINTMENT_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_REMOVE_APPOINTMENT_CONFIRMATION_PROMPT;
    char choice{};
    std::cin >> choice;
    if (choice == 'y')
        resource_uci.remove(id);
    else
        resource_uci.list_all();
};