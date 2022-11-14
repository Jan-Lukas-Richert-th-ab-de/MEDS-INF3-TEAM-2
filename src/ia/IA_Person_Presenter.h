#ifndef IA_PERSON_PRESENTER_H
#define IA_PERSON_PRESENTER_H
#include "FD_Resource_View.h"
#include "AR_UCI_Person_Administration_OB.h"
#include <vector>
#include <map>

class IA_Person_Presenter : public AR_UCI_Person_Administration_OB {
    public:
        IA_Person_Presenter(FD_Resource_View& view);
        void present_all(const std::vector<std::map<std::string, std::string>>& data);
    private:
        FD_Resource_View& resource_view;
};
#endif /* IA_PERSON_PRESENTER_H */