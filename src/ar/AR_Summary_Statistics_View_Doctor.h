#ifndef AR_SUMMARY_STATISTICS_VIEW_DOCTOR_H
#define AR_SUMMARY_STATISTICS_VIEW_DOCTOR_H
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
 
 class report_doctor_summary_statistics {
     public:
         Doctor(std::int date_conter, std::int doctor_date_conter, int Average_doctor);
         std::string get_date_conte();
         std::string get_doctor_date_conter();
         int get_Average_doctor();
     private:
         std::int date_conter;
         std::int doctor_date_conter;
         int Average_doctor;
 };