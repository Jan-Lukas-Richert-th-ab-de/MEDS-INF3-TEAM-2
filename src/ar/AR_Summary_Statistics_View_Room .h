#ifndef AR_SUMMARY_STATISTICS_VIEW_ROOM_H
#define AR_SUMMARY_STATISTICS_VIEW_ROOM_H
#include  "FD_Resource_View.h"
#include <map>
#include <numeric>
#include <vector>
#include <cmath>


/*class FD_Summary_Statistics_View : public FD_Resource_View {
   public:
       void show_list_view(const std::vector<std::map<std::string, std::string>>& data); 
   private:
       void show_list_empty_message();
       void show_list_header();
       void show_column_header();
       void show_list_contents(const std::vector<std::map<std::string, std::string>>& data);
};*/

  class report_room_summary_statistics {
     public:
         Room(std::int date_conter, std::int room_date_conter, int Average_room);
         std::int date_conter();
         std::int room_date_conter();
         int average_room();
     private:
         std::int date_conter;
         std::int room_date_conter;
        int Average_room;
 };
