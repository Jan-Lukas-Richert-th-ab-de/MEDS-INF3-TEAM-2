#ifndef AR_UCI_SUMMARY_STATISTICS_Creation_H
#define AR_UCI_SUMMARY_STATISTICS_Creation_H
#include "FD_Resource_View.h"
#include "AR_UCI_Summary_Statistics_Creation_IB.h"
#include "AR_UCI_Summary_Statistics_Creation_OB.h"
#include "AR_DAI_Doctor_Repository.h"
#include "AR_DAI_Appointment_Repository.h"
#include "AR_DAI_Room_Repository.h"
#include <vector>
#include <map>
#include <string>
#include "ER_Doctor.h"
#include "ER_Room.h"
#include "ER_Appointment.h"
#include <memory>

class AR_UCI_Summary_Statistics_Creation : public AR_UCI_Summary_Statistics_Creation_IB {
public:
AR_UCI_Summary_Statistics_Creation(
AR_UCI_Summary_Statistics_Creation_OB& presenter,
AR_DAI_Appointment_Repository& appointment_repository,
AR_DAI_Doctor_Repository& doctor_repository,
AR_DAI_Room_Repository& room_repository);

void list_all() override;
void report_room_occupancy_Summary_Statistics(unsigned int id, std::string day, std::string month, std::string year) override;
void report_doctor_Summary_Statistics(unsigned int id, std::string day, std::string month, std::string year) override;

private:
AR_UCI_Summary_Statistics_Creation_OB& resource_presenter;
AR_DAI_Doctor_Repository& doctor_resource_repository;
AR_DAI_Room_Repository& room_resource_repository;
AR_DAI_Appointment_Repository& appointment_resource_repository;

std::map<std::string, double> get_average_room_occupancy(
const std::vector<ER_Appointment>& appointments,
const std::vector<ER_Room>& rooms,
const std::string& week);
std::map<std::string, double> get_doctor_statistics(
const std::vector<ER_Appointment>& appointments,
const std::vector<ER_Doctor>& doctors,
const std::string& week);
};
#endif