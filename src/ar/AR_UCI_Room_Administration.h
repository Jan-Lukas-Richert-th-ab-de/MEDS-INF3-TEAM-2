#ifndef AR_UCI_ROOM_ADMINISTRATION_H
#define AR_UCI_ROOM_ADMINISTRATION_H
#include "FD_Resource_View.h"
#include "AR_UCI_Room_Administration_IB.h"
#include "AR_UCI_Room_Administration_OB.h"
#include "AR_DAI_Room_Repository.h"

class AR_UCI_Room_Administration : public AR_UCI_Room_Administration_IB
{
public:
    AR_UCI_Room_Administration(
        AR_UCI_Room_Administration_OB &presenter, AR_DAI_Room_Repository &repository);
    void list_all();
    void create(std::string room_description, std::string room_number);
    void update(unsigned int id, std::string room_description, std::string room_number);
    void remove(unsigned int id);

private:
    AR_UCI_Room_Administration_OB &resource_presenter;
    AR_DAI_Room_Repository &resource_repository;
    std::map<std::string, std::string> get_data_map_for_room(const ER_Room &a_room);
    void sort_rooms_by_id(std::vector<ER_Room> &room_list);
};
#endif /* AR_UCI_ROOM_ADMINISTRATION_H */