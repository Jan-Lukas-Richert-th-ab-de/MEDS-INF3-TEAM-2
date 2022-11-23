#include "ER_Room.h"

ER_Room::ER_Room(std::string rn)
	: room_name{rn} {};

ER_Room::ER_Room(unsigned int rid, std::string rn)
	: room_id{rid}, room_name{rn} {};

unsigned int ER_Room::get_room_id() const
{
	return room_id;
};

std::string ER_Room::get_room_name() const
{
	return room_name;
};
void ER_Room::set_room_name(std::string rn)
{
	room_name = rn;
};

std::string ER_Room::get_full_name() const
{
	std::string result{""};
	result.append(room_name);

	return result;
}
