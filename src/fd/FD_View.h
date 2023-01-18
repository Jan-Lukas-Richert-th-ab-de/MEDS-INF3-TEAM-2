#ifndef FD_VIEW_H
#define FD_VIEW_H
#include <string>
#include <array>

class FD_View
{
public:
   virtual ~FD_View() = default;
   FD_View() = default;
   FD_View(const FD_View &) = default;
   FD_View &operator=(const FD_View &) = default;

protected:
   void show_header();
   void show_separator();
   void show_menu();
      void show_menu_Summary();


private:
   const std::string OPTIONS_HEADER{"Options:"};
   const std::array<std::string, 4> OPTIONS_LIST{
       "Create Entry", "Update Entry", "Delete Entry", "Quit"};
         const std::string OPTIONS_HEADER_Summary{"Options:"};
};
class FD_View_S : public FD_View 

{  protected:
   void show_header();
   void show_separator();
   void show_menu();
   

   const std::string OPTIONS_HEADER{"Options:"};
   const std::array<std::string, 5> OPTIONS_LIST{
       "room occupancy Statistics pro day","room occupancy Statistics pro week", "doctor Summary Statistics pro day", "doctor Summary Statistics pro week", "->back to main menu"};
};
#endif /* FD_VIEW_H */