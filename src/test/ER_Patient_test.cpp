#include "doctest.h"
#include "ER_Patient.h"

TEST_SUITE_BEGIN("Patient");
TEST_CASE("create patient, get_id, get_fullname")
{
    ER_Patient a_patient{"Maria", "Musterfrau"};
    CHECK(a_patient.get_id() == 0);
    CHECK(a_patient.get_full_name() == "Maria Musterfrau");
}
TEST_CASE("create patient with id, get_fullname")
{
    ER_Patient a_patient{1, "Max", "Mustermann"};
    CHECK(a_patient.get_id() == 1);
    CHECK(a_patient.get_full_name() == "Max Mustermann");
}
TEST_SUITE_END();
