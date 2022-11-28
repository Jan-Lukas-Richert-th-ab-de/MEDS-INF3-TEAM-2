#include "IA_Room_Controller.h"
#include <iostream>
#include <string>

IA_Room_Controller::IA_Room_Controller(AR_UCI_Room_Administration_IB &uci)
    : resource_uci(uci){};
void IA_Room_Controller::control_list_all()
{
    resource_uci.list_all();
};

void IA_Room_Controller::control_create()
{
    std::cout << MESSAGE_CREATE_ROOM_ROOM_DESCRIPTION_PROMPT;
    std::string room_description{};
    std::cin >> room_description;
    std::cout << MESSAGE_CREATE_ROOM_ROOM_NUMBER_PROMPT;
    std::string room_number{};
    std::cin >> room_number;
    resource_uci.create(room_description, room_number);
};

void IA_Room_Controller::control_update()
{
    std::cout << MESSAGE_UPDATE_ROOM_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_UPDATE_ROOM_ROOM_DESCRIPTION_PROMPT;
    std::string room_description{};
    std::cin >> room_description;
    std::cout << MESSAGE_UPDATE_ROOM_ROOM_NUMBER_PROMPT;
    std::string room_number{};
    std::cin >> room_number;
    resource_uci.update(id, room_description, room_number);
};

void IA_Room_Controller::control_remove()
{
    std::cout << MESSAGE_REMOVE_ROOM_ID_PROMPT;
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_REMOVE_ROOM_CONFIRMATION_PROMPT;
    char choice{};
    std::cin >> choice;
    if (choice == 'y')
        resource_uci.remove(id);
    else
        resource_uci.list_all();
};