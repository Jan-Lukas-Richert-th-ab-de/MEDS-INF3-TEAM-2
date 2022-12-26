#ifndef IA_SUMMARY_STATISTICS_PRESENTER_H
#define IA_SUMMARY_STATISTICS_PRESENTER_H
#include "FD_Resource_View.h"
#include "AR_UCI_Summary_Statistics_Creation_OB.h"
#include <vector>
#include <map>


class IA_Summary_Statistics_Presenter : public AR_UCI_Summary_Statistics_Creation_OB {
    public:
        IA_Summary_Statistics_Presenter(FD_Resource_View_S& view);
        void present_all(const std::vector<std::map<std::string, std::string>>& data);
    private:
        FD_Resource_View_S &resource_view;
};
#endif /* IA_Summary_Statistics_PRESENTER_H */