#include "AR_UCI_Appointment_Administration.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "ER_Appointment.h"

// A- oder appointmennt;

AR_UCI_Appointment_Administration::AR_UCI_Appointment_Administration(
    AR_UCI_Appointment_Administration_OB &presenter, AR_DAI_Appointment_Repository &repository, AR_DAI_Doctor_Repository &doctor_repository, AR_DAI_Patient_Repository &patient_repository, AR_DAI_Room_Repository &room_repository)
    : resource_presenter(presenter), resource_repository(repository), resource_repository_doctor(doctor_repository), resource_repository_patient(patient_repository), resource_repository_room(room_repository){};

void AR_UCI_Appointment_Administration::list_all() // Auflisten
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
void AR_UCI_Appointment_Administration::list_all_data() // Auflisten
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
void AR_UCI_Appointment_Administration::create(std::string day, std::string month, std::string year, std::string time_start, std::string time, unsigned int doctor_id, unsigned int patient_id, unsigned int room_id) // Hinzufügen
{
  ER_Doctor found_doctor = resource_repository_doctor.find(doctor_id);
  ER_Patient found_patient = resource_repository_patient.find(patient_id);
  ER_Room found_room = resource_repository_room.find(room_id);
  ER_Appointment a_appointment{day, month, year, time_start, time, found_doctor, found_patient, found_room};
  resource_repository.save(a_appointment);
  list_all();
};
void AR_UCI_Appointment_Administration::update(unsigned int id, std::string day, std::string month, std::string year, std::string time_start, std::string time, unsigned int doctor_id, unsigned int patient_id, unsigned int room_id) // Bearbeiten
{
  ER_Appointment a_appointment_to_be_updated = resource_repository.find(id);
  a_appointment_to_be_updated.set_day(day);
  a_appointment_to_be_updated.set_month(month);
  a_appointment_to_be_updated.set_year(year);
  a_appointment_to_be_updated.set_time_start(time_start);
  a_appointment_to_be_updated.set_time(time);
  ER_Doctor found_doctor = resource_repository_doctor.find(doctor_id);
  a_appointment_to_be_updated.set_doctor(found_doctor);
  ER_Patient found_patient = resource_repository_patient.find(patient_id);
  a_appointment_to_be_updated.set_patient(found_patient);
  ER_Room found_room = resource_repository_room.find(room_id);
  a_appointment_to_be_updated.set_room(found_room);

  resource_repository.save(a_appointment_to_be_updated);
  list_all();
};
void AR_UCI_Appointment_Administration::remove(unsigned int id) // Löschen
{
  resource_repository.remove(id);
  list_all();
};

std::map<std::string, std::string> AR_UCI_Appointment_Administration::get_data_map_for_appointment(const ER_Appointment &a_appointment) // Map
{
  std::map<std::string, std::string> data_map{};
  data_map.insert({"id", std::to_string(a_appointment.get_id())});
  data_map.insert({"day", a_appointment.get_day()});
  data_map.insert({"month", a_appointment.get_month()});
  data_map.insert({"year", a_appointment.get_year()});
  data_map.insert({"time_start", a_appointment.get_time_start()});
  data_map.insert({"time", a_appointment.get_time()});
  data_map.insert({"doctor", std::to_string(a_appointment.get_doctor())}); ////std::string
  data_map.insert({"patient", std::to_string(a_appointment.get_patient())});
  data_map.insert({"room", std::to_string(a_appointment.get_room())});

  return data_map;
};

void AR_UCI_Appointment_Administration::sort_appointments_by_id(std::vector<ER_Appointment> &appointment_list) // ID-Sortierung
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