#include <iostream>
#include "Room/ER_Room.h"
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
#include "IA_Master_Controller_test.h"

using namespace std;

int main()
{

    FD_Room_View room_view{};
    FD_Doctor_View doctor_view{};
    FD_Patient_View patient_view{};
    IA_Room_Presenter room_presenter{room_view};
    IA_Doctor_Presenter doctor_presenter{doctor_view};
    IA_Patient_Presenter patient_presenter{patient_view};
    FD_DA_Room_Repository_FileBasedImpl room_repository{};
    FD_DA_Doctor_Repository_FileBasedImpl doctor_repository{};
    FD_DA_Patient_Repository_FileBasedImpl patient_repository{};
    AR_UCI_Room_Administration room_administration_use_case{room_presenter, room_repository};
    AR_UCI_Doctor_Administration doctor_administration_use_case{doctor_presenter, doctor_repository};
    AR_UCI_Patient_Administration patient_administration_use_case{patient_presenter, patient_repository};
    IA_Room_Controller room_controller{room_administration_use_case};
    IA_Doctor_Controller doctor_controller{doctor_administration_use_case};
    IA_Patient_Controller patient_controller{patient_administration_use_case};
    IA_test_Doctor_Controller test_Doctor_Controller{doctor_controller};
    IA_test_Room_Controller test_Room_Controller{room_controller};
    IA_test_Patient_Controller test_Patient_Controller{patient_controller};
    FD_Resource_View_test resource_view_test{};
    IA_test_Room_Presenter test_Room_Presenter{resource_view_test};

    FD_View main_view{};
    FD_View_test test_view{};
    IA_Master_Controller_test application_master_controller_test{test_Room_Controller, test_Doctor_Controller, test_Patient_Controller, test_Room_Presenter};

    application_master_controller_test.control_application_start();
}
