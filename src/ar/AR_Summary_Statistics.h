#ifndef AR_SUMMARY_STATISTICS_H
#define AR_SUMMARY_STATISTICS_H

#include <string>
#include <vector>



// Class for representing rooms
class Room
{
public:
    // Constructor
    Room(int number, const std::vector<std::pair<int, int>>& occupancy_times)
        : number_(number), occupancy_times_(occupancy_times)
    {
    }

    // Get the room number
    int number() const
    {
        return number_;
    }

    // Get the occupancy times for the room
    const std::vector<std::pair<int, int>>& occupancyTimes() const
    {
        return occupancy_times_;
    }
    

private:
    int number_;
    std::vector<std::pair<int, int>> occupancy_times_;
};



// Class for representing doctors
class Doctor
{
public:
    // Constructor
    Doctor(const std::string& name, const std::vector<std::pair<int, int>>& deployment_times)
        : name_(name), deployment_times_(deployment_times)
    {
    }

    // Get the doctor's name
    const std::string& name() const
    {
        return name_;
    }

    // Get the deployment times for the doctor
    const std::vector<std::pair<int, int>>& deploymentTimes() const
    {
        return deployment_times_;
    }

private:
    std::string name_;
    std::vector<std::pair<int, int>> deployment_times_;
};

// Function for calculating the average occupancy period of consulting rooms
// per day for a given week
double calculateAverageOccupancyPeriodPerDay(const std::vector<Room>& rooms, int week);

// Function for calculating the average duration of deployment of doctors
// per day for a given week
double calculateAverageDeploymentDurationPerDay(const std::vector<Doctor>& doctors, int week);

#endif // AR_SUMMARY_STATISTICS_H