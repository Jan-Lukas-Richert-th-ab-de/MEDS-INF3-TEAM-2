
#ifndef FD_SUMMARY_STATISTICS_VIEW_H
#define FD_SUMMARY_STATISTICS_VIEW_H
#include "FD_Resource_View.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

class FD_Summary_Statistics_View  : public FD_Resource_View_S{
public:
    void show_list_view(const std::vector<std::map<std::string, std::string>> &data)override;

    void show_room_occupancy_summary(const std::vector<std::map<std::string, std::string>> &data)override;
    void show_room_occupancy_summary_per_week(const std::vector<std::map<std::string, std::string>> &data)override;

    void show_doctor_summary(const std::vector<std::map<std::string, std::string>> &data)override;
    void show_doctor_summary_per_week(const std::vector<std::map<std::string, std::string>> &data)override;

private:
    void show_list_empty_message();

    void show_column_header();

};
#endif 