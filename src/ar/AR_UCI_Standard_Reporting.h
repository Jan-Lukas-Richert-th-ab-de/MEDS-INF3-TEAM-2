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
          , AR_DAI_Doctor_Repository& repositoryDoctor;
          , AR_DAI_Room_Repository& repositoryRoom);
        void list_all();
        

    private:
        AR_UCI_Standard_Reporting_OB& resource_presenter;
        AR_DAI_Person_Repository& resource_repository;
        std::map<std::string, std::string> get_data_map_for_doctor(const ER_Doctor& a_doctor);
        std::map<std::string, std::string> get_data_map_for_room(const ER_Room& a_room);
        void sort_doctors_by_id (std::vector<ER_Doctor>& doctor_list);
        void sort_rooms_by_id (std::vector<ER_Roomr>& room_list);

};
#endif /* AR_UCI_Standard_Reporting_H */
