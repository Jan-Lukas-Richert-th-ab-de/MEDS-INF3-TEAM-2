#ifndef IA_APPOINTMENT_CONTROLLER_H
#define IA_APPOINTMENT_CONTROLLER_H
#include <string>
#include "AR_UCI_Appointment_Administration_IB.h"
#include "AR_UCI_Doctor_Administration_IB.h"
#include "AR_UCI_Patient_Administration_IB.h"
#include "AR_UCI_Room_Administration_IB.h"

class IA_Appointment_Controller
{
public:
    IA_Appointment_Controller(AR_UCI_Appointment_Administration_IB &uci, AR_UCI_Doctor_Administration_IB &doctor_uci, AR_UCI_Patient_Administration_IB &patient_uci,AR_UCI_Room_Administration_IB &room_uci);

    void control_list_all();
    void control_create();
    void control_update();
    void control_remove();
    

private:
    AR_UCI_Appointment_Administration_IB &resource_uci;
    AR_UCI_Doctor_Administration_IB &resource_doctor_uci;
    AR_UCI_Patient_Administration_IB &resource_patient_uci;
    AR_UCI_Room_Administration_IB &resource_room_uci;
    const std::string MESSAGE_CREATE_APPOINTMENT_DAY_PROMPT{"Please enter the day of the appointment:\n"};
    const std::string MESSAGE_CREATE_APPOINTMENT_MONTH_PROMPT{"Please enter the month of the appointment:\n"};
    const std::string MESSAGE_CREATE_APPOINTMENT_YEAR_PROMPT{"Please enter the year of the appointment:\n"};                    //+year
    const std::string MESSAGE_CREATE_APPOINTMENT_TIME_START_PROMPT{"Please enter the time_start of the appointment:\n"};        //+time_start
    const std::string MESSAGE_CREATE_APPOINTMENT_TIME_PROMPT{"Please enter the time in minutes of the appointment:\n"};                    //+time
    const std::string MESSAGE_CREATE_APPOINTMENT_DOCTOR_ID_PROMPT{"Please enter the doctor_id of the appointment:\n"};          //+doctor_id
    const std::string MESSAGE_CREATE_APPOINTMENT_PATIENT_ID_PROMPT{"Please enter the patient_id of the appointment:\n"};        //+patient_id
    const std::string MESSAGE_CREATE_APPOINTMENT_ROOM_ID_PROMPT{"Please enter the room_id of the appointment:\n"};              //+room_id
    const std::string MESSAGE_UPDATE_APPOINTMENT_ID_PROMPT{"Please enter the ID of the appointment you want to update:\n"};
    const std::string MESSAGE_UPDATE_APPOINTMENT_DAY_PROMPT{"Please enter the updated day of the appointment:\n"};
    const std::string MESSAGE_UPDATE_APPOINTMENT_MONTH_PROMPT{"Please enter the updated month of the appointment:\n"};
    const std::string MESSAGE_UPDATE_APPOINTMENT_YEAR_PROMPT{"Please enter the updated year of the appointment:\n"};             //+year
    const std::string MESSAGE_UPDATE_APPOINTMENT_TIME_START_PROMPT{"Please enter the updated time_start of the appointment:\n"}; //+ts
    const std::string MESSAGE_UPDATE_APPOINTMENT_TIME_PROMPT{"Please enter the updated time in minutes of the appointment:\n"};             //+t
    const std::string MESSAGE_UPDATE_APPOINTMENT_DOCTOR_ID_PROMPT{"Please enter the updated doctor_id of the appointment:\n"};   //+doctor_id
    const std::string MESSAGE_UPDATE_APPOINTMENT_PATIENT_ID_PROMPT{"Please enter the updated patient_id of the appointment:\n"}; //+patient_id
    const std::string MESSAGE_UPDATE_APPOINTMENT_ROOM_ID_PROMPT{"Please enter the updated room_id of the appointment:\n"};       //+room_id
    const std::string MESSAGE_REMOVE_APPOINTMENT_ID_PROMPT{"Please enter the ID of the appointment you want to delete:\n"};
    const std::string MESSAGE_REMOVE_APPOINTMENT_CONFIRMATION_PROMPT{"Are you sure you want to delete the entry? [y/n]\n"};
};
#endif /* IA_APPOINTMENT_CONTROLLER_H */