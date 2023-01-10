#include "ER_Doctor.h"

ER_Doctor::ER_Doctor(std::string fn, std::string ln, std::string dc)
	: first_name{fn}, last_name{ln}, doctors_specialties{dc} {};

ER_Doctor::ER_Doctor(unsigned int id, std::string fn, std::string ln, std::string dc)
	: id{id}, first_name{fn}, last_name{ln}, doctors_specialties{dc} {};

unsigned int ER_Doctor::get_id() const
{
	return id;
};

std::string ER_Doctor::get_first_name() const
{
	return first_name;
};
std::string ER_Doctor::get_last_name() const
{
	return last_name;
};
std::string ER_Doctor::get_doctors_specialties() const
{
	return doctors_specialties;
};
void ER_Doctor::set_first_name(std::string fn)
{
	first_name = fn;
};
void ER_Doctor::set_last_name(std::string ln)
{
	last_name = ln;
};
void ER_Doctor::set_doctors_specialties(std::string dc)
{
	doctors_specialties = dc;
};

std::string ER_Doctor::get_full_name() const
{
	std::string result{""};
	result.append(first_name);
	result.append("");
	result.append(last_name);
	result.append("");
	result.append(doctors_specialties);
	return result;
}
