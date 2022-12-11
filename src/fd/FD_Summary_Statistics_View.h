#ifndef FD_SUMMARY_STATISTICS_VIEW_H
#define FD_SUMMARY_STATISTICS_VIEW_H

#include "AR_Summary_Statistics.h"

// Class for displaying summary statistics
class SummaryStatisticsView
{
public:
    // Constructor
    SummaryStatisticsView(const  OccupancyAndDeploymentData& data) : data_(data)
    {
    }

    // Display the summary statistics on the screen
    void display() const;

private:
    const int OccupancyAndDeploymentData& data_;
};

#endif // FD_SUMMARY_STATISTICS_VIEW_H
