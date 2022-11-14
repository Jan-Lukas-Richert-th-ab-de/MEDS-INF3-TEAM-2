#ifndef FD_TEXT_FILE_RECORD_STORAGE_H
#define FD_TEXT_FILE_RECORD_STORAGE_H

#include <string>
#include <vector>
#include <fstream>

namespace FD_Text_File_Record_Storage {
       void create_storage_file(const std::string& storage_file_name, const std::string& storage_file_header);
       void remove_storage_file(const std::string& storage_file_name);
       void create_storage_file_if_not_existing(const std::string& storage_file_name, const std::string& storage_file_header);
       unsigned int read_max_id_out_of_storage_file(const std::string& storage_file_name, const std::string& storage_file_header);
       void append_record(const std::string& record, const std::string& storage_file_name);
       void check_if_file_can_be_opened(std::fstream& file);
       void skip_header_line_of_storage_file(std::fstream& file, const std::string& storage_file_header);
       void check_if_file_name_is_empty(const std::string& storage_file_name);
       unsigned int get_id_out_of_storage_file_record(const std::string& line);
       std::string get_all_but_id_out_of_storage_file_record(const std::string& line);
       std::string get_record_out_of_storage_file(unsigned int id, const std::string& storage_file_name, const std::string& storage_file_header); 
       std::vector<std::string> get_all_records_out_of_storage_file(const std::string& storage_file_name, const std::string& storage_file_header);
       void remove_record_from_storage_file(unsigned int id, const std::string& storage_file_name, const std::string& storage_file_header);
       std::string save_record_to_storage_file(const std::string& record, const std::string& storage_file_name, const std::string& storage_file_header);
       
       const std::string MESSAGE_FILE_NOT_OPENED   {"Data Storage: data file cannot be opened."};
       const std::string MESSAGE_FILE_NAME_MISSING {"Data Storage: name of data file is missing."};
       const std::string MESSAGE_FILE_NOT_CREATED  {"Data Storage: data file cannot be created."};
       const std::string MESSAGE_RECORD_NOT_FOUND  {"Data Storage: searched record was not found."};
       const std::string RECORD_ITEM_DELIMETER  {","};
}

#endif /* FD_TEXT_FILE_RECORD_STORAGE_H */