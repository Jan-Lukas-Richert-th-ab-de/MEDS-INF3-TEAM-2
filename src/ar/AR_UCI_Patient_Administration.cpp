#include "AR_UCI_Patient_Administration.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "ER_Patient.h"

AR_UCI_Patient_Administration::AR_UCI_Patient_Administration(
    AR_UCI_Patient_Administration_OB &presenter, AR_DAI_Patient_Repository &repository)
    : resource_presenter(presenter), resource_repository(repository){};

void AR_UCI_Patient_Administration::list_all()
{
  std::vector<std::map<std::string, std::string>> output_data;
  std::vector<ER_Patient> all_Patients = resource_repository.find_all();
  sort_Patients_by_id(all_Patients);
  for (auto current_Patient : all_Patients)
  {
    std::map<std::string, std::string> data_map_for_current_Patient =
        get_data_map_for_Patient(current_Patient);
    output_data.push_back(data_map_for_current_Patient);
  }
  resource_presenter.present_all(output_data);
};
void AR_UCI_Patient_Administration::create(std::string first_name, std::string last_name)
{
  ER_Patient a_Patient{first_name, last_name};
  resource_repository.save(a_Patient);
  list_all();
};
void AR_UCI_Patient_Administration::update(unsigned int id, std::string first_name, std::string last_name)
{
  ER_Patient a_Patient_to_be_updated = resource_repository.find(id);
  a_Patient_to_be_updated.set_first_name(first_name);
  a_Patient_to_be_updated.set_last_name(last_name);
  resource_repository.save(a_Patient_to_be_updated);
  list_all();
};
void AR_UCI_Patient_Administration::remove(unsigned int id)
{
  resource_repository.remove(id);
  list_all();
};

std::map<std::string, std::string> AR_UCI_Patient_Administration::get_data_map_for_Patient(const ER_Patient &a_Patient)
{
  std::map<std::string, std::string> data_map{};
  data_map.insert({"id", std::to_string(a_Patient.get_id())});
  data_map.insert({"first_name", a_Patient.get_first_name()});
  data_map.insert({"last_name", a_Patient.get_last_name()});
  return data_map;
};

void AR_UCI_Patient_Administration::sort_Patients_by_id(std::vector<ER_Patient> &Patient_list)
{
  std::sort(Patient_list.begin(), Patient_list.end(),
            [](ER_Patient a, ER_Patient b)
            {
              auto result_a{a.get_id()};
              auto result_b{b.get_id()};
              return (result_a < result_b);
              // the smaller result will be pushed to the beginning
            });
};