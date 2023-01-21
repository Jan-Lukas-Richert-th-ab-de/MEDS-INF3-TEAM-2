#ifndef AR_UCI_STANDARD_REPORTING_H
#define AR_UCI_STANDARD_REPORTING_H
#include <memory>
#include <vector>
#include <map>
#include <string>
#include "FD_View.h"
#include "AR_DAI_Doctor_Repository.h"
#include "AR_DAI_Appointment_Repository.h"
#include "AR_DAI_Room_Repository.h"
#include "ER_doctor.h"
#include "ER_Room.h"
#include "ER_appointment.h"
#include "AR_UCI_Standard_Reporting_OB.h"
#include "AR_UCI_Standard_Reporting_IB.h"




class AR_UCI_Standard_Reporting : public AR_UCI_Standard_Reporting_IB{
public:
AR_UCI_Standard_Reporting(AR_UCI_Standard_Reporting_OB& presenter,
AR_DAI_Appointment_Repository& appointment_repository,
AR_DAI_Doctor_Repository& doctor_repository,
AR_DAI_Room_Repository& room_repository);
void list_all() override;

void report_doctor_timeplan(unsigned int id, const std::string& day, const std::string& month, const std::string& year)override;
void report_room_occupancy_plan(unsigned int id, const std::string& day, const std::string& month, const std::string& year) override;
void report_doctor_timeplan_week(unsigned int id, const std::string& day, const std::string& month, const std::string& year)override;
void report_room_occupancy_plan_week(unsigned int id, const std::string& day, const std::string& month, const std::string& year) override;


private:
AR_UCI_Standard_Reporting_OB& presenter;
AR_DAI_Doctor_Repository& doctor_repository;
AR_DAI_Room_Repository& room_repository;
AR_DAI_Appointment_Repository& appointment_repository;

};

#endif /* AR_UCI_STANDARD_REPORTING_H */