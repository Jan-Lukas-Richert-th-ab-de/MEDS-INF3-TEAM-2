#include "doctest.h"
#include "Room/ER_Room.h"
#include "FD_DA_Room_Repository_FileBasedImpl.h"

TEST_SUITE_BEGIN("FD_DA_Room_Repository_FileBasedImpl");
TEST_CASE("save room, find room")
{
    ER_Room a_room{"Maria", "Musterfrau"};
    FD_DA_Room_Repository_FileBasedImpl a_room_repo{};
    a_room_repo.set_storage_file_name("ROOM_LIST_TEST_DATA.txt");
    a_room_repo.remove_all();
    ER_Room a_created_room = a_room_repo.save(a_room);
    ER_Room a_restored_room = a_room_repo.find(a_created_room.get_room_id());
    CHECK(a_restored_room.get_room_id() == a_created_room.get_room_id());
    CHECK(a_restored_room.get_room_description() == "Maria");
    CHECK(a_restored_room.get_room_description() == "Musterfrau");
    a_room_repo.remove_all();
}

TEST_CASE("save two rooms, find second room")
{
    FD_DA_Room_Repository_FileBasedImpl a_room_repo{};
    a_room_repo.set_storage_file_name("ROOM_LIST_TEST_DATA.txt");
    a_room_repo.remove_all();
    ER_Room a_room{"Maria", "Musterfrau"};
    ER_Room a_created_room = a_room_repo.save(a_room);
    ER_Room a_room2{"Max", "Mustermann"};
    ER_Room a_created_room2 = a_room_repo.save(a_room2);

    ER_Room a_restored_room2 = a_room_repo.find(a_created_room2.get_room_id());
    CHECK(a_restored_room2.get_room_id() == a_created_room2.get_room_id());
    a_room_repo.remove_all();
}
TEST_CASE("save three rooms, remove second room, find all")
{
    FD_DA_Room_Repository_FileBasedImpl a_room_repo{};
    a_room_repo.set_storage_file_name("ROOM_LIST_TEST_DATA.txt");
    a_room_repo.remove_all();
    ER_Room a_room{"Maria", "Musterfrau"};
    ER_Room a_created_room = a_room_repo.save(a_room);
    ER_Room a_room2{"Max", "Mustermann"};
    ER_Room a_created_room2 = a_room_repo.save(a_room2);
    ER_Room a_room3{"Eva", "Musterfrau"};
    ER_Room a_created_room3 = a_room_repo.save(a_room3);
    a_room_repo.remove(a_created_room2.get_room_id());
    std::vector<ER_Room> all_stored_rooms = a_room_repo.find_all();
    CHECK(all_stored_rooms.size() == 2);
    CHECK((all_stored_rooms.at(0)).get_room_id() == 1);
    CHECK((all_stored_rooms.at(0)).get_room_description() == "Maria");
    CHECK((all_stored_rooms.at(1)).get_room_id() == 3);
    CHECK((all_stored_rooms.at(1)).get_room_description() == "Eva");
    a_room_repo.remove_all();
}

TEST_CASE("save three rooms, update second room, find all")
{
    FD_DA_Room_Repository_FileBasedImpl a_room_repo{};
    a_room_repo.set_storage_file_name("ROOM_LIST_TEST_DATA.txt");
    a_room_repo.remove_all();
    ER_Room a_room{"Maria", "Musterfrau"};
    ER_Room a_created_room = a_room_repo.save(a_room);
    ER_Room a_room2{"Max", "Mustermann"};
    ER_Room a_created_room2 = a_room_repo.save(a_room2);
    ER_Room a_room3{"Eva", "Musterfrau"};
    ER_Room a_created_room3 = a_room_repo.save(a_room3);
    a_created_room2.set_room_description("Meier");
    ER_Room an_updated_room2 = a_room_repo.save(a_created_room2);
    CHECK(an_updated_room2.get_room_id() == a_created_room2.get_room_id());
    std::vector<ER_Room> all_stored_rooms = a_room_repo.find_all();
    CHECK(all_stored_rooms.size() == 3);
    CHECK((all_stored_rooms.at(0)).get_room_id() == 1);
    CHECK((all_stored_rooms.at(0)).get_room_description() == "Maria");
    CHECK((all_stored_rooms.at(1)).get_room_id() == 3);
    CHECK((all_stored_rooms.at(1)).get_room_description() == "Eva");
    CHECK((all_stored_rooms.at(2)).get_room_id() == 2);
    CHECK((all_stored_rooms.at(2)).get_room_description() == "Max");
    CHECK((all_stored_rooms.at(2)).get_room_description() == "Meier");
    a_room_repo.remove_all();
}

TEST_SUITE_END();