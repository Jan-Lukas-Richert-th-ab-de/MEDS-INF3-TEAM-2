#include "doctest.h"
#include "ER_Doctor.h"
#include "FD_DA_Doctor_Repository_FileBasedImpl.h"

TEST_SUITE_BEGIN("FD_DA_Doctor_Repository_FileBasedImpl");
TEST_CASE("save doctor, find doctor")
{
    ER_Doctor a_doctor{"Maria", "Musterfrau"};
    FD_DA_Doctor_Repository_FileBasedImpl a_doctor_repo{};
    a_doctor_repo.set_storage_file_name("PERSON_LIST_TEST_DATA.txt");
    a_doctor_repo.remove_all();
    ER_Doctor a_created_doctor = a_doctor_repo.save(a_doctor);
    ER_Doctor a_restored_doctor = a_doctor_repo.find(a_created_doctor.get_id());
    CHECK(a_restored_doctor.get_id() == a_created_doctor.get_id());
    CHECK(a_restored_doctor.get_first_name() == "Maria");
    CHECK(a_restored_doctor.get_last_name() == "Musterfrau");
    a_doctor_repo.remove_all();
}

TEST_CASE("save two doctors, find second doctor")
{
    FD_DA_Doctor_Repository_FileBasedImpl a_doctor_repo{};
    a_doctor_repo.set_storage_file_name("PERSON_LIST_TEST_DATA.txt");
    a_doctor_repo.remove_all();
    ER_Doctor a_doctor{"Maria", "Musterfrau"};
    ER_Doctor a_created_doctor = a_doctor_repo.save(a_doctor);
    ER_Doctor a_doctor2{"Max", "Mustermann"};
    ER_Doctor a_created_doctor2 = a_doctor_repo.save(a_doctor2);

    ER_Doctor a_restored_doctor2 = a_doctor_repo.find(a_created_doctor2.get_id());
    CHECK(a_restored_doctor2.get_id() == a_created_doctor2.get_id());
    a_doctor_repo.remove_all();
}
TEST_CASE("save three doctors, remove second doctor, find all")
{
    FD_DA_Doctor_Repository_FileBasedImpl a_doctor_repo{};
    a_doctor_repo.set_storage_file_name("PERSON_LIST_TEST_DATA.txt");
    a_doctor_repo.remove_all();
    ER_Doctor a_doctor{"Maria", "Musterfrau"};
    ER_Doctor a_created_doctor = a_doctor_repo.save(a_doctor);
    ER_Doctor a_doctor2{"Max", "Mustermann"};
    ER_Doctor a_created_doctor2 = a_doctor_repo.save(a_doctor2);
    ER_Doctor a_doctor3{"Eva", "Musterfrau"};
    ER_Doctor a_created_doctor3 = a_doctor_repo.save(a_doctor3);
    a_doctor_repo.remove(a_created_doctor2.get_id());
    std::vector<ER_Doctor> all_stored_doctors = a_doctor_repo.find_all();
    CHECK(all_stored_doctors.size() == 2);
    CHECK((all_stored_doctors.at(0)).get_id() == 1);
    CHECK((all_stored_doctors.at(0)).get_first_name() == "Maria");
    CHECK((all_stored_doctors.at(1)).get_id() == 3);
    CHECK((all_stored_doctors.at(1)).get_first_name() == "Eva");
    a_doctor_repo.remove_all();
}

TEST_CASE("save three doctors, update second doctor, find all")
{
    FD_DA_Doctor_Repository_FileBasedImpl a_doctor_repo{};
    a_doctor_repo.set_storage_file_name("PERSON_LIST_TEST_DATA.txt");
    a_doctor_repo.remove_all();
    ER_Doctor a_doctor{"Maria", "Musterfrau"};
    ER_Doctor a_created_doctor = a_doctor_repo.save(a_doctor);
    ER_Doctor a_doctor2{"Max", "Mustermann"};
    ER_Doctor a_created_doctor2 = a_doctor_repo.save(a_doctor2);
    ER_Doctor a_doctor3{"Eva", "Musterfrau"};
    ER_Doctor a_created_doctor3 = a_doctor_repo.save(a_doctor3);
    a_created_doctor2.set_last_name("Meier");
    ER_Doctor an_updated_doctor2 = a_doctor_repo.save(a_created_doctor2);
    CHECK(an_updated_doctor2.get_id() == a_created_doctor2.get_id());
    std::vector<ER_Doctor> all_stored_doctors = a_doctor_repo.find_all();
    CHECK(all_stored_doctors.size() == 3);
    CHECK((all_stored_doctors.at(0)).get_id() == 1);
    CHECK((all_stored_doctors.at(0)).get_first_name() == "Maria");
    CHECK((all_stored_doctors.at(1)).get_id() == 3);
    CHECK((all_stored_doctors.at(1)).get_first_name() == "Eva");
    CHECK((all_stored_doctors.at(2)).get_id() == 2);
    CHECK((all_stored_doctors.at(2)).get_first_name() == "Max");
    CHECK((all_stored_doctors.at(2)).get_last_name() == "Meier");
    a_doctor_repo.remove_all();
}

TEST_SUITE_END();