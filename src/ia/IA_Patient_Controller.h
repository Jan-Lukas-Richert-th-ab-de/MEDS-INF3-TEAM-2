#ifndef IA_PATIENT_CONTROLLER_H
#define IA_PATIENT_CONTROLLER_H
#include <string>
#include "AR_UCI_Patient_Administration_IB.h"

class IA_Patient_Controller
{
public:
    IA_Patient_Controller(AR_UCI_Patient_Administration_IB &uci);
    void control_list_all();
    void control_create();
    void control_update();
    void control_remove();

private:
    AR_UCI_Patient_Administration_IB &resource_uci;
    const std::string MESSAGE_CREATE_PATIENT_FIRST_NAME_PROMPT{"Please enter the first name of the patient:\n"};
    const std::string MESSAGE_CREATE_PATIENT_LAST_NAME_PROMPT{"Please enter the last name of the patient:\n"};
    const std::string MESSAGE_UPDATE_PATIENT_ID_PROMPT{"Please enter the ID of the patient you want to update:\n"};
    const std::string MESSAGE_UPDATE_PATIENT_FIRST_NAME_PROMPT{"Please enter the updated first name of the patient:\n"};
    const std::string MESSAGE_UPDATE_PATIENT_LAST_NAME_PROMPT{"Please enter the updated last name of the patient:\n"};
    const std::string MESSAGE_REMOVE_PATIENT_ID_PROMPT{"Please enter the ID of the patient you want to delete:\n"};
    const std::string MESSAGE_REMOVE_PATIENT_CONFIRMATION_PROMPT{"Are you sure you want to delete the entry? [y/n]\n"};
};
#endif /* IA_PATIENT_CONTROLLER_H */