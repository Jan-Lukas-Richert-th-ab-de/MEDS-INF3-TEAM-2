#ifndef FD_DA_PERSON_REPOSITORY_FILEBASEDIMPL_H
#define FD_DA_PERSON_REPOSITORY_FILEBASEDIMPL_H
#include "AR_DAI_Person_Repository.h"
#include <string>

class FD_DA_Person_Repository_FileBasedImpl : public AR_DAI_Person_Repository {
   public:
       std::vector<ER_Person> find_all(); 
       ER_Person find(unsigned int id);
       ER_Person save(const ER_Person& person);
       void remove(unsigned int id);
       void remove_all();

       //specific to FileBasedImpl, to be used for test setup
       void set_storage_file_name(std::string file_name);

    private:
       ER_Person create_person_from_storage_record(const std::string& line);
       std::string create_storage_record_from_person(unsigned int id, const ER_Person& person);

       std::string storage_file_name{"PERSON_LIST_APP_DATA.csv"};
       const std::string STORAGE_FILE_HEADER_LINE{"ID,FIRST_NAME,LAST_NAME"};
};

#endif /* FD_DA_PERSON_REPOSITORY_FILEBASEDIMPL_H */