#ifndef ER_Patient_H
#define ER_Patient_H
#include <string>

class ER_Patient
{
public:
    ER_Patient() = delete;
    ER_Patient(std::string fn, std::string ln);
    ER_Patient(unsigned int id, std::string fn, std::string ln);
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

#endif /* ER_Patient_H */
