#include "AR_UCI_Appointment_Administration.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "ER_Appointment.h"

// A- oder appointmennt;

AR_UCI_Appointment_Administration::AR_UCI_Appointment_Administration(
    AR_UCI_Appointment_Administration_OB &presenter, AR_DAI_Appointment_Repository &repository)
    : resource_presenter(presenter), resource_repository(repository){};

void AR_UCI_Appointment_Administration::list_all()
{
  std::vector<std::map<std::string, std::string>> output_data;
  std::vector<ER_Appointment> all_appointments = resource_repository.find_all();
  sort_appointments_by_id(all_appointments);
  for (auto current_appointment : all_appointments)
  {
    std::map<std::string, std::string> data_map_for_current_appointment =
        get_data_map_for_appointment(current_appointment);
    output_data.push_back(data_map_for_current_appointment);
  }
  resource_presenter.present_all(output_data);
};
void AR_UCI_Appointment_Administration::create(std::string day, std::string month, std::string year)
{
  ER_Appointment a_appointment{day, month, year};
  resource_repository.save(a_appointment);
  list_all();
};
void AR_UCI_Appointment_Administration::update(unsigned int id, std::string day, std::string month, std::string year)
{
  ER_Appointment a_appointment_to_be_updated = resource_repository.find(id);
  a_appointment_to_be_updated.set_day(day);
  a_appointment_to_be_updated.set_month(month);
  a_appointment_to_be_updated.set_year(year);
  resource_repository.save(a_appointment_to_be_updated);
  list_all();
};
void AR_UCI_Appointment_Administration::remove(unsigned int id)
{
  resource_repository.remove(id);
  list_all();
};

std::map<std::string, std::string> AR_UCI_Appointment_Administration::get_data_map_for_appointment(const ER_Appointment &a_appointment)
{
  std::map<std::string, std::string> data_map{};
  data_map.insert({"id", std::to_string(a_appointment.get_id())});
  data_map.insert({"day", a_appointment.get_day()});
  data_map.insert({"month", a_appointment.get_month()});
  data_map.insert({"year", a_appointment.get_year()});
  return data_map;
};

void AR_UCI_Appointment_Administration::sort_appointments_by_id(std::vector<ER_Appointment> &appointment_list)
{
  std::sort(appointment_list.begin(), appointment_list.end(),
            [](ER_Appointment a, ER_Appointment b)
            {
              auto result_a{a.get_id()};
              auto result_b{b.get_id()};
              return (result_a < result_b);
              // the smaller result will be pushed to the beginning
            });
};