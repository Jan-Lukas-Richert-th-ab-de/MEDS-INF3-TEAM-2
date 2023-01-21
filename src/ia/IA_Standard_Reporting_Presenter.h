#ifndef IA_STANDARD_REPORTING_PRESENTER_H
#define IA_STANDARD_REPORTING_PRESENTER_H
#include "FD_Resource_View.h"
#include "AR_UCI_Standard_Reporting_OB.h"
#include <vector>
#include <map>
#include <string>

class IA_Standard_Reporting_Presenter : public AR_UCI_Standard_Reporting_OB {

        private:
        FD_Resource_View_R &resource_view_R;
         void present_all(const std::vector<std::map<std::string, std::string>>& data)override;

         void present_report_doctor_time_plan(const std::vector<std::map<std::string, std::string>>& data) override;
         void present_report_room_occupancy_plan(const std::vector<std::map<std::string, std::string>>& data) override;
                  void present_report_doctor_time_plan_week(const std::vector<std::map<std::string, std::string>>& data) override;
         void present_report_room_occupancy_plan_week(const std::vector<std::map<std::string, std::string>>& data) override; 


    public:
        IA_Standard_Reporting_Presenter(FD_Resource_View_R& view_R) : resource_view_R(view_R) {};
};
#endif /* IA_Standard_Reporting_Presenter_H */