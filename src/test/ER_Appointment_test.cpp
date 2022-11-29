#include "doctest.h"
#include "ER_Appointment.h"

TEST_SUITE_BEGIN("Appointment");
TEST_CASE("create appointment, get_id, get_date") 
{
    ER_Appointment a_appointment{"01", ".", "01", ".", "2022"}; //??????
    CHECK(a_appointment.get_id()==0);
    CHECK(a_appointment.get_full_date()=="01.01.2022"); //??????
}
TEST_CASE("create appointment with id, get_date") 
{
    ER_Appointment a_appointment{1, "01", ".", "01", ".", "2022"}; //??????
    CHECK(a_appointment.get_id()==1);
    CHECK(a_appointment.get_full_date()=="01.01.2022"); //?????????
}
TEST_SUITE_END();
