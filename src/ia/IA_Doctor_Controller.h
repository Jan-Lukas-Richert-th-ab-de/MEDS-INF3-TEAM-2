#ifndef IA_DOCTOR_CONTROLLER_H
#define IA_DOCTOR_CONTROLLER_H
#include <string>
#include "AR_UCI_Doctor_Administration_IB.h"

class IA_Doctor_Controller
{
public:
    IA_Doctor_Controller(AR_UCI_Doctor_Administration_IB &uci);
    void control_list_all();
    void control_create();
    void control_update();
    void control_remove();

private:
    AR_UCI_Doctor_Administration_IB &resource_uci;
    const std::string MESSAGE_CREATE_DOCTOR_FIRST_NAME_PROMPT{"Please enter the first name of the doctor:\n"};
    const std::string MESSAGE_CREATE_DOCTOR_LAST_NAME_PROMPT{"Please enter the last name of the doctor:\n"};
    const std::string MESSAGE_UPDATE_DOCTOR_ID_PROMPT{"Please enter the ID of the doctor you want to update:\n"};
    const std::string MESSAGE_UPDATE_DOCTOR_FIRST_NAME_PROMPT{"Please enter the updated first name of the doctor:\n"};
    const std::string MESSAGE_UPDATE_DOCTOR_LAST_NAME_PROMPT{"Please enter the updated last name of the doctor:\n"};
    const std::string MESSAGE_REMOVE_DOCTOR_ID_PROMPT{"Please enter the ID of the doctor you want to delete:\n"};
    const std::string MESSAGE_REMOVE_DOCTOR_CONFIRMATION_PROMPT{"Are you sure you want to delete the entry? [y/n]\n"};
    const std::string MESSAGE_CREATE_DOCTOR_DOCTOR_SPECIALTIES_PROMPT{"Please enter the Specialities of the doctor:\n"};
    const std::string MESSAGE_UPDATE_DOCTOR_DOCTOR_SPECIALTIES_PROMPT{"Please enter the updated Specialities of the doctor:\n"};
};
#endif /* IA_DOCTOR_CONTROLLER_H */