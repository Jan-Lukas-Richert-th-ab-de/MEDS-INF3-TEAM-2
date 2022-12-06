#include "FD_Resource_View.h"
#include <iostream>
#include <iomanip>

void FD_Resource_View::show_list_view(const std::vector<std::map<std::string, std::string>> &data)
{
   show_header();
   show_separator();
   show_menu();
};
/*void FD_Resource_View::show_list_view_MAIN()
{
   show_header();
   show_separator();
   show_menu_MAIN();
};
void FD_Resource_View::show_list_view_CORE_RESSURCES()
{
   show_header();
   show_separator();
   show_menu_CORE_RESSURCES();
};*/