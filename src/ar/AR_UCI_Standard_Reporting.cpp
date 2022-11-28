#include "AR_UCI_Standard_Reporting.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "ER_Person.h"

AR_UCI_Standard_Reporting::AR_UCI_Standard_Reporting(
    AR_UCI_Standard_Reporting_OB& presenter
  , AR_DAI_Person_Repository& repository)
            : resource_presenter(presenter)
            , resource_repository(repository) {};

void AR_UCI_Standard_Reporting::list_all(){
  std::vector<std::map<std::string, std::string>> output_data;
  std::vector<ER_Person> all_persons = resource_repository.find_all();
  sort_persons_by_id(all_persons);
  for(auto current_person : all_persons) {
    std::map<std::string, std::string> data_map_for_current_person = 
        get_data_map_for_person(current_person);
    output_data.push_back(data_map_for_current_person);
  }
  resource_presenter.present_all(output_data);
};
void AR_UCI_Standard_Reporting::create(std::string first_name, std::string last_name){
  ER_Person a_person{first_name, last_name};
  resource_repository.save(a_person);
  list_all();
};
void AR_UCI_Standard_Reporting::update(unsigned int id, std::string first_name, std::string last_name){
  ER_Person a_person_to_be_updated = resource_repository.find(id);
  a_person_to_be_updated.set_first_name(first_name);
  a_person_to_be_updated.set_last_name(last_name);
  resource_repository.save(a_person_to_be_updated);
  list_all();
};
void AR_UCI_Standard_Reporting::remove(unsigned int id){
  resource_repository.remove(id);
  list_all();
};

std::map<std::string, std::string> AR_UCI_Standard_Reporting::get_data_map_for_person(const ER_Person& a_person){
    std::map<std::string, std::string> data_map{};
    data_map.insert({"id",std::to_string(a_person.get_id())});
    data_map.insert({"first_name",a_person.get_first_name()});
    data_map.insert({"last_name",a_person.get_last_name()});
    return data_map;
};

void AR_UCI_Standard_Reporting::sort_persons_by_id (std::vector<ER_Person>& person_list) {
    std::sort(person_list.begin(), person_list.end(),
    		[](ER_Person a, ER_Person b) {
		   	auto result_a{a.get_id()};
		  	auto result_b{b.get_id()};
		  	return (result_a < result_b);
		  	// the smaller result will be pushed to the beginning
		    }
	  );
};