#include "AR_UCI_Doctor_Administration.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "ER_Doctor.h"

AR_UCI_Doctor_Administration::AR_UCI_Doctor_Administration(
    AR_UCI_Doctor_Administration_OB &presenter, AR_DAI_Doctor_Repository &repository)
    : resource_presenter(presenter), resource_repository(repository){};

void AR_UCI_Doctor_Administration::list_all()
{
  std::vector<std::map<std::string, std::string>> output_data;
  std::vector<ER_Doctor> all_Doctors = resource_repository.find_all();
  sort_Doctors_by_id(all_Doctors);
  for (auto current_Doctor : all_Doctors)
  {
    std::map<std::string, std::string> data_map_for_current_Doctor =
        get_data_map_for_Doctor(current_Doctor);
    output_data.push_back(data_map_for_current_Doctor);
  }
  resource_presenter.present_all(output_data);
};
void AR_UCI_Doctor_Administration::create(std::string first_name, std::string last_name, std::string doctors_specialties)
{
  ER_Doctor a_Doctor{first_name, last_name, doctors_specialties};
  resource_repository.save(a_Doctor);
  list_all();
};
void AR_UCI_Doctor_Administration::update(unsigned int id, std::string first_name, std::string last_name, std::string doctors_specialties)
{
  ER_Doctor a_Doctor_to_be_updated = resource_repository.find(id);
  a_Doctor_to_be_updated.set_first_name(first_name);
  a_Doctor_to_be_updated.set_last_name(last_name);
  a_Doctor_to_be_updated.set_doctors_specialties(doctors_specialties);
  resource_repository.save(a_Doctor_to_be_updated);
  list_all();
};
void AR_UCI_Doctor_Administration::remove(unsigned int id)
{
  resource_repository.remove(id);
  list_all();
};

std::map<std::string, std::string> AR_UCI_Doctor_Administration::get_data_map_for_Doctor(const ER_Doctor &a_Doctor)
{
  std::map<std::string, std::string> data_map{};
  data_map.insert({"id", std::to_string(a_Doctor.get_id())});
  data_map.insert({"first_name", a_Doctor.get_first_name()});
  data_map.insert({"last_name", a_Doctor.get_last_name()});
  data_map.insert({"doctors_specialties", a_Doctor.get_doctors_specialties()});
  return data_map;
};

void AR_UCI_Doctor_Administration::sort_Doctors_by_id(std::vector<ER_Doctor> &Doctor_list)
{
  std::sort(Doctor_list.begin(), Doctor_list.end(),
            [](ER_Doctor a, ER_Doctor b)
            {
              auto result_a{a.get_id()};
              auto result_b{b.get_id()};
              return (result_a < result_b);
              // the smaller result will be pushed to the beginning
            });
};