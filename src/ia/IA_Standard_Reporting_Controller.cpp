#include "IA_Standard_Reporting_Controller.h"
#include <iostream>
#include <string>



IA_Standard_Reporting_Controller::IA_Standard_Reporting_Controller(AR_UCI_Standard_Reporting_IB& room_uci, AR_UCI_Standard_Reporting_IB& doctor_uci, AR_UCI_Standard_Reporting_IB& appointment_uci)
            : report_room_uci(room_uci), report_doctor_uci (doctor_uci), report_appointment_uci (appointment_uci) {};



void IA_Standard_Reporting_Controller::control_report_room() {
    report_room_uci.report_room();
};




void IA_Standard_Reporting_Controller::control_report_doctor() {
    report_doctor_uci.report_doctor();

}



void IA_Standard_Reporting_Controller::control_report_appointment() {
    report_appointment_uci.report_appointment();

}