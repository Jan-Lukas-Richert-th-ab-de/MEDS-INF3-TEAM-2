#ifndef IA_SUMMARY_STATISTICS_CONTROLLER_H
#define IA_SUMMARY_STATISTICS_CONTROLLER_H
#include <string>
#include "AR_UCI_Summary_Statistics_Creation_IB.h"

class IA_Summary_Statistics_Controller {
    public:
        IA_Summary_Statistics_Controller (AR_UCI_Summary_Statistics_Creation_IB& uci);
        void control_list_all();
        void control_report_doctor_Summary_Statistics();
        void control_report_room_occupancy_Summary_Statistics();
         void control_report_doctor_Summary_Statistics_per_week();
        void control_report_room_occupancy_Summary_Statistics_per_week();



    private:
        AR_UCI_Summary_Statistics_Creation_IB& resource_uci;
        const std::string MESSAGE_CREATE_Summary_Statistics_ID_PROMPT{"Please enter the ID of the room :\n"};
         const std::string MESSAGE_CREATE_Summary_Statistics_D_ID_PROMPT{"Please enter the ID of the doctor :\n"};
                 const std::string MESSAGE_CREATE_Summary_Statistics_DATE_PROMPT{"Please Enter start date [DD MM YYYY] for statistics breakdown (don't forget the spaces!): \n"};

/*        const std::string MESSAGE_CREATE_Summary_Statistics_DAY_PROMPT{"Please enter the  day :\n"};
        const std::string MESSAGE_CREATE_Summary_Statistics_MONTH_PROMPT{"Please enter the month :\n"};
        const std::string MESSAGE_CREATE_Summary_Statistics_YEAR_PROMPT{"Please enter the year :\n"}; //+yea 
*/};
#endif /* IA_SUMMARY_STATISTICS_CONTROLLER_H */

