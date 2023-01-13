/*
#include "AR_UCI_Summary_Statistics_Creation.h"
#include <vector>
#include <map>
#include <string>

class MockPresenter : public AR_UCI_Summary_Statistics_Creation_OB {
public:
    void present_report_doctor_Summary_Statistics(const std::vector<std::map<std::string, std::string>>& data) override {
        present_data = data;
    }

    std::vector<std::map<std::string, std::string>> present_data;
};

class MockDoctorRepository : public AR_DAI_Doctor_Repository {
public:
    std::vector<ER_Doctor> retrieve_doctors() const override {
        std::vector<ER_Doctor> doctors;
        ER_Doctor doctor1("Doctor A", 10);
        ER_Doctor doctor2("Doctor B", 5);
        ER_Doctor doctor3("Doctor C", 0);
        doctors.push_back(doctor1);
        doctors.push_back(doctor2);
        doctors.push_back(doctor3);
        return doctors;
    }
};

TEST(AR_UCI_Summary_Statistics_Creation, TestReportDoctorSummaryStatistics) {
    // Arrange
    std::vector<std::map<std::string, std::string>> expected_data;
    std::map<std::string, std::string> doctor1_data;
    doctor1_data["Name"] = "Doctor A";
    doctor1_data["Appointments"] = "10";
    std::map<std::string, std::string> doctor2_data;
    doctor2_data["Name"] = "Doctor B";
    doctor2_data["Appointments"] = "5";
    std::map<std::string, std::string> doctor3_data;
    doctor3_data["Name"] = "Doctor C";
    doctor3_data["
Appointments"] = "0";
expected_data.push_back(doctor1_data);
expected_data.push_back(doctor2_data);
expected_data.push_back(doctor3_data);


MockPresenter presenter;
MockDoctorRepository repository;
AR_UCI_Summary_Statistics_Creation use_case(repository, presenter);

// Act
use_case.report_doctor_Summary_Statistics();

// Assert
EXPECT_EQ(presenter.present_data, expected_data);
}*/