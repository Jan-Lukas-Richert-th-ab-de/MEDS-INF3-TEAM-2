#ifndef ER_PERSON_H
#define ER_PERSON_H
#include <string>

class ER_Person {
public:
    ER_Person() = delete;
    ER_Person(std::string fn, std::string ln);
    ER_Person(unsigned int id, std::string fn, std::string ln);
    unsigned int get_id() const;
    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_full_name() const;
    void set_first_name(std::string fn); 
    void set_last_name(std::string ln); 

private:
    unsigned int id{0};
    std::string first_name{};
    std::string last_name{};
};

#endif /* ER_PERSON_H */
