#include "ER_appointment.h"

ER_Appointment::ER_Appointment(std::string d, std::string m, std::string y, std::string ts, std::string t, const ER_Doctor a_doctor, const ER_Patient a_patient, const ER_Room a_room)
	: day{d}, month{m}, year{y}, time_start{ts}, time{t}, doctor_id{a_doctor}, patient_id{a_patient}, room_id{a_room} {};

ER_Appointment::ER_Appointment(unsigned int id, std::string d, std::string m, std::string y, std::string ts, std::string t, const ER_Doctor a_doctor, const ER_Patient a_patient, const ER_Room a_room)
	: id{id}, day{d}, month{m}, year{y}, time_start{ts}, time{t}, doctor_id{a_doctor}, patient_id{a_patient}, room_id{a_room} {};

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
std::string ER_Appointment::get_time_start() const
{
	return time_start;
};
std::string ER_Appointment::get_time() const
{
	return time;
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
void ER_Appointment::set_time_start(std::string ts)
{
	time_start = ts;
};
void ER_Appointment::set_time(std::string t)
{
	time = t;
};
unsigned int ER_Appointment::get_doctor() const
{
	return doctor_id.get_id();
};
std::string ER_Appointment::get_doctor_full_name() const
{
	return doctor_id.get_full_name();
};
std::string ER_Appointment::get_patient_full_name() const
{
	return patient_id.get_full_name();
};
std::string ER_Appointment::get_room_full_name() const
{
	return room_id.get_full_name();
};
unsigned int ER_Appointment::get_patient() const
{
	return patient_id.get_id();
};
unsigned int ER_Appointment::get_room() const
{
	return room_id.get_room_id();
};
void ER_Appointment::set_doctor(const ER_Doctor a_doctor)
{
	doctor_id = a_doctor;
};
void ER_Appointment::set_patient(const ER_Patient a_patient)
{
	patient_id = a_patient;
};
void ER_Appointment::set_room(const ER_Room a_room)
{
	room_id = a_room;
};
std::string ER_Appointment::get_date() const
{
	std::string result{""};
	result.append(day);
	result.append(" ");
	result.append(month);
	result.append(" ");
	result.append(year);
	result.append(".");
	result.append(time_start);
	result.append(".");
	result.append(time);

	return result;
}
