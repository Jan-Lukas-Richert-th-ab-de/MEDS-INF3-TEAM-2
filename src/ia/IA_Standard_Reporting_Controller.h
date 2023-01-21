#ifndef IA_STANDARD_REPORTING_CONTROLLER_H
#define IA_STANDARD_REPORTING_CONTROLLER_H
#include <string>
#include "AR_UCI_Standard_Reporting_IB.h"

class IA_Standard_Reporting_Controller {
    public:
     public:
        IA_Standard_Reporting_Controller (AR_UCI_Standard_Reporting_IB& uci);
        void control_list_all();
        void control_report_doctor_timeplan();
        void control_report_room_occupancy_plan();

        void control_report_doctor_timeplan_week();
        void control_report_room_occupancy_plan_week();


    private:
        AR_UCI_Standard_Reporting_IB& resource_uci;
        const std::string MESSAGE_CREATE_Standard_Reporting_ID_PROMPT{"Please enter the ID of the room you want to report:\n"};
         const std::string MESSAGE_CREATE_Standard_Reporting_D_ID_PROMPT{"Please enter the ID of the doctor you want to report:\n"};
        const std::string MESSAGE_CREATE_Standard_Reporting_DAY_PROMPT{"Please enter the start day :\n"};
        const std::string MESSAGE_CREATE_Standard_Reporting_MONTH_PROMPT{"Please enter the month :\n"};
        const std::string MESSAGE_CREATE_Standard_Reporting_YEAR_PROMPT{"Please enter the year :\n"}; //+yea 
        const std::string MESSAGE_HEADER{"Standard Reporting Menu:\n"};
};
#endif /* IA_Standard_Reporting_CONTROLLER_H */