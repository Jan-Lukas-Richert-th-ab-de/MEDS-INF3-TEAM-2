#ifndef AR_UCI_APPOINTMENT_ADMINISTRATION_H
#define AR_UCI_APPOINTMENT_ADMINISTRATION_H
#include "FD_Resource_View.h"
#include "AR_UCI_Appointment_Administration_IB.h"
#include "AR_UCI_Appointment_Administration_OB.h"
#include "AR_DAI_Appointment_Repository.h"
#include "AR_DAI_Doctor_Repository.h"
#include "AR_DAI_Patient_Repository.h"
#include "AR_DAI_Room_Repository.h"

class AR_UCI_Appointment_Administration : public AR_UCI_Appointment_Administration_IB
{
public:
    AR_UCI_Appointment_Administration(
        AR_UCI_Appointment_Administration_OB &presenter, AR_DAI_Appointment_Repository &repository, AR_DAI_Doctor_Repository &doctor_repository, AR_DAI_Patient_Repository &patient_repository, AR_DAI_Room_Repository &room_repository);
    void list_all();
    void create(std::string day, std::string month, std::string year, std::string time_start, std::string time, unsigned int doctor_id, unsigned int patient_id, unsigned int room_id);
    void update(unsigned int id, std::string day, std::string month, std::string year, std::string time_start, std::string time, unsigned int doctor_id, unsigned int patient_id, unsigned int room_id);
    void remove(unsigned int id);

private:
    AR_UCI_Appointment_Administration_OB &resource_presenter;
    AR_DAI_Appointment_Repository &resource_repository;
    AR_DAI_Doctor_Repository &resource_repository_doctor;
    AR_DAI_Patient_Repository &resource_repository_patient;
    AR_DAI_Room_Repository &resource_repository_room;
    std::map<std::string, std::string> get_data_map_for_appointment(const ER_Appointment &a_appointment);
    void sort_appointments_by_id(std::vector<ER_Appointment> &appointment_list);
};
#endif /* AR_UCI_APPOINTMENT_ADMINISTRATION_H */