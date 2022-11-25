#include <iostream>
#include "ER_Doctor.h"
#include "FD_View.h"
#include "FD_Doctor_View.h"
#include "IA_Doctor_Presenter.h"
#include "FD_DA_Doctor_Repository_FileBasedImpl.h"
#include "AR_UCI_Doctor_Administration.h"
#include "IA_Doctor_Controller.h"
#include "IA_Master_Controller.h"

using namespace std;

int main()
{
    FD_Doctor_View person_view{};
    IA_Doctor_Presenter person_presenter{person_view};
    FD_DA_Doctor_Repository_FileBasedImpl person_repository{};
    AR_UCI_Doctor_Administration person_administration_use_case{person_presenter, person_repository};
    IA_Doctor_Controller person_controller{person_administration_use_case};

    FD_View main_view{};
    IA_Master_Controller application_master_controller{person_controller};

    application_master_controller.control_application_start();
}
