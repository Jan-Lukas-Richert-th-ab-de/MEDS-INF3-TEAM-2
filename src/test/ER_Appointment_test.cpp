#include "doctest.h"
#include "ER_Person.h"

TEST_SUITE_BEGIN("Person");
TEST_CASE("create person, get_id, get_fullname") 
{
    ER_Person a_person{"Maria", "Musterfrau"};
    CHECK(a_person.get_id()==0);
    CHECK(a_person.get_full_name()=="Maria Musterfrau");
}
TEST_CASE("create person with id, get_fullname") 
{
    ER_Person a_person{1, "Max", "Mustermann"};
    CHECK(a_person.get_id()==1);
    CHECK(a_person.get_full_name()=="Max Mustermann");
}
TEST_SUITE_END();
