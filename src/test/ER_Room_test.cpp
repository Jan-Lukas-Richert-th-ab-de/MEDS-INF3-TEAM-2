#include "doctest.h"
#include "ER_Room.h"

TEST_SUITE_BEGIN("Room");
TEST_CASE("create room, get_id, get_room_description, get_room_number, get_fullname")
{
    ER_Room a_room{"MRT", "1"};
    CHECK(a_room.get_room_id() == 0);
    // CHECK(a_room.get_room_description() == "MRT");
    // CHECK(a_room.get_room_number() == "1");
    CHECK(a_room.get_full_name() == "MRT1");
}
TEST_CASE("create room with id, get_fullname")
{
    ER_Room a_room{1, "CT", "2"};
    CHECK(a_room.get_room_id() == 1);
    CHECK(a_room.get_full_name() == "CT2");
}
TEST_SUITE_END();
