#ifndef FD_DA_APPOINTMENT_REPOSITORY_FILEBASEDIMPL_H
#define FD_DA_APPOINTMENT_REPOSITORY_FILEBASEDIMPL_H
#include "AR_DAI_Appointment_Repository.h"
#include <string>

class FD_DA_Appointment_Repository_FileBasedImpl : public AR_DAI_Appointment_Repository
{
public:
   std::vector<ER_Appointment> find_all();
   ER_Appointment find(unsigned int id);
   ER_Appointment save(const ER_Appointment &appointment);
   void remove(unsigned int id);
   void remove_all();

   // specific to FileBasedImpl, to be used for test setup
   void set_storage_file_name(std::string file_name);

private:
   ER_Appointment create_appointment_from_storage_record(const std::string &line);
   std::string create_storage_record_from_appointment(unsigned int id, const ER_Appointment &appointment);

       std::string storage_file_name{"APPOINTMENT_LIST_APP_DATA.csv"};
       const std::string STORAGE_FILE_HEADER_LINE{"ID,DAY, MONTH, YEAR, TIME_START; TIME"};
};

#endif /* FD_DA_APPOINTMENT_REPOSITORY_FILEBASEDIMPL_H */