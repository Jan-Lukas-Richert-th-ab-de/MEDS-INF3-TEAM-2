#ifndef IA_ROOM_CONTROLLER_H
#define IA_ROOM_CONTROLLER_H
#include <string>
#include "AR_UCI_Room_Administration_IB.h"

class IA_Room_Controller
{
public:
    IA_Room_Controller(AR_UCI_Room_Administration_IB &uci);
    void control_list_all();
    void control_create();
    void control_update();
    void control_remove();

private:
    AR_UCI_Room_Administration_IB &resource_uci;
    const std::string MESSAGE_CREATE_ROOM_ROOM_DESCRIPTION_PROMPT{"Please enter the room description of the room:\n"};
    const std::string MESSAGE_CREATE_ROOM_ROOM_NUMBER_PROMPT{"Please enter the room number of the room:\n"};
    const std::string MESSAGE_UPDATE_ROOM_ID_PROMPT{"Please enter the ID of the room you want to update:\n"};
    const std::string MESSAGE_UPDATE_ROOM_ROOM_DESCRIPTION_PROMPT{"Please enter the updated room description of the room:\n"};
    const std::string MESSAGE_UPDATE_ROOM_ROOM_NUMBER_PROMPT{"Please enter the updated room number of the room:\n"};
    const std::string MESSAGE_REMOVE_ROOM_ID_PROMPT{"Please enter the ID of the room you want to delete:\n"};
    const std::string MESSAGE_REMOVE_ROOM_CONFIRMATION_PROMPT{"Are you sure you want to delete the entry? [y/n]\n"};
};
#endif /* IA_ROOM_CONTROLLER_H */