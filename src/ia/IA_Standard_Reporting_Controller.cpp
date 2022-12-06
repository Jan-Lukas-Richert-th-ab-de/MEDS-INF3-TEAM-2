#include "IA_Standard_Reporting_Controller.h"
#include <iostream>
#include <string>

IA_Standard_Reporting_Controller::IA_Standard_Reporting_Controller(AR_UCI_Standard_Reporting_IB& uci)
            : resource_uci(uci) {};
void IA_Standard_Reporting_Controller::control_list_all() {
    resource_uci.list_all();
};
