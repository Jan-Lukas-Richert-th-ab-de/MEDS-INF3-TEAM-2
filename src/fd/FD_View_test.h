#ifndef FD_VIEW_TEST_H
#define FD_VIEW_TEST_H
#include <string>
#include <array>

class FD_View_test
{
public:
   virtual ~FD_View_test() = default;
   FD_View_test() = default;
   FD_View_test(const FD_View_test &) = default;
   FD_View_test &operator=(const FD_View_test &) = default;

protected:
   void show_header();
   void show_separator();
   void show_menu();

private:
   const std::string OPTIONS_HEADER{"Options:"};
   const std::array<std::string, 4> OPTIONS_LIST{
       "Administer Patient", "Administer Doctor", "Administer Room", "Quit"};
};
#endif /* FD_VIEW_H */