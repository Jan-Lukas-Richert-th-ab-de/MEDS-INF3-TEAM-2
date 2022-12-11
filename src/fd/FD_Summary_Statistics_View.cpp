

#include "FD_Summary_Statistics_View.h"
#include <iostream>


// Display the summary statistics on the screen
void SummaryStatisticsView::display() const
{
   
    // Calculate the average occupancy period
    double average_occupancy_period = calculateAverageOccupancyPeriod(data_);

    // Calculate the average deployment duration
    double average_deployment_duration = calculateAverageDeploymentDurationp(data_);

    // Create a vector of summary statistics
    std::vector<std::pair<std::string, double>> summary_statistics;
    summary_statistics.push_back({"Average occupancy period", average_occupancy_period});
    summary_statistics.push_back({"Average deployment duration", average_deployment_duration});

    // Display the summary statistics in a list format
    std::cout << "Summary statistics:" << std::endl;
    for (const auto& stat : summary_statistics)
    {
        std::cout << " - " << stat.first << ": " << stat.second << std::endl;
    }
}

