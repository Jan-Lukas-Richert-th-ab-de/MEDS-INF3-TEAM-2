#ifndef AR_UCI_STANDARD_REPORTING_H
#define AR_UCI_STANDARD_REPORTING_H
#include "FD_Resource_View.h"
#include "AR_UCI_Standard_Reporting_IB.h"
#include "AR_UCI_Standard_Reporting_OB.h"
#include "AR_DAI_Doctor_Repository.h"
#include "AR_DAI_Room_Repository.h"
#include "AR_DAI_Appointment_Repository.h"


class AR_UCI_Standard_Reporting : public AR_UCI_Standard_Reporting_IB {
    public:
        AR_UCI_Standard_Reporting(
            AR_UCI_Standard_Reporting_OB& doctor_presenter
          , AR_UCI_Standard_Reporting_OB& room_presenter
          , AR_UCI_Standard_Reporting_OB& appointment_presenter
          , AR_DAI_Doctor_Repository& doctor_repository
          , AR_DAI_Room_Repository& room_repository
          , AR_DAI_Appointment_Repository& appointment_repository);

        void list_all();

        void report_doctor_timeplan(); 
        void report_room_occupancy_plan(); 
        void report_appointment(); 
        
    private:
        AR_UCI_Standard_Reporting_OB& doctor_resource_presenter;
        AR_UCI_Standard_Reporting_OB& room_resource_presenter;
        AR_UCI_Standard_Reporting_OB& appointment_resource_presenter;



        AR_DAI_Doctor_Repository& doctor_resource_repository;
        AR_DAI_Room_Repository& room_resource_repository;
        AR_DAI_Appointment_Repository& appointment_resource_repository;

};

#endif /* AR_UCI_Standard_Reporting_H */
