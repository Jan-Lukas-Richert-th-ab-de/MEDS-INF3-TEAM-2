#include "doctest.h"
#include "ER_Patient.h"
#include "FD_DA_Patient_Repository_FileBasedImpl.h"

TEST_SUITE_BEGIN("FD_DA_Patient_Repository_FileBasedImpl");
TEST_CASE("save patient, find patient")
{
    ER_Patient a_patient{"Maria", "Musterfrau"};
    FD_DA_Patient_Repository_FileBasedImpl a_patient_repo{};
    a_patient_repo.set_storage_file_name("PERSON_LIST_TEST_DATA.txt");
    a_patient_repo.remove_all();
    ER_Patient a_created_patient = a_patient_repo.save(a_patient);
    ER_Patient a_restored_patient = a_patient_repo.find(a_created_patient.get_id());
    CHECK(a_restored_patient.get_id() == a_created_patient.get_id());
    CHECK(a_restored_patient.get_first_name() == "Maria");
    CHECK(a_restored_patient.get_last_name() == "Musterfrau");
    a_patient_repo.remove_all();
}

TEST_CASE("save two patients, find second patient")
{
    FD_DA_Patient_Repository_FileBasedImpl a_patient_repo{};
    a_patient_repo.set_storage_file_name("PERSON_LIST_TEST_DATA.txt");
    a_patient_repo.remove_all();
    ER_Patient a_patient{"Maria", "Musterfrau"};
    ER_Patient a_created_patient = a_patient_repo.save(a_patient);
    ER_Patient a_patient2{"Max", "Mustermann"};
    ER_Patient a_created_patient2 = a_patient_repo.save(a_patient2);

    ER_Patient a_restored_patient2 = a_patient_repo.find(a_created_patient2.get_id());
    CHECK(a_restored_patient2.get_id() == a_created_patient2.get_id());
    a_patient_repo.remove_all();
}
TEST_CASE("save three patients, remove second patient, find all")
{
    FD_DA_Patient_Repository_FileBasedImpl a_patient_repo{};
    a_patient_repo.set_storage_file_name("PERSON_LIST_TEST_DATA.txt");
    a_patient_repo.remove_all();
    ER_Patient a_patient{"Maria", "Musterfrau"};
    ER_Patient a_created_patient = a_patient_repo.save(a_patient);
    ER_Patient a_patient2{"Max", "Mustermann"};
    ER_Patient a_created_patient2 = a_patient_repo.save(a_patient2);
    ER_Patient a_patient3{"Eva", "Musterfrau"};
    ER_Patient a_created_patient3 = a_patient_repo.save(a_patient3);
    a_patient_repo.remove(a_created_patient2.get_id());
    std::vector<ER_Patient> all_stored_patients = a_patient_repo.find_all();
    CHECK(all_stored_patients.size() == 2);
    CHECK((all_stored_patients.at(0)).get_id() == 1);
    CHECK((all_stored_patients.at(0)).get_first_name() == "Maria");
    CHECK((all_stored_patients.at(1)).get_id() == 3);
    CHECK((all_stored_patients.at(1)).get_first_name() == "Eva");
    a_patient_repo.remove_all();
}

TEST_CASE("save three patients, update second patient, find all")
{
    FD_DA_Patient_Repository_FileBasedImpl a_patient_repo{};
    a_patient_repo.set_storage_file_name("PERSON_LIST_TEST_DATA.txt");
    a_patient_repo.remove_all();
    ER_Patient a_patient{"Maria", "Musterfrau"};
    ER_Patient a_created_patient = a_patient_repo.save(a_patient);
    ER_Patient a_patient2{"Max", "Mustermann"};
    ER_Patient a_created_patient2 = a_patient_repo.save(a_patient2);
    ER_Patient a_patient3{"Eva", "Musterfrau"};
    ER_Patient a_created_patient3 = a_patient_repo.save(a_patient3);
    a_created_patient2.set_last_name("Meier");
    ER_Patient an_updated_patient2 = a_patient_repo.save(a_created_patient2);
    CHECK(an_updated_patient2.get_id() == a_created_patient2.get_id());
    std::vector<ER_Patient> all_stored_patients = a_patient_repo.find_all();
    CHECK(all_stored_patients.size() == 3);
    CHECK((all_stored_patients.at(0)).get_id() == 1);
    CHECK((all_stored_patients.at(0)).get_first_name() == "Maria");
    CHECK((all_stored_patients.at(1)).get_id() == 3);
    CHECK((all_stored_patients.at(1)).get_first_name() == "Eva");
    CHECK((all_stored_patients.at(2)).get_id() == 2);
    CHECK((all_stored_patients.at(2)).get_first_name() == "Max");
    CHECK((all_stored_patients.at(2)).get_last_name() == "Meier");
    a_patient_repo.remove_all();
}

TEST_SUITE_END();