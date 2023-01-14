#ifndef FD_PERSON_VIEW_H
#define FD_PERSON_VIEW_H
#include "FD_Resource_View.h"
#include <vector>
#include <map>

class FD_Person_View : public FD_Resource_View
{
public:
    void show_list_view(const std::vector<std::map<std::string, std::string>> &data);
    void show_list_view_data(const std::vector<std::map<std::string, std::string>> &data);

private:
    void show_list_empty_message();
    void show_list_header();
    void show_column_header();
    void show_list_contents(const std::vector<std::map<std::string, std::string>> &data);
};

#endif /* FD_PERSON_VIEW_H */