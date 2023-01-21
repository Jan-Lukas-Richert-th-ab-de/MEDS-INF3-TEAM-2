#ifndef FD_STANDARD_REPORTING_VIEW_H
#define FD_STANDARD_REPORTING_VIEW_H
#include "FD_Resource_View.h"
#include <vector>
#include <map>

class FD_Standard_Reporting_View : public FD_Resource_View_R
{
public:
     void show_list_view(const std::vector<std::map<std::string, std::string>> &data)override;
    void show_view_report_room(const std::vector<std::map<std::string, std::string>> &data)override;
    void show_view_report_doctor(const std::vector<std::map<std::string, std::string>> &data)override;
        void show_view_report_room_week(const std::vector<std::map<std::string, std::string>> &data)override;
    void show_view_report_doctor_week(const std::vector<std::map<std::string, std::string>> &data)override;


private:
    void show_list_empty_message();
};

#endif /* FD_PATIENT_VIEW_H */