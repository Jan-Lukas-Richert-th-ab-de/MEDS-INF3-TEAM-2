#ifndef FD_RESOURCE_VIEW_TEST_H
#define FD_RESOURCE_VIEW_TEST_H
#include "FD_View_test.h"
#include <vector>
#include <map>

class FD_Resource_View_test : public FD_View_test
{
public:
   virtual void show_list_view();

   virtual ~FD_Resource_View_test() = default;
   FD_Resource_View_test() = default;
   FD_Resource_View_test(const FD_Resource_View_test &) = default;
   FD_Resource_View_test &operator=(const FD_Resource_View_test &) = default;
};

#endif /* FD_RESOURCE_VIEW_H */