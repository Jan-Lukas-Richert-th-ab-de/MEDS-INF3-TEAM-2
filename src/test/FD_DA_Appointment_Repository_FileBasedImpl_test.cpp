#include "doctest.h"
#include "ER_Person.h"
#include "FD_DA_Person_Repository_FileBasedImpl.h"

TEST_SUITE_BEGIN("FD_DA_Person_Repository_FileBasedImpl");
TEST_CASE("save person, find person") 
{
    ER_Person a_person{"Maria", "Musterfrau"};
    FD_DA_Person_Repository_FileBasedImpl a_person_repo{};
    a_person_repo.set_storage_file_name("PERSON_LIST_TEST_DATA.txt");
    a_person_repo.remove_all();
    ER_Person a_created_person = a_person_repo.save(a_person);
    ER_Person a_restored_person = a_person_repo.find(a_created_person.get_id());
    CHECK(a_restored_person.get_id()== a_created_person.get_id());
    CHECK(a_restored_person.get_first_name()=="Maria");
    CHECK(a_restored_person.get_last_name()=="Musterfrau");
    a_person_repo.remove_all();
}

TEST_CASE("save two persons, find second person") 
{
    FD_DA_Person_Repository_FileBasedImpl a_person_repo{};
    a_person_repo.set_storage_file_name("PERSON_LIST_TEST_DATA.txt");
    a_person_repo.remove_all();
    ER_Person a_person{"Maria", "Musterfrau"};
    ER_Person a_created_person = a_person_repo.save(a_person);
    ER_Person a_person2{"Max", "Mustermann"};
    ER_Person a_created_person2 = a_person_repo.save(a_person2);

    ER_Person a_restored_person2 = a_person_repo.find(a_created_person2.get_id());
    CHECK(a_restored_person2.get_id()==a_created_person2.get_id());
    a_person_repo.remove_all();
}
TEST_CASE("save three persons, remove second person, find all") 
{
    FD_DA_Person_Repository_FileBasedImpl a_person_repo{};
    a_person_repo.set_storage_file_name("PERSON_LIST_TEST_DATA.txt");
    a_person_repo.remove_all();
    ER_Person a_person{"Maria", "Musterfrau"};
    ER_Person a_created_person = a_person_repo.save(a_person);
    ER_Person a_person2{"Max", "Mustermann"};
    ER_Person a_created_person2 = a_person_repo.save(a_person2);
    ER_Person a_person3{"Eva", "Musterfrau"};
    ER_Person a_created_person3 = a_person_repo.save(a_person3);
    a_person_repo.remove(a_created_person2.get_id());
    std::vector<ER_Person> all_stored_persons = a_person_repo.find_all();
    CHECK(all_stored_persons.size()==2);
    CHECK((all_stored_persons.at(0)).get_id() == 1);
    CHECK((all_stored_persons.at(0)).get_first_name() == "Maria");
    CHECK((all_stored_persons.at(1)).get_id() == 3);
    CHECK((all_stored_persons.at(1)).get_first_name() == "Eva");
    a_person_repo.remove_all();
}

TEST_CASE("save three persons, update second person, find all") 
{
    FD_DA_Person_Repository_FileBasedImpl a_person_repo{};
    a_person_repo.set_storage_file_name("PERSON_LIST_TEST_DATA.txt");
    a_person_repo.remove_all();
    ER_Person a_person{"Maria", "Musterfrau"};
    ER_Person a_created_person = a_person_repo.save(a_person);
    ER_Person a_person2{"Max", "Mustermann"};
    ER_Person a_created_person2 = a_person_repo.save(a_person2);
    ER_Person a_person3{"Eva", "Musterfrau"};
    ER_Person a_created_person3 = a_person_repo.save(a_person3);
    a_created_person2.set_last_name("Meier");
    ER_Person  an_updated_person2 = a_person_repo.save(a_created_person2);
    CHECK(an_updated_person2.get_id() == a_created_person2.get_id());
    std::vector<ER_Person> all_stored_persons = a_person_repo.find_all();
    CHECK(all_stored_persons.size()==3);
    CHECK((all_stored_persons.at(0)).get_id() == 1);
    CHECK((all_stored_persons.at(0)).get_first_name() == "Maria");
    CHECK((all_stored_persons.at(1)).get_id() == 3);
    CHECK((all_stored_persons.at(1)).get_first_name() == "Eva");
    CHECK((all_stored_persons.at(2)).get_id() == 2);
    CHECK((all_stored_persons.at(2)).get_first_name() == "Max");
    CHECK((all_stored_persons.at(2)).get_last_name() == "Meier");
    a_person_repo.remove_all();
}

TEST_SUITE_END();