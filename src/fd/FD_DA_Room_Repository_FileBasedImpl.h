#ifndef FD_DA_ROOM_REPOSITORY_FILEBASEDIMPL_H
#define FD_DA_ROOM_REPOSITORY_FILEBASEDIMPL_H
#include "AR_DAI_Room_Repository.h"
#include <string>

class FD_DA_Room_Repository_FileBasedImpl : public AR_DAI_Room_Repository
{
public:
   std::vector<ER_Room> find_all();
   ER_Room find(unsigned int id);
   ER_Room save(const ER_Room &room);
   void remove(unsigned int id);
   void remove_all();

   // specific to FileBasedImpl, to be used for test setup
   void set_storage_file_name(std::string file_name);

private:
   ER_Room create_room_from_storage_record(const std::string &line);
   std::string create_storage_record_from_room(unsigned int id, const ER_Room &room);

   std::string storage_file_name{"ROOM_LIST_APP_DATA.csv"};
   const std::string STORAGE_FILE_HEADER_LINE{"ID,FIRST_NAME,LAST_NAME"};
};

#endif /* FD_DA_ROOM_REPOSITORY_FILEBASEDIMPL_H */