#ifndef IA_STANDARD_REPORTING_PRESENTER_H
#define IA_STANDARD_REPORTING_PRESENTER_H
#include "FD_Resource_View.h"
#include "AR_UCI_Standard_Reporting_OB.h"
#include <vector>
#include <map>
#include <string>

class IA_Standard_Reporting_Presenter : public AR_UCI_Standard_Reporting_OB {

    public:
        IA_Standard_Reporting_Presenter(FD_Resource_View& view);
        void present_all(const std::vector<std::map<std::string, std::string>>& data);

        void present_report_room (size_t room);
        void present_report_doctor (size_t doctor);
        void present_report_appointment(size_t appointment);
    

    private:
        FD_Resource_View& resource_view;
};
#endif /* IA_Standard_Reporting_Presenter_H */