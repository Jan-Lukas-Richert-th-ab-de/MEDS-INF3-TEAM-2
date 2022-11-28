#ifndef AR_UCI_DOCTOR_ADMINISTRATION_H
#define AR_UCI_DOCTOR_ADMINISTRATION_H
#include "FD_Resource_View.h"
#include "AR_UCI_DOCTOR_Administration_IB.h"
#include "AR_UCI_DOCTOR_Administration_OB.h"
#include "AR_DAI_DOCTOR_Repository.h"

class AR_UCI_Doctor_Administration : public AR_UCI_Doctor_Administration_IB
{
public:
    AR_UCI_Doctor_Administration(
        AR_UCI_Doctor_Administration_OB &presenter, AR_DAI_Doctor_Repository &repository);
    void list_all();
    void create(std::string first_name, std::string last_name, std::string doctors_specialties);
    void update(unsigned int id, std::string first_name, std::string last_name, std::string doctors_specialties);
    void remove(unsigned int id);

private:
    AR_UCI_Doctor_Administration_OB &resource_presenter;
    AR_DAI_Doctor_Repository &resource_repository;
    std::map<std::string, std::string> get_data_map_for_Doctor(const ER_Doctor &a_Doctor);
    void sort_Doctors_by_id(std::vector<ER_Doctor> &Doctor_list);
};
#endif /* AR_UCI_Doctor_ADMINISTRATION_H */