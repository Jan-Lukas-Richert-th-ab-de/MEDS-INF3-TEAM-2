#include "FD_DA_Patient_Repository_FileBasedImpl.h"
#include "FD_general_utility_functions.h"
#include "FD_Text_File_Record_Storage.h"
#include <string>
#include <vector>

std::vector<ER_Patient> FD_DA_Patient_Repository_FileBasedImpl::find_all()
{
  std::vector<ER_Patient> patient_list{};
  std::vector<std::string> record_list{FD_Text_File_Record_Storage::get_all_records_out_of_storage_file(storage_file_name, STORAGE_FILE_HEADER_LINE)};
  for (auto current_record : record_list)
  {
    ER_Patient current_patient = create_patient_from_storage_record(current_record);
    patient_list.push_back(current_patient);
  }
  return patient_list;
};

ER_Patient FD_DA_Patient_Repository_FileBasedImpl::find(unsigned int id)
{
  std::string record = FD_Text_File_Record_Storage::get_record_out_of_storage_file(id, storage_file_name, STORAGE_FILE_HEADER_LINE);
  ER_Patient result = create_patient_from_storage_record(record);
  return result;
};

ER_Patient FD_DA_Patient_Repository_FileBasedImpl::save(const ER_Patient &patient)
{
  std::string record{create_storage_record_from_patient(patient.get_id(), patient)};
  std::string updated_record = FD_Text_File_Record_Storage::save_record_to_storage_file(record, storage_file_name, STORAGE_FILE_HEADER_LINE);
  ER_Patient updated_patient = create_patient_from_storage_record(updated_record);
  return updated_patient;
};

void FD_DA_Patient_Repository_FileBasedImpl::remove(unsigned int id)
{
  FD_Text_File_Record_Storage::remove_record_from_storage_file(id, storage_file_name, STORAGE_FILE_HEADER_LINE);
};

void FD_DA_Patient_Repository_FileBasedImpl::remove_all()
{
  FD_Text_File_Record_Storage::remove_storage_file(storage_file_name);
};

// specific to FileBasedImpl, to be used for test setup
void FD_DA_Patient_Repository_FileBasedImpl::set_storage_file_name(std::string file_name)
{
  storage_file_name = file_name;
};

ER_Patient FD_DA_Patient_Repository_FileBasedImpl::create_patient_from_storage_record(const std::string &line)
{
  std::vector<std::string> line_tokens{split(line, ",")};
  unsigned int current_id{static_cast<unsigned int>(stoi(line_tokens.at(0)))};
  std::string found_first_name{line_tokens.at(1)};
  std::string found_last_name{line_tokens.at(2)};
  ER_Patient result{current_id, found_first_name, found_last_name};
  return result;
};

std::string FD_DA_Patient_Repository_FileBasedImpl::create_storage_record_from_patient(unsigned int id, const ER_Patient &patient)
{
  std::string result{};
  result.append(std::to_string(id));
  result.append(",");
  result.append(patient.get_first_name());
  result.append(",");
  result.append(patient.get_last_name());
  return result;
};
