#ifndef AR_DAI_ROOM_REPOSITORY_H
#define AR_DAI_ROOM_REPOSITORY_H
#include <vector>
#include "ER_Room.h"

class AR_DAI_Room_Repository
{
public:
   virtual std::vector<ER_Room> find_all() = 0;
   virtual ER_Room find(unsigned int id) = 0;
   virtual ER_Room save(const ER_Room &room) = 0;
   virtual void remove(unsigned int id) = 0;
   virtual void remove_all() = 0;

   virtual ~AR_DAI_Room_Repository() = default;
   AR_DAI_Room_Repository() = default;
   AR_DAI_Room_Repository(const AR_DAI_Room_Repository &) = default;
   AR_DAI_Room_Repository &operator=(const AR_DAI_Room_Repository &) = default;
};

#endif /* AR_DAI_ROOM_REPOSITORY_H */