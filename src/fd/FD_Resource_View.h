#ifndef FD_RESOURCE_VIEW_H
#define FD_RESOURCE_VIEW_H
#include "FD_View.h"
#include <vector>
#include <map>

class FD_Resource_View : public FD_View {
   public:
      virtual void show_list_view(const std::vector<std::map<std::string, std::string>>& data) = 0; 
     


      
      
      virtual ~FD_Resource_View() = default;
      FD_Resource_View() = default;
      FD_Resource_View(const FD_Resource_View&) = default;
      FD_Resource_View& operator=(const FD_Resource_View&) = default;

};

class FD_Resource_View_S : public FD_View_S {

 public:
      virtual void show_list_view(const std::vector<std::map<std::string, std::string>>& data) = 0; 
      virtual void show_doctor_summary(const std::vector<std::map<std::string, std::string>>& data) = 0;
      virtual void show_room_occupancy_summary(const std::vector<std::map<std::string, std::string>>& room_statistics) = 0;
            virtual void show_doctor_summary_per_week(const std::vector<std::map<std::string, std::string>>& data) = 0;
      virtual void show_room_occupancy_summary_per_week(const std::vector<std::map<std::string, std::string>>& room_statistics) = 0;
      virtual ~FD_Resource_View_S() = default;
      FD_Resource_View_S() = default;
      FD_Resource_View_S(const FD_Resource_View_S&) = default;
      FD_Resource_View_S& operator=(const FD_Resource_View_S&) = default;
};

#endif /* FD_RESOURCE_VIEW_H */