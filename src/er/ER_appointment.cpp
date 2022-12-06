#include "ER_Appointment.h"

ER_Appointment::ER_Appointment(std::string d, std::string m, std::string y)
	: day{d}, month{m}, year{y} {};

ER_Appointment::ER_Appointment(unsigned int id, std::string d, std::string m, std::string y)
	: id{id}, day{d}, month{m}, year{y} {};

unsigned int ER_Appointment::get_id() const
{
	return id;
};

std::string ER_Appointment::get_day() const
{
	return day;
};
std::string ER_Appointment::get_month() const
{
	return month;
};
std::string ER_Appointment::get_year() const
{
	return year;
};
void ER_Appointment::set_day(std::string d)
{
	day = d;
};
void ER_Appointment::set_month(std::string m)
{
	month = m;
};
void ER_Appointment::set_year(std::string y)
{
	year = y;
};

std::string ER_Appointment::get_date() const
{
	std::string result{""};
	result.append(day);
	result.append(" ");
	result.append(month);
	result.append(" ");
	result.append(year);
	return result;
}
