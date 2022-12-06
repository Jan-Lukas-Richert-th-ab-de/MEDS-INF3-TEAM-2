#include "AR_UCI_Standard_Reporting.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "ER_doctor.h"
#include "ER_Room.h"
#include "ER_appointment.h"


AR_UCI_Standard_Reporting::AR_UCI_Standard_Reporting(
    AR_UCI_Standard_Reporting_OB &presenter
  , AR_DAI_Doctor_Repository& repositoryDoctor
  , AR_DAI_Room_Repository& repositoryRoom)
    : resource_presenter(presenter)
    , resource_repository(repositoryDoctor)
    , resource_repository(repositorRoom) {};

void AR_UCI_Standard_Reporting::list_all()
{
  std::vector<std::map<std::string, std::string>> output_data;
  std::vector<ER_Doctor> all_doctors = resource_repository.find_all();
  
  sort_doctors_by_id(all_doctors);
  for (auto current_doctor : all_doctors)
  {
    std::map<std::string, std::string> data_map_for_current_doctor =
        get_data_map_for_doctor(current_doctor);
    output_data.push_back(data_map_for_current_doctor);
  }

  sort_rooms_by_id(all_room);
  for (auto current_room: all_room)
  {
    std::map<std::string, std::string> data_map_for_current_room =
        get_data_map_for_tour(current_room);
    output_data.push_back(data_map_for_current_room);
  }

  resource_presenter.present_all(output_data);
};