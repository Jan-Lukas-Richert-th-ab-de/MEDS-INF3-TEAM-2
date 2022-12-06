#include "IA_Standard_Reporting_Controller.h"
#include <iostream>
#include <string>

IA_Standard_Reporting_Controller::IA_Standard_Reporting_Controller(AR_UCI_Standard_Reporting_IB& uci)
            : resource_uci(uci) {};
void IA_Standard_Reporting_Controller::control_list_all() {
    resource_uci.list_all();
};

void IA_Standard_Reporting_Controller::control_create(){
    std::cout << MESSAGE_CREATE_PERSON_FIRST_NAME_PROMPT;  
    std::string first_name{};
    std::cin >> first_name;
    std::cout << MESSAGE_CREATE_PERSON_LAST_NAME_PROMPT;  
    std::string last_name{};
    std::cin >> last_name;
    resource_uci.create(first_name, last_name);
};

void IA_Standard_Reporting_Controller::control_update(){
    std::cout << MESSAGE_UPDATE_PERSON_ID_PROMPT;  
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_UPDATE_PERSON_FIRST_NAME_PROMPT;  
    std::string first_name{};
    std::cin >> first_name;
    std::cout << MESSAGE_UPDATE_PERSON_LAST_NAME_PROMPT;  
    std::string last_name{};
    std::cin >> last_name;
    resource_uci.update(id, first_name, last_name);
};

void IA_Standard_Reporting_Controller::control_remove(){
    std::cout << MESSAGE_REMOVE_PERSON_ID_PROMPT;  
    unsigned int id{};
    std::cin >> id;
    std::cout << MESSAGE_REMOVE_PERSON_CONFIRMATION_PROMPT; 
    char choice{};
    std::cin >> choice; 
    if (choice == 'y') 
        resource_uci.remove(id);
    else
        resource_uci.list_all();
};