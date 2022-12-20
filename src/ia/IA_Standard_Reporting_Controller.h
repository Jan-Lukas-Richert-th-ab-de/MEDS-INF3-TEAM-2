#ifndef IA_STANDARD_REPORTING_CONTROLLER_H
#define IA_STANDARD_REPORTING_CONTROLLER_H
#include <string>
#include "AR_UCI_Standard_Reporting_IB.h"

class IA_Standard_Reporting_Controller {
    public:
        IA_Standard_Reporting_Controller(
              AR_UCI_Standard_Reporting_IB& room_uci
            , AR_UCI_Standard_Reporting_IB& doctor_uci
            , AR_UCI_Standard_Reporting_IB& appointment_uci);

        void control_list_all();

        void controll_report_room();
        void controll_report_doctor();
        void controll_report_appointment();
        
    private:
      AR_UCI_Standard_Reporting_IB& report_room_uci;
      AR_UCI_Standard_Reporting_IB& report_doctor_uci;
      AR_UCI_Standard_Reporting_IB& report_appointment_uci;
         
};
#endif /* IA_Standard_Reporting_CONTROLLER_H */