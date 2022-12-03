#include "FD_DA_Doctor_Repository_FileBasedImpl.h"
#include "FD_general_utility_functions.h"
#include "FD_Text_File_Record_Storage.h"
#include <string>
#include <vector>

std::vector<ER_Doctor> FD_DA_Doctor_Repository_FileBasedImpl::find_all()
{
  std::vector<ER_Doctor> doctor_list{};
  std::vector<std::string> record_list{FD_Text_File_Record_Storage::get_all_records_out_of_storage_file(storage_file_name, STORAGE_FILE_HEADER_LINE)};
  for (auto current_record : record_list)
  {
    ER_Doctor current_doctor = create_doctor_from_storage_record(current_record);
    doctor_list.push_back(current_doctor);
  }
  return doctor_list;
};

ER_Doctor FD_DA_Doctor_Repository_FileBasedImpl::find(unsigned int id)
{
  std::string record = FD_Text_File_Record_Storage::get_record_out_of_storage_file(id, storage_file_name, STORAGE_FILE_HEADER_LINE);
  ER_Doctor result = create_doctor_from_storage_record(record);
  return result;
};

ER_Doctor FD_DA_Doctor_Repository_FileBasedImpl::save(const ER_Doctor &doctor)
{
  std::string record{create_storage_record_from_doctor(doctor.get_id(), doctor)};
  std::string updated_record = FD_Text_File_Record_Storage::save_record_to_storage_file(record, storage_file_name, STORAGE_FILE_HEADER_LINE);
  ER_Doctor updated_doctor = create_doctor_from_storage_record(updated_record);
  return updated_doctor;
};

void FD_DA_Doctor_Repository_FileBasedImpl::remove(unsigned int id)
{
  FD_Text_File_Record_Storage::remove_record_from_storage_file(id, storage_file_name, STORAGE_FILE_HEADER_LINE);
};

void FD_DA_Doctor_Repository_FileBasedImpl::remove_all()
{
  FD_Text_File_Record_Storage::remove_storage_file(storage_file_name);
};

// specific to FileBasedImpl, to be used for test setup
void FD_DA_Doctor_Repository_FileBasedImpl::set_storage_file_name(std::string file_name)
{
  storage_file_name = file_name;
};

ER_Doctor FD_DA_Doctor_Repository_FileBasedImpl::create_doctor_from_storage_record(const std::string &line)
{
  std::vector<std::string> line_tokens{split(line, ",")};
  unsigned int current_id{static_cast<unsigned int>(stoi(line_tokens.at(0)))};
  std::string found_first_name{line_tokens.at(1)};
  std::string found_last_name{line_tokens.at(2)};
  std::string found_doctors_specialties{line_tokens.at(3)};
  ER_Doctor result{current_id, found_first_name, found_last_name, found_doctors_specialties};
  return result;
};

std::string FD_DA_Doctor_Repository_FileBasedImpl::create_storage_record_from_doctor(unsigned int id, const ER_Doctor &doctor)
{
  std::string result{};
  result.append(std::to_string(id));
  result.append(",");
  result.append(doctor.get_first_name());
  result.append(",");
  result.append(doctor.get_last_name());
  result.append(",");
  result.append(doctor.get_doctors_specialties());

  return result;
};
