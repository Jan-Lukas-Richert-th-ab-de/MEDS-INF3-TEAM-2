#include "FD_DA_Appointment_Repository_FileBasedImpl.h"
#include "FD_general_utility_functions.h"
#include "FD_Text_File_Record_Storage.h"
#include <string>
#include <vector>
#include <iostream>

std::vector<ER_Appointment> FD_DA_Appointment_Repository_FileBasedImpl::find_all()
{
  std::vector<ER_Appointment> appointment_list{};
  std::vector<std::string> record_list{FD_Text_File_Record_Storage::get_all_records_out_of_storage_file(storage_file_name, STORAGE_FILE_HEADER_LINE)};
  for (auto current_record : record_list)
  {
    ER_Appointment current_appointment = create_appointment_from_storage_record(current_record);
    appointment_list.push_back(current_appointment);
  }
  return appointment_list;
};

ER_Appointment FD_DA_Appointment_Repository_FileBasedImpl::find(unsigned int id)
{
  std::string record = FD_Text_File_Record_Storage::get_record_out_of_storage_file(id, storage_file_name, STORAGE_FILE_HEADER_LINE);
  ER_Appointment result = create_appointment_from_storage_record(record);
  return result;
};

ER_Appointment FD_DA_Appointment_Repository_FileBasedImpl::save(const ER_Appointment &appointment)
{
  std::string record{create_storage_record_from_appointment(appointment.get_id(), appointment)};
  std::string updated_record = FD_Text_File_Record_Storage::save_record_to_storage_file(record, storage_file_name, STORAGE_FILE_HEADER_LINE);
  ER_Appointment updated_appointment = create_appointment_from_storage_record(updated_record);
  return updated_appointment;
};

void FD_DA_Appointment_Repository_FileBasedImpl::remove(unsigned int id)
{
  FD_Text_File_Record_Storage::remove_record_from_storage_file(id, storage_file_name, STORAGE_FILE_HEADER_LINE);
};

void FD_DA_Appointment_Repository_FileBasedImpl::remove_all()
{
  FD_Text_File_Record_Storage::remove_storage_file(storage_file_name);
};

// specific to FileBasedImpl, to be used for test setup
void FD_DA_Appointment_Repository_FileBasedImpl::set_storage_file_name(std::string file_name)
{
  storage_file_name = file_name;
};
// speichern als Textdokument
ER_Appointment FD_DA_Appointment_Repository_FileBasedImpl::create_appointment_from_storage_record(const std::string &line)
{
  std::vector<std::string> line_tokens{split(line, ",")}; // Vektor mit string
  unsigned int current_id{static_cast<unsigned int>(stoi(line_tokens.at(0)))};
  std::string found_day{line_tokens.at(1)}; // Line tokens, Reihenfolge
  std::string found_month{line_tokens.at(2)};
  std::string found_year{line_tokens.at(3)};
  std::string found_time_start{line_tokens.at(4)};
  std::string found_time{line_tokens.at(5)};
  std::string found_a_doctor{line_tokens.at(6)};
  std::string found_a_patient{line_tokens.at(7)};
  std::string found_a_room{line_tokens.at(8)};
  FD_DA_Doctor_Repository_FileBasedImpl doctor_repository;
  ER_Doctor result_doctor = doctor_repository.find(static_cast<unsigned int>(stoi(found_a_doctor)));
  FD_DA_Patient_Repository_FileBasedImpl patient_repository;
  ER_Patient result_patient = patient_repository.find(static_cast<unsigned int>(stoi(found_a_patient)));
  FD_DA_Room_Repository_FileBasedImpl room_repository;
  ER_Room result_room = room_repository.find(static_cast<unsigned int>(stoi(found_a_room)));
  ER_Appointment result{current_id, found_day, found_month, found_year, found_time_start, found_time, result_doctor, result_patient, result_room};
  return result;
};

std::string FD_DA_Appointment_Repository_FileBasedImpl::create_storage_record_from_appointment(unsigned int id, const ER_Appointment &appointment)
{
  std::string result{};
  result.append(std::to_string(id));
  result.append(",");
  result.append(appointment.get_day());
  result.append(",");
  result.append(appointment.get_month());
  result.append(",");
  result.append(appointment.get_year());
  result.append(",");
  result.append(appointment.get_time_start());
  result.append(",");
  result.append(appointment.get_time());
  result.append(",");
  result.append(std::to_string(appointment.get_doctor())); // std::string
  result.append(",");
  result.append(std::to_string(appointment.get_patient())); // std::string
  result.append(",");
  result.append(std::to_string(appointment.get_room())); // std::string
  return result;
};
