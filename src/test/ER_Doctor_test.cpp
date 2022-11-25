#include "doctest.h"
#include "ER_Doctor.h"

TEST_SUITE_BEGIN("Doctor");
TEST_CASE("create doctor, get_id, get_fullname")
{
    ER_Doctor a_doctor{"Maria", "Musterfrau", "tester"};
    CHECK(a_doctor.get_id() == 0);
    CHECK(a_doctor.get_full_name() == "Maria Musterfrau tester");
}
TEST_CASE("create doctor with id, get_fullname")
{
    ER_Doctor a_doctor{1, "Max", "Mustermann", "tester"};
    CHECK(a_doctor.get_id() == 1);
    CHECK(a_doctor.get_full_name() == "Max Mustermann");
    CHECK(a_doctor.get_doctors_specialties() == "tester");
}
TEST_SUITE_END();
