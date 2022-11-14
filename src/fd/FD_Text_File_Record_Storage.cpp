#include "FD_Text_File_Record_Storage.h"
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <algorithm>

namespace FD_Text_File_Record_Storage{

void create_storage_file(const std::string& storage_file_name, const std::string& storage_file_header) {
  std::fstream out_file{storage_file_name, std::ios::out};
  if (!out_file.good()) {
        throw std::runtime_error{FD_Text_File_Record_Storage::MESSAGE_FILE_NOT_CREATED};
    }
  out_file << storage_file_header;
};

void remove_storage_file(const std::string& storage_file_name){
  std::filesystem::remove(storage_file_name);
};

void create_storage_file_if_not_existing(const std::string& storage_file_name, const std::string& storage_file_header){
  FD_Text_File_Record_Storage::check_if_file_name_is_empty(storage_file_name);
  bool storage_file_exists = std::filesystem::exists(storage_file_name);
  if(!storage_file_exists){
    FD_Text_File_Record_Storage::create_storage_file(storage_file_name, storage_file_header);
  }
};

unsigned int read_max_id_out_of_storage_file(const std::string& storage_file_name, const std::string& storage_file_header){
  unsigned int max_id{0};
  std::vector<unsigned int> id_list{};
  std::fstream in_file{storage_file_name, std::ios::in};
  check_if_file_can_be_opened(in_file);
  skip_header_line_of_storage_file(in_file, storage_file_header); 
  std::string line{};
  while (in_file.good()) {
    getline(in_file, line);
    unsigned int current_id = get_id_out_of_storage_file_record(line);
    id_list.push_back(current_id);
  }
  if(id_list.size() > 0) {
    max_id = *std::max_element(id_list.begin(), id_list.end());
  }  
  return max_id;
};

void append_record(const std::string& record, const std::string& storage_file_name) {
  std::fstream out_file{storage_file_name, std::ios::app};
  check_if_file_can_be_opened(out_file);
  out_file << '\n';
  out_file << record;
};

void check_if_file_can_be_opened(std::fstream& file){
  if (!file.is_open()) {
    throw std::runtime_error{FD_Text_File_Record_Storage::MESSAGE_FILE_NOT_OPENED};
  }
};

void skip_header_line_of_storage_file(std::fstream& file, const std::string& storage_file_header){
    // skip the first header line and '\n'
  file.seekg(file.beg + std::string{storage_file_header}.size() + 2); 
};

void check_if_file_name_is_empty(const std::string& storage_file_name){
  if (storage_file_name.empty()) { 
    throw std::runtime_error{FD_Text_File_Record_Storage::MESSAGE_FILE_NAME_MISSING}; 
  }
};

unsigned int get_id_out_of_storage_file_record(const std::string& line) {
  unsigned int current_id{0};
  if ( (line.size() > 0) && (line.find(FD_Text_File_Record_Storage::RECORD_ITEM_DELIMETER) != std::string::npos) ) {
    std::size_t first_separator_index = line.find_first_of(FD_Text_File_Record_Storage::RECORD_ITEM_DELIMETER);
    std::string id_string = line.substr(0, first_separator_index);
    current_id = static_cast<unsigned int>(stoi(id_string));
  }
  return current_id;
}

std::string get_all_but_id_out_of_storage_file_record(const std::string& line) {
  std::string result{""};
  if ( (line.size() > 0) && (line.find(FD_Text_File_Record_Storage::RECORD_ITEM_DELIMETER) != std::string::npos) ) {
    std::size_t first_separator_index = line.find_first_of(FD_Text_File_Record_Storage::RECORD_ITEM_DELIMETER);
    result = line.substr(first_separator_index + 1);
  }
  return result;
}

std::string get_record_out_of_storage_file(unsigned int id, const std::string& storage_file_name, const std::string& storage_file_header) {
  std::string result{};
  if(!std::filesystem::exists(storage_file_name))
    return result;
  std::fstream in_file{storage_file_name, std::ios::in};
  FD_Text_File_Record_Storage::check_if_file_can_be_opened(in_file);
  FD_Text_File_Record_Storage::skip_header_line_of_storage_file(in_file, storage_file_header);
  std::string line{};
  bool record_found{false};
  while (in_file.good()) {
    getline(in_file, line);
    unsigned int current_id = FD_Text_File_Record_Storage::get_id_out_of_storage_file_record(line);
    if(current_id == id) {
      record_found = true;
      result = line;
      break;
    }
  }
  if(!record_found){
    throw std::runtime_error{FD_Text_File_Record_Storage::MESSAGE_RECORD_NOT_FOUND};
  }
  return result;
}

std::vector<std::string> get_all_records_out_of_storage_file(const std::string& storage_file_name, const std::string& storage_file_header) {
  std::vector<std::string> record_list{};
  if(!std::filesystem::exists(storage_file_name))
    return record_list;
  std::fstream in_file{storage_file_name, std::ios::in};
  FD_Text_File_Record_Storage::check_if_file_can_be_opened(in_file);
  FD_Text_File_Record_Storage::skip_header_line_of_storage_file(in_file, storage_file_header);
  std::string line{};
  while (in_file.good()) {
    getline(in_file, line);
    if (line != "")
      record_list.push_back(line);
  }
  return record_list;
}; 

void remove_record_from_storage_file(unsigned int id, const std::string& storage_file_name, const std::string& storage_file_header) {
  std::vector<std::string> all_records = get_all_records_out_of_storage_file(storage_file_name, storage_file_header);
  remove_storage_file(storage_file_name);
  create_storage_file(storage_file_name, storage_file_header);
  for(auto current_record : all_records){
    unsigned int current_id = get_id_out_of_storage_file_record(current_record);
    if(current_id != id) {
      append_record(current_record, storage_file_name);
    }
  }
};

std::string save_record_to_storage_file(const std::string& record, const std::string& storage_file_name, const std::string& storage_file_header) {
  create_storage_file_if_not_existing(storage_file_name, storage_file_header);
  unsigned int resulting_id;
  std::string new_record;
  unsigned int current_id = get_id_out_of_storage_file_record(record);
  std::string record_without_id_prefix = get_all_but_id_out_of_storage_file_record(record);
  if(current_id == 0) { // -> a new record has to be saved
    unsigned int maximal_existing_id = read_max_id_out_of_storage_file(storage_file_name, storage_file_header);
    unsigned int new_max_id{maximal_existing_id + 1};
    new_record = (std::to_string(new_max_id)).append(FD_Text_File_Record_Storage::RECORD_ITEM_DELIMETER).append(record_without_id_prefix);
    resulting_id = new_max_id;
  } else { // -> an existing record has to be updated
    remove_record_from_storage_file(current_id, storage_file_name, storage_file_header);
    new_record = (std::to_string(current_id)).append(FD_Text_File_Record_Storage::RECORD_ITEM_DELIMETER).append(record_without_id_prefix);
    resulting_id = current_id;
  }
  append_record(new_record, storage_file_name);
  return new_record;
};


} // namespace FD_Text_File_Record_Storage