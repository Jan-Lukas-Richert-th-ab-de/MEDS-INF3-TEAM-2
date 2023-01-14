#ifndef AR_UCI_Patient_ADMINISTRATION_H
#define AR_UCI_Patient_ADMINISTRATION_H
#include "FD_Resource_View.h"
#include "AR_UCI_Patient_Administration_IB.h"
#include "AR_UCI_Patient_Administration_OB.h"
#include "AR_DAI_Patient_Repository.h"

class AR_UCI_Patient_Administration : public AR_UCI_Patient_Administration_IB
{
public:
    AR_UCI_Patient_Administration(
        AR_UCI_Patient_Administration_OB &presenter, AR_DAI_Patient_Repository &repository);
    void list_all();
    void list_all_data();
    void create(std::string first_name, std::string last_name);
    void update(unsigned int id, std::string first_name, std::string last_name);
    void remove(unsigned int id);

private:
    AR_UCI_Patient_Administration_OB &resource_presenter;
    AR_DAI_Patient_Repository &resource_repository;
    std::map<std::string, std::string> get_data_map_for_Patient(const ER_Patient &a_Patient);
    void sort_Patients_by_id(std::vector<ER_Patient> &Patient_list);
};
#endif /* AR_UCI_Patient_ADMINISTRATION_H */