#ifndef FD_VIEW_H
#define FD_VIEW_H
#include <string>
#include <array>


class FD_View {
   public:

      virtual ~FD_View() = default;
      FD_View() = default;
      FD_View(const FD_View&) = default;
      FD_View& operator=(const FD_View&) = default;
   protected:
      void show_header();
      void show_separator();
      void show_menu();
   private:
      const std::string OPTIONS_HEADER{"Options:"};
      const std::array<std::string,4> OPTIONS_LIST{
         "Create Entry"
        ,"Update Entry"
        ,"Delete Entry"
        ,"Quit"
      };
};
#endif /* FD_VIEW_H */