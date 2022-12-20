/*#ifndef AR_SUMMARY_STATISTICS_H
#define AR_SUMMARY_STATISTICS_H

#include <vector>
#include <map>
#include <string>
#include "ER_appointment.h"
#include "ER_doctor.h"
#include "ER_Room.h"
#include <memory>


class AR_Summary_Statistics
{
public:

  virtual std::map<std::string, double> get_average_room_occupancy(const std::vector<ER_Appointment>& appointments, const std::vector<ER_Room>& rooms, const std::string& week) = 0;

  virtual std::map<std::string, double> get_average_doctor_utilization(const std::vector<ER_Appointment>& appointments, const std::vector<ER_Doctor>& doctors, const std::string& week) = 0;

  virtual ~AR_Summary_Statistics() = default;
  AR_Summary_Statistics() = default;
  AR_Summary_Statistics(const AR_Summary_Statistics &) = default;
  AR_Summary_Statistics &operator=(const AR_Summary_Statistics &) = default;
   static std::unique_ptr<AR_Summary_Statistics> create();
};
#endif /* AR_SUMMARY_STATISTICS_H */
