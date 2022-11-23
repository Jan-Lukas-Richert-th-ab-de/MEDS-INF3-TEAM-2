#include "ER_Person.h"

ER_Person::ER_Person(std::string fn, std::string ln)
   : first_name{fn}, last_name{ln} {};

ER_Person::ER_Person(unsigned int id, std::string fn, std::string ln)
   : id{id}, first_name{fn}, last_name{ln} {};

unsigned int ER_Person::get_id() const {
	return id;
};

std::string ER_Person::get_first_name() const {
	return first_name;
};
std::string ER_Person::get_last_name() const {
	return last_name;
};
void ER_Person::set_first_name(std::string fn) {
    first_name = fn;
}; 
void ER_Person::set_last_name(std::string ln) {
    last_name = ln;
}; 

std::string ER_Person::get_full_name() const {
	std::string result{""};
	result.append(first_name);
	result.append(" ");
	result.append(last_name);
    return result;
}
