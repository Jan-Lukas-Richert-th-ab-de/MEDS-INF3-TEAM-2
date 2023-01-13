#ifndef ER_APPOINTMENT_H
#define ER_APPOINTMENT_H
#include <string>
#include "ER_doctor.h"
#include "ER_patient.h"
#include "ER_Room.h"

class ER_Appointment
{
public:
    ER_Appointment() = delete;
    ER_Appointment(std::string d, std::string m, std::string y, std::string ts, std::string t, const ER_Doctor a_doctor, const ER_Patient a_patient, const ER_Room a_room);                  // d, m, y, ts, t
    ER_Appointment(unsigned int id, std::string d, std::string m, std::string y, std::string ts, std::string t, const ER_Doctor a_doctor, const ER_Patient a_patient, const ER_Room a_room); // d, m, y, ts, t
    unsigned int get_id() const;
    unsigned int get_doctor() const;
    unsigned int get_patient() const;
    unsigned int get_room() const;
    std::string get_day() const;               // Tag
    std::string get_month() const;             // Monat
    std::string get_year() const;              // Jahr noch dazu eingefügt
    std::string get_time_start() const;        // Zeitanfang noch dazu eingefügt
    std::string get_time() const;              // Termindauer noch dazu eingefügt
    std::string get_date() const;              // Datum
    std::string get_doctor_full_name() const;  // Arzt
    std::string get_patient_full_name() const; // Patient
    std::string get_room_full_name() const;    // Raum

    void set_day(std::string d);         // Tag
    void set_month(std::string m);       // Monat
    void set_year(std::string y);        // Jahr noch dazu
    void set_time_start(std::string ts); // Anfang noch dazu
    void set_time(std::string t);        // Dauer noch dazu
    void set_doctor(const ER_Doctor a_doctor);
    void set_patient(const ER_Patient a_patient);
    void set_room(const ER_Room a_room);

private:
    unsigned int id{0};
    std::string day{};        // Tag
    std::string month{};      // Monat
    std::string year{};       // Jahr noch dazu
    std::string time_start{}; // Zeitanfang wann?
    std::string time{};       // Termindauer wie lange?

    ER_Doctor doctor_id; // cnst referenz benutzen, aber am Ende
    ER_Patient patient_id;
    ER_Room room_id;
};
#endif /* ER_Appointment_H */
