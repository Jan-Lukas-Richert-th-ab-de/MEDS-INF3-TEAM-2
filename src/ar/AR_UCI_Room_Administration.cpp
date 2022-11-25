#include "AR_UCI_Room_Administration.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "ER_Room.h"

AR_UCI_Room_Administration::AR_UCI_Room_Administration(
    AR_UCI_Room_Administration_OB &presenter, AR_DAI_Room_Repository &repository)
    : resource_presenter(presenter), resource_repository(repository){};

void AR_UCI_Room_Administration::list_all()
{
  std::vector<std::map<std::string, std::string>> output_data;
  std::vector<ER_Room> all_rooms = resource_repository.find_all();
  sort_rooms_by_id(all_rooms);
  for (auto current_room : all_rooms)
  {
    std::map<std::string, std::string> data_map_for_current_room =
        get_data_map_for_room(current_room);
    output_data.push_back(data_map_for_current_room);
  }
  resource_presenter.present_all(output_data);
};
void AR_UCI_Room_Administration::create(std::string room_description, std::string room_number)
{
  ER_Room a_room{room_description, room_number};
  resource_repository.save(a_room);
  list_all();
};
void AR_UCI_Room_Administration::update(unsigned int id, std::string room_description, std::string room_number)
{
  ER_Room a_room_to_be_updated = resource_repository.find(id);
  a_room_to_be_updated.set_room_description(room_description);
  a_room_to_be_updated.set_room_number(room_number);
  resource_repository.save(a_room_to_be_updated);
  list_all();
};
void AR_UCI_Room_Administration::remove(unsigned int id)
{
  resource_repository.remove(id);
  list_all();
};

std::map<std::string, std::string> AR_UCI_Room_Administration::get_data_map_for_room(const ER_Room &a_room)
{
  std::map<std::string, std::string> data_map{};
  data_map.insert({"id", std::to_string(a_room.get_room_id())});
  data_map.insert({"room_description", a_room.get_room_description()});
  data_map.insert({"room_number", a_room.get_room_number()});
  return data_map;
};

void AR_UCI_Room_Administration::sort_rooms_by_id(std::vector<ER_Room> &room_list)
{
  std::sort(room_list.begin(), room_list.end(),
            [](ER_Room a, ER_Room b)
            {
              auto result_a{a.get_room_id()};
              auto result_b{b.get_room_id()};
              return (result_a < result_b);
              // the smaller result will be pushed to the beginning
            });
};