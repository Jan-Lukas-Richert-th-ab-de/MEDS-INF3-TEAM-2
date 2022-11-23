#ifndef ER_Doctor_H
#define ER_Doctor_H
#include <string>

class ER_Doctor
{
public:
    ER_Doctor() = delete;
    ER_Doctor(std::string fn, std::string ln);
    ER_Doctor(unsigned int id, std::string fn, std::string ln, std::string dc);
    unsigned int get_id() const;
    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_doctors_specialties() const;
    std::string get_full_name() const;
    void set_first_name(std::string fn);
    void set_last_name(std::string ln);
    void set_doctors_specialties(std::string ds);

private:
    unsigned int id{0};
    std::string first_name{};
    std::string last_name{};
    std::string doctors_specialties{};
};

#endif /* ER_Doctor_H */
