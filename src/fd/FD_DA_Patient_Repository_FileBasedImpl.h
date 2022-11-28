#ifndef FD_DA_PATIENT_REPOSITORY_FILEBASEDIMPL_H
#define FD_DA_PATIENT_REPOSITORY_FILEBASEDIMPL_H
#include "AR_DAI_Patient_Repository.h"
#include <string>

class FD_DA_Patient_Repository_FileBasedImpl : public AR_DAI_Patient_Repository
{
public:
   std::vector<ER_Patient> find_all();
   ER_Patient find(unsigned int id);
   ER_Patient save(const ER_Patient &patient);
   void remove(unsigned int id);
   void remove_all();

   // specific to FileBasedImpl, to be used for test setup
   void set_storage_file_name(std::string file_name);

private:
   ER_Patient create_patient_from_storage_record(const std::string &line);
   std::string create_storage_record_from_patient(unsigned int id, const ER_Patient &patient);

   std::string storage_file_name{"PATIENT_LIST_APP_DATA.csv"};
   const std::string STORAGE_FILE_HEADER_LINE{"ID,FIRST_NAME,LAST_NAME"};
};

#endif /* FD_DA_PATIENT_REPOSITORY_FILEBASEDIMPL_H */