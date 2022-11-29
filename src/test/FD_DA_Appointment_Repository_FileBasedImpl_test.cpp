#include "doctest.h"
#include "ER_Appointment.h"
#include "FD_DA_Appointment_Repository_FileBasedImpl.h"

TEST_SUITE_BEGIN("FD_DA_Appointment_Repository_FileBasedImpl");
TEST_CASE("save appointment, find appointment") 
{
    ER_Appointment a_appointment{"01", ".", "01", ".", "2022"};
    FD_DA_Appointment_Repository_FileBasedImpl a_appointment_repo{};
    a_appointment_repo.set_storage_file_name("appointment_LIST_TEST_DATA.txt");
    a_appointment_repo.remove_all();
    ER_Appointment a_created_appointment = a_appointment_repo.save(a_appointment);
    ER_Appointment a_restored_appointment = a_appointment_repo.find(a_created_appointment.get_id());
    CHECK(a_restored_appointment.get_id()== a_created_appointment.get_id());
    CHECK(a_restored_appointment.get_day()=="01");
    CHECK(a_restored_appointment.get_month()=="01");
    CHECK(a_restored_appointment.get_year()=="2022"); //+year

    a_appointment_repo.remove_all();
}

TEST_CASE("save two appointments, find second appointment") 
{
    FD_DA_Appointment_Repository_FileBasedImpl a_appointment_repo{};
    a_appointment_repo.set_storage_file_name("APPOINTMENT_LIST_TEST_DATA.txt");
    a_appointment_repo.remove_all();
    ER_Appointment a_appointment{"01", ".", "01", ".", "2022"}; // Maria
    ER_Appointment a_created_appointment = a_appointment_repo.save(a_appointment);
    ER_Appointment a_appointment2{"02", ".", "02", ".", "2022"}; // Max
    ER_Appointment a_created_appointment2 = a_appointment_repo.save(a_appointment2);

    ER_Appointment a_restored_appointment2 = a_appointment_repo.find(a_created_appointment2.get_id());
    CHECK(a_restored_appointment2.get_id()==a_created_appointment2.get_id());
    a_appointment_repo.remove_all();
}
TEST_CASE("save three appointments, remove second appointment, find all") 
{
    FD_DA_Appointment_Repository_FileBasedImpl a_appointment_repo{};
    a_appointment_repo.set_storage_file_name("APPOINTMENT_LIST_TEST_DATA.txt");
    a_appointment_repo.remove_all();
    ER_Appointment a_appointment{"01", ".", "01", ".", "2022"}; //Maria
    ER_Appointment a_created_appointment = a_appointment_repo.save(a_appointment);
    ER_Appointment a_appointment2{"02", ".", "02", ".", "2022"}; //Max
    ER_Appointment a_created_appointment2 = a_appointment_repo.save(a_appointment2);
    ER_Appointment a_appointment3{"03", ".", "03", ".", "2022"}; //Eva
    ER_Appointment a_created_appointment3 = a_appointment_repo.save(a_appointment3);
    a_appointment_repo.remove(a_created_appointment2.get_id());
    std::vector<ER_Appointment> all_stored_appointments = a_appointment_repo.find_all();
    CHECK(all_stored_appointments.size()==2);
    CHECK((all_stored_appointments.at(0)).get_id() == 1);
    CHECK((all_stored_appointments.at(0)).get_day() == "01"); //Maria
    CHECK((all_stored_appointments.at(1)).get_id() == 3);
    CHECK((all_stored_appointments.at(1)).get_day() == "03"); //Eva
    a_appointment_repo.remove_all();
}

TEST_CASE("save three appointments, update second appointment, find all") 
{
    FD_DA_Appointment_Repository_FileBasedImpl a_appointment_repo{};
    a_appointment_repo.set_storage_file_name("APPOINTMENT_LIST_TEST_DATA.txt");
    a_appointment_repo.remove_all();
    ER_Appointment a_appointment{"01", ".", "01", ".", "2022"};
    ER_Appointment a_created_appointment = a_appointment_repo.save(a_appointment);
    ER_Appointment a_appointment2{"02", ".", "02", ".", "2022"};
    ER_Appointment a_created_appointment2 = a_appointment_repo.save(a_appointment2);
    ER_Appointment a_appointment3{"03", ".", "03", ".", "2022"};
    ER_Appointment a_created_appointment3 = a_appointment_repo.save(a_appointment3);
    a_created_appointment2.set_month("02");
    ER_Appointment  an_updated_appointment2 = a_appointment_repo.save(a_created_appointment2);
    CHECK(an_updated_appointment2.get_id() == a_created_appointment2.get_id());
    std::vector<ER_Appointment> all_stored_appointments = a_appointment_repo.find_all();
    CHECK(all_stored_appointments.size()==3);
    CHECK((all_stored_appointments.at(0)).get_id() == 1);
    CHECK((all_stored_appointments.at(0)).get_day() == "01");
    CHECK((all_stored_appointments.at(1)).get_id() == 3);
    CHECK((all_stored_appointments.at(1)).get_day() == "03");
    CHECK((all_stored_appointments.at(2)).get_id() == 2);
    CHECK((all_stored_appointments.at(2)).get_day() == "02");
    CHECK((all_stored_appointments.at(2)).get_month() == "02");
    CHECK((all_stored_appointments.at(2)).get_year() == "2022"); //+year
    a_appointment_repo.remove_all();
}

TEST_SUITE_END();