#ifndef AR_UCI_SUMMARY_STATISTICS_CREATION_H
#define AR_UCI_SUMMARY_STATISTICS_CREATION_H

#include "FD_Resource_View.h"
#include "AR_UCI_Summary_Statistics_Creation_IB.h"
#include "AR_UCI_Summary_Statistics_Creation_OB.h"
#include "AR_DAI_Doctor_Repository.h"
#include "AR_DAI_Appointment_Repository.h"
#include "AR_DAI_Room_Repository.h"
#include <vector>
#include <map>
#include <string>
#include "ER_doctor.h"
#include "ER_Room.h"
#include "ER_appointment.h"
#include <memory>
#include <iostream>
#include <numeric> // für accumulate

class AR_UCI_Summary_Statistics_Creation : public AR_UCI_Summary_Statistics_Creation_IB {
public:
AR_UCI_Summary_Statistics_Creation(
AR_UCI_Summary_Statistics_Creation_OB& presenter,
AR_DAI_Appointment_Repository& appointment_repository,
AR_DAI_Doctor_Repository& doctor_repository,
AR_DAI_Room_Repository& room_repository);

void list_all() override;
void report_doctor_Summary_Statistics(unsigned int id, const std::string& day, const std::string& month, const std::string& year)  override ;
void report_room_occupancy_Summary_Statistics(unsigned int id, const std::string& day, const std::string& month, const std::string& year) override;
void report_doctor_Summary_Statistics_pre_week(unsigned int id, const std::string& day, const std::string& month, const std::string& year)  override ;
void report_room_occupancy_Summary_Statistics_pre_week(unsigned int id, const std::string& day, const std::string& month, const std::string& year) override;

private:


AR_UCI_Summary_Statistics_Creation_OB& presenter;
AR_DAI_Appointment_Repository& appointment_repository;
AR_DAI_Doctor_Repository& doctor_repository;
AR_DAI_Room_Repository& room_repository;
};

#endif