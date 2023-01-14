#include <iostream>
#include "ER_Room.h"
#include "ER_Doctor.h"
#include "ER_Patient.h"
#include "FD_View.h"
#include "FD_View_test.h"
#include "FD_Room_View.h"
#include "FD_Doctor_View.h"
#include "FD_Patient_View.h"
#include "IA_Room_Presenter.h"
#include "IA_Doctor_Presenter.h"
#include "IA_Patient_Presenter.h"
#include "FD_DA_Doctor_Repository_FileBasedImpl.h"
#include "FD_DA_Patient_Repository_FileBasedImpl.h"
#include "FD_DA_Room_Repository_FileBasedImpl.h"
#include "AR_UCI_Room_Administration.h"
#include "AR_UCI_Doctor_Administration.h"
#include "AR_UCI_Patient_Administration.h"
#include "IA_Room_Controller.h"
#include "IA_test_Doctor_Controller.h"
#include "IA_test_Patient_Controller.h"
#include "IA_test_Room_Controller.h"
#include "IA_test_Appointment_Controller.h"
#include "IA_Master_Controller_test.h"
#include "AR_DAI_Appointment_Repository.h"
#include "AR_UCI_Appointment_Administration_IB.h"
#include "AR_UCI_Appointment_Administration_OB.h"
#include "AR_UCI_Appointment_Administration.h"
#include "ER_Appointment.h"
#include "FD_Appointment_View.h"
#include "FD_DA_Appointment_Repository_FileBasedImpl.h"
#include "IA_Appointment_Controller.h"
#include "IA_Appointment_Presenter.h"
#include "FD_Summary_Statistics_View.h"
#include "IA_Summary_Statistics_Presenter.h"
#include "IA_Summary_Statistics_Controller.h"
#include "AR_UCI_Summary_Statistics_Creation_IB.h"
#include "AR_UCI_Summary_Statistics_Creation.h"
#include "AR_UCI_Summary_Statistics_Creation_OB.h"
#include "IA_test_Summary_Statistics_Controller.h"
using namespace std;

int main()
{

    FD_Room_View room_view{};
    FD_Doctor_View doctor_view{};
    FD_Patient_View patient_view{};
    FD_Appointment_View appointment_view{};
    IA_Room_Presenter room_presenter{room_view};
    IA_Doctor_Presenter doctor_presenter{doctor_view};
    IA_Patient_Presenter patient_presenter{patient_view};
    IA_Appointment_Presenter appointment_presenter{appointment_view};
    FD_DA_Room_Repository_FileBasedImpl room_repository{};
    FD_DA_Doctor_Repository_FileBasedImpl doctor_repository{};
    FD_DA_Patient_Repository_FileBasedImpl patient_repository{};
    FD_DA_Appointment_Repository_FileBasedImpl appointment_repository{};
    AR_UCI_Room_Administration room_administration_use_case{room_presenter, room_repository};
    AR_UCI_Doctor_Administration doctor_administration_use_case{doctor_presenter, doctor_repository};
    AR_UCI_Patient_Administration patient_administration_use_case{patient_presenter, patient_repository};
    AR_UCI_Appointment_Administration appointment_administration_use_case{appointment_presenter, appointment_repository, doctor_repository, patient_repository, room_repository};
    IA_Room_Controller room_controller{room_administration_use_case};
    IA_Doctor_Controller doctor_controller{doctor_administration_use_case};
    IA_Patient_Controller patient_controller{patient_administration_use_case};
    IA_Appointment_Controller appointment_controller{appointment_administration_use_case, doctor_administration_use_case, patient_administration_use_case, room_administration_use_case}; //noch andere dazu
    IA_test_Doctor_Controller test_Doctor_Controller{doctor_controller};
    IA_test_Room_Controller test_Room_Controller{room_controller};
    IA_test_Patient_Controller test_Patient_Controller{patient_controller};
    IA_test_Appointment_Controller test_Appointment_Controller{appointment_controller};
    FD_Resource_View_test resource_view_test{};
    IA_test_Room_Presenter test_Room_Presenter{resource_view_test};

    FD_Summary_Statistics_View Summary_Statistic_view{};
    IA_Summary_Statistics_Presenter Summary_Statistic_presenter{Summary_Statistic_view};

    AR_UCI_Summary_Statistics_Creation Summary_Statistics_use_case(Summary_Statistic_presenter, appointment_repository, doctor_repository, room_repository);

    IA_Summary_Statistics_Controller summary_statistics_controller{Summary_Statistics_use_case};

    IA_test_Summary_Statistics_Controller test_Summary_Statistics_Controller{summary_statistics_controller};

    // Appointment

    FD_View main_view{};
    FD_View_test test_view{};
    IA_Master_Controller_test application_master_controller_test{test_Room_Controller, test_Doctor_Controller,
                                                                 test_Patient_Controller, test_Appointment_Controller, test_Room_Presenter, test_Summary_Statistics_Controller};

    application_master_controller_test.control_application_start();
}
