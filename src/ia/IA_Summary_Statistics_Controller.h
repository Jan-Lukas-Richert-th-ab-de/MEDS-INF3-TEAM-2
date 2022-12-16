#ifndef IA_SUMMARY_STATISTICS_CONTROLLER_H
#define IA_SUMMARY_STATISTICS_CONTROLLER_H
#include <string>
#include "AR_UCI_Summary_Statistics_Administration_IB.h"

class IA_Summary_Statistics_Controller {
    public:
        IA_Summary_Statistics_Controller (AR_UCI_Summary_Statistics_Administration_IB& uci);
        void control_list_all();
        void control_update();


    private:
        AR_UCI_Summary_Statistics_Administration_IB& resource_uci;
         const std::string MESSAGE_CREATE_Summary_Statistics_ID_PROMPT{"Please enter the ID of the room or doctor you want to report:\n"};
        const std::string MESSAGE_CREATE_Summary_Statistics_DAY_PROMPT{"Please enter the start day of the report weck:\n"};
        const std::string MESSAGE_CREATE_Summary_Statistics_MONTH_PROMPT{"Please enter the month of the report weck:\n"};
        const std::string MESSAGE_CREATE_Summary_Statistics_YEAR_PROMPT{"Please enter the year of the report weck:\n"}; //+yea 
};
#endif /* IA_APPOINTMENT_CONTROLLER_H */

