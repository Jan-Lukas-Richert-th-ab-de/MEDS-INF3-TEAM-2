  #include "AR_Summary_Statistics_View_Room.h"
  #include <iostream>
  #include <iomanip>

  void AR_Summary_Statistics_View_Room::show_list_view(const std::vector<std::map<std::string, std::string>>& data)
  {
    if (data.empty())
    {
        show_list_empty_message();
    }
    else
    {
        show_list_header();
        show_column_header();
        show_list_contents(data);
    }
  }

   void AR_Summary_Statistics_View_Room::show_list_empty_message()
   {
       std::cout << "No data stored!" << '\n';
   }
   void AR_Summary_Statistics_View_Room::show_list_header()
   {
       std::cout << "Doktor List:" << '\n';
   }
   void AR_Summary_Statistics_View_Room::show_column_header()
   {
       std::cout << std::left << std::setfill(' ') << std::setw(3) << "room ID";
     std::cout << " - ";
    std::cout << std::left << std::setfill(' ') << std::setw(10) << "room_date_conter";
     std::cout << " - ";
     std::cout << std::left << std::setfill(' ') << std::setw(10) << "Average_room";
    std::cout << '\n';
 }
 void AR_Summary_Statistics_View_Room::show_list_contents(const std::vector<std::map<std::string, std::string>>& data)
{
     for (auto current_element : data)
    {
         std::cout << std::left << std::setfill(' ') << std::setw(3) << current_element["room ID"];
         std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["room_date_conter"];
       std::cout << " - ";
        std::cout << std::left << std::setfill(' ') << std::setw(10) << current_element["Average_room"];
        std::cout << '\n';
    }
 }
