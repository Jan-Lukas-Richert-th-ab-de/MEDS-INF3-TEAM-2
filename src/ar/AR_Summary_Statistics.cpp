#include "AR_Summary_Statistics.h"
using namespace std;


// Function for calculating the average occupancy period of consulting rooms
// for a given data set
double calculateAverageOccupancyPeriod(const  OccupancyAndDeploymentData& data)
{
    // Calculate the total occupancy period
    int total_occupancy_period = 0;
    for (const auto& occupancy_time : data.occupancy_times)
    {
        total_occupancy_period += occupancy_time.second - occupancy_time.first;
    }

    // Calculate the average occupancy period
    
    int num_occupancy_times = data.occupancy_times.size();
    double average_occupancy_period = 0.0;
    if (num_occupancy_times > 0)
    {
        average_occupancy_period = static_cast<double>(total_occupancy_period) / num_occupancy_times;
    }

    return average_occupancy_period;
};

// Function for calculating the average duration of deployment of doctors
// for a given data set
double calculateAverageDeploymentDuration(const OccupancyAndDeploymentData& data)
{
    // Calculate the total deployment duration
    int total_deployment_duration = 0;
    for (const auto& deployment_time : data.deployment_times)
    {
        total_deployment_duration += deployment_time.second - deployment_time.first;
    }

    // Calculate the average deployment duration
    int num_deployment_times = data.deployment_times.size();
    double average_deployment_duration = 0.0;
    if (num_deployment_times > 0)
    {
        average_deployment_duration = static_cast<double>(total_deployment_duration) / num_deployment_times;
    }

    return average_deployment_duration;
};