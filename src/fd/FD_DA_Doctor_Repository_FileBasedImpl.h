#ifndef FD_DA_DOCTOR_REPOSITORY_FILEBASEDIMPL_H
#define FD_DA_DOCTOR_REPOSITORY_FILEBASEDIMPL_H
#include "AR_DAI_Doctor_Repository.h"
#include <string>

class FD_DA_Doctor_Repository_FileBasedImpl : public AR_DAI_Doctor_Repository
{
public:
   std::vector<ER_Doctor> find_all();
   ER_Doctor find(unsigned int id);
   ER_Doctor save(const ER_Doctor &doctor);
   void remove(unsigned int id);
   void remove_all();

   // specific to FileBasedImpl, to be used for test setup
   void set_storage_file_name(std::string file_name);

private:
   ER_Doctor create_doctor_from_storage_record(const std::string &line);
   std::string create_storage_record_from_doctor(unsigned int id, const ER_Doctor &doctor);

   std::string storage_file_name{"DOCTOR_LIST_APP_DATA.csv"};
   const std::string STORAGE_FILE_HEADER_LINE{"ID,FIRST_NAME,LAST_NAME,DOCTORS_SPECIALTIES"};
};

#endif /* FD_DA_DOCTOR_REPOSITORY_FILEBASEDIMPL_H */