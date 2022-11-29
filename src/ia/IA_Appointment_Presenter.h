#ifndef IA_APPOINTMENT_PRESENTER_H
#define IA_APPOINTMENT_PRESENTER_H
#include "FD_Resource_View.h"
#include "AR_UCI_Appointment_Administration_OB.h"
#include <vector>
#include <map>

class IA_Appointment_Presenter : public AR_UCI_Appointment_Administration_OB {
    public:
        IA_Appointment_Presenter(FD_Resource_View& view);
        void present_all(const std::vector<std::map<std::string, std::string>>& data);
    private:
        FD_Resource_View& resource_view;
};
#endif /* IA_APPOINTMENT_PRESENTER_H */