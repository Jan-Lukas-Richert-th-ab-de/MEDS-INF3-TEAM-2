#ifndef IA_SUMMARY_STATISTICS_PRESENTER_H
#define IA_SUMMARY_STATISTICS_PRESENTER_H
#include "FD_Resource_View.h"

#include <vector>
#include <map>

#include "AR_UCI_Summary_Statistics_Administration_OB.h"

class IA_Summary_Statistics_Presenter : public AR_UCI_Summary_Statistics_Administration_OB {
    public:
        IA_Summary_Statistics_Presenter(FD_Resource_View& view);
        void present_all(const std::vector<std::map<std::string, std::string>>& data);
    private:
        FD_Resource_View& resource_view;
};
#endif /* IA_Summary_Statistics_PRESENTER_H */