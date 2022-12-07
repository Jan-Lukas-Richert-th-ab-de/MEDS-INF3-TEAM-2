#ifndef AR_UCI_APPOINTMENT_ADMINISTRATION_H
#define AR_UCI_APPOINTMENT_ADMINISTRATION_H
#include "FD_Resource_View.h"
#include "AR_UCI_Appointment_Administration_IB.h"
#include "AR_UCI_Appointment_Administration_OB.h"
#include "AR_DAI_Appointment_Repository.h"

class AR_UCI_Appointment_Administration : public AR_UCI_Appointment_Administration_IB {
    public:
        AR_UCI_Appointment_Administration(
            AR_UCI_Appointment_Administration_OB& presenter
          , AR_DAI_Appointment_Repository& repository);
        void list_all();
        void create(std::string day, std::string month, std::string year, std::string time_start, std::string time);
        void update(unsigned int id, std::string day, std::string month, std::string year, std::string time_start, std::string time);
        void remove(unsigned int id);
    private:
        AR_UCI_Appointment_Administration_OB& resource_presenter;
        AR_DAI_Appointment_Repository& resource_repository;
        std::map<std::string, std::string> get_data_map_for_appointment(const ER_Appointment& a_appointment);
        void sort_appointments_by_id (std::vector<ER_Appointment>& appointment_list);
};
#endif /* AR_UCI_APPOINTMENT_ADMINISTRATION_H */