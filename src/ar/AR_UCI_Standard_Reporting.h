#ifndef AR_UCI_STANDARD_REPORTING_H
#define AR_UCI_STANDARD_REPORTING_H
#include "FD_Resource_View.h"
#include "AR_UCI_Standard_Reporting_IB.h"
#include "AR_UCI_Standard_Reporting_OB.h"
#include "AR_DAI_Person_Repository.h"

class AR_UCI_Standard_Reporting : public AR_UCI_Standard_Reporting_IB {
    public:
        AR_UCI_Standard_Reporting(
            AR_UCI_Standard_Reporting_OB& presenter
          , AR_DAI_Person_Repository& repository);
        void list_all();
        void create(std::string first_name, std::string last_name);
        void update(unsigned int id, std::string first_name, std::string last_name);
        void remove(unsigned int id);
    private:
        AR_UCI_Standard_Reporting_OB& resource_presenter;
        AR_DAI_Person_Repository& resource_repository;
        std::map<std::string, std::string> get_data_map_for_person(const ER_Person& a_person);
        void sort_persons_by_id (std::vector<ER_Person>& person_list);
};
#endif /* AR_UCI_Standard_Reporting_H */