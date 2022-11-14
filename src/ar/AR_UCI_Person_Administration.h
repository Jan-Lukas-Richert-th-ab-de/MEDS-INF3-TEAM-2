#ifndef AR_UCI_PERSON_ADMINISTRATION_H
#define AR_UCI_PERSON_ADMINISTRATION_H
#include "FD_Resource_View.h"
#include "AR_UCI_Person_Administration_IB.h"
#include "AR_UCI_Person_Administration_OB.h"
#include "AR_DAI_Person_Repository.h"

class AR_UCI_Person_Administration : public AR_UCI_Person_Administration_IB {
    public:
        AR_UCI_Person_Administration(
            AR_UCI_Person_Administration_OB& presenter
          , AR_DAI_Person_Repository& repository);
        void list_all();
        void create(std::string first_name, std::string last_name);
        void update(unsigned int id, std::string first_name, std::string last_name);
        void remove(unsigned int id);
    private:
        AR_UCI_Person_Administration_OB& resource_presenter;
        AR_DAI_Person_Repository& resource_repository;
        std::map<std::string, std::string> get_data_map_for_person(const ER_Person& a_person);
        void sort_persons_by_id (std::vector<ER_Person>& person_list);
};
#endif /* AR_UCI_PERSON_ADMINISTRATION_H */