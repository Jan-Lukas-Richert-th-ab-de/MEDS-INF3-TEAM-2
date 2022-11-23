#include "IA_Doctor_Controller.h"
#include <iostream>
#include <string>

IA_Doctor_Controller::IA_Doctor_Controller(AR_UCI_Doctor_Administration_IB &uci)
    : resource_uci(uci){};
void IA_Doctor_Controller::control_list_all()
{
    resource_uci.list_all();
};

void IA_Doctor_Controller::control_create()
{
    std::cout << MESSAGE_CREATE_DOCTOR_FIRST_NAME_PROMPT;
    std::string first_name{};
    std::cin >> first_name;
    std::cout << MESSAGE_CREATE_DOCTOR_LAST_NAME_PROMPT;
    std::string last_name{};
    std::cin >> last_name;
    std::cout << MESSAGE_CREATE_DOCTOR_DOCTOR_SPECIALTIES_PROMPT;
    std::string doctor_specialties{};
    std::cin >> doctor_specialties;
    resource_uci.create(first_name, last_name, doctor_specialties);
};

void IA_Doctor_Controller::control_update()
{
    std::cout << MESSAGE_UPDATE_DOCTOR_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_UPDATE_DOCTOR_FIRST_NAME_PROMPT;
    std::string first_name{};
    std::cin >> first_name;
    std::cout << MESSAGE_UPDATE_DOCTOR_LAST_NAME_PROMPT;
    std::string last_name{};
    std::cin >> last_name;
    std::cout << MESSAGE_UPDATE_DOCTOR_DOCTOR_SPECIALTIES_PROMPT;
    std::string doctor_specialties{};
    std::cin >> doctor_specialties;

    resource_uci.update(id, first_name, last_name, doctor_specialties);
};

void IA_Doctor_Controller::control_remove()
{
    std::cout << MESSAGE_REMOVE_DOCTOR_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_REMOVE_DOCTOR_CONFIRMATION_PROMPT;
    char choice{};
    std::cin >> choice;
    if (choice == 'y')
        resource_uci.remove(id);
    else
        resource_uci.list_all();
};