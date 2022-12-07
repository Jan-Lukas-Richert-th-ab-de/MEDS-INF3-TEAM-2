#include "ER_Room.h"

ER_Room::ER_Room(std::string rd, std::string rn)
	: room_description{rd}, room_number{rn} {};

ER_Room::ER_Room(unsigned int id, std::string rd, std::string rn)
	: room_id{id}, room_description{rd}, room_number{rn} {};

unsigned int ER_Room::get_room_id() const
{
	return room_id;
};

std::string ER_Room::get_room_description() const
{
	return room_description;
};

std::string ER_Room::get_room_number() const
{

	return room_number;
};
void ER_Room::set_room_description(std::string rd)
{
	room_description = rd;
};

void ER_Room::set_room_number(std::string rn)
{

	room_number = rn;
}

std::string ER_Room::get_full_name() const
{
	std::string result{""};
	result.append(room_description);
	result.append(" ");
	result.append(room_number);

	return result;
}
