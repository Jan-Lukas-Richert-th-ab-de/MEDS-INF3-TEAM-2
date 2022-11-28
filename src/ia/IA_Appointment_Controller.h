#ifndef IA_PERSON_CONTROLLER_H
#define IA_PERSON_CONTROLLER_H
#include <string>
#include "AR_UCI_Person_Administration_IB.h"

class IA_Person_Controller {
    public:
        IA_Person_Controller(AR_UCI_Person_Administration_IB& uci);
        void control_list_all();
        void control_create();
        void control_update();
        void control_remove();
    private:
        AR_UCI_Person_Administration_IB& resource_uci;
        const std::string MESSAGE_CREATE_PERSON_FIRST_NAME_PROMPT{"Please enter the first name of the person:\n"};
        const std::string MESSAGE_CREATE_PERSON_LAST_NAME_PROMPT{"Please enter the last name of the person:\n"};
        const std::string MESSAGE_UPDATE_PERSON_ID_PROMPT{"Please enter the ID of the person you want to update:\n"};
        const std::string MESSAGE_UPDATE_PERSON_FIRST_NAME_PROMPT{"Please enter the updated first name of the person:\n"};
        const std::string MESSAGE_UPDATE_PERSON_LAST_NAME_PROMPT{"Please enter the updated last name of the person:\n"};
        const std::string MESSAGE_REMOVE_PERSON_ID_PROMPT{"Please enter the ID of the person you want to delete:\n"};
        const std::string MESSAGE_REMOVE_PERSON_CONFIRMATION_PROMPT{"Are you sure you want to delete the entry? [y/n]\n"};
};
#endif /* IA_PERSON_CONTROLLER_H */