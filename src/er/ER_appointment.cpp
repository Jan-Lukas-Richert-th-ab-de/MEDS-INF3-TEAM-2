#include "ER_Appointment.h"

ER_Appointment::ER_Appointment(std::string d, std::string m, std::string y, std::string ts, std::string t)
   : day{d}, month{m}, year{y}, time_start{ts}, time{t} {};

ER_Appointment::ER_Appointment(unsigned int id, std::string d, std::string m, std::string y, std::string ts, std::string t)
   : id{id}, day{d}, month{m}, year{y}, time_start{ts}, time{t} {};
   

unsigned int ER_Appointment::get_id() const {
	return id;
};

std::string ER_Appointment::get_day() const {
	return day;
};
std::string ER_Appointment::get_month() const {
	return month;
};
std::string ER_Appointment::get_year() const {
	return year;
};
std::string ER_Appointment::get_time_start() const {
	return time_start;
};
std::string ER_Appointment::get_time() const {
	return time;
};
void ER_Appointment::set_day(std::string d) {
    day = d;
}; 
void ER_Appointment::set_month(std::string m) {
    month = m;
}; 
void ER_Appointment::set_year(std::string y) {
    year = y;
}; 
void ER_Appointment::set_time_start(std::string ts) {
    time_start = ts;
}; 
void ER_Appointment::set_time(std::string t) {
    time = t;
}; 



std::string ER_Appointment::get_date() const {
	std::string result{""};
	result.append(day);
	result.append(".");
	result.append(month);
	result.append(".");
	result.append(year);
	result.append(".");
	result.append(time_start);
	result.append(".");
	result.append(time);

    return result;
}
