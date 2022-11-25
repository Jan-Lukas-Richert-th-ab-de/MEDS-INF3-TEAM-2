#ifndef AR_UCI_ROOM_ADMINISTRATION_IB_H
#define AR_UCI_ROOM_ADMINISTRATION_IB_H
#include <string>

class AR_UCI_Room_Administration_IB
{
public:
   virtual void list_all() = 0;
   virtual void create(std::string room_description, std::string room_number) = 0;
   virtual void update(unsigned int id, std::string room_description, std::string room_number) = 0;
   virtual void remove(unsigned int id) = 0;

   virtual ~AR_UCI_Room_Administration_IB() = default;
   AR_UCI_Room_Administration_IB() = default;
   AR_UCI_Room_Administration_IB(const AR_UCI_Room_Administration_IB &) = default;
   AR_UCI_Room_Administration_IB &operator=(const AR_UCI_Room_Administration_IB &) = default;
};

#endif /* AR_UCI_ROOM_ADMINISTRATION_IB_H */