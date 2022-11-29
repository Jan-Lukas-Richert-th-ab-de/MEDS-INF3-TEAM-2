#include "doctest.h"
#include "Room/ER_Room.h"

TEST_SUITE_BEGIN("Room");
TEST_CASE("create room, get_id, get_fullname")
{
    ER_Room a_room{"Maria", "Musterfrau"};
    CHECK(a_room.get_room_id() == 0);
    CHECK(a_room.get_full_name() == "Maria Musterfrau");
}
TEST_CASE("create room with id, get_fullname")
{
    ER_Room a_room{1, "Max", "Mustermann"};
    CHECK(a_room.get_room_id() == 1);
    CHECK(a_room.get_full_name() == "Max Mustermann");
}
TEST_SUITE_END();
