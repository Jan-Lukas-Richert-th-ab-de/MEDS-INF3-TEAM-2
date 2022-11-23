#iddef ER_APPOINTMENT_H
#define ER_APPOINTMENT_H
#include <string>

class ER_Appointment {
public:
    ER_Appointment() = delete;
    ER_Appointment(std::string d, std::string m, std::string y); //d, m, y
    ER_Appointment(unsigned int id, std::string d, std::string m, std::string y); // d, m, y
    unsigned int get_id() const;
    std::string get_day() const; //Tag
    std::string get_month() const;//Monat
    std::string get_year() const; // Jahr noch dazu eingefügt
    std::string get_date() const; //Datum
    void set_day(std::string d); //Tag
    void set_month(std::string m); //Monat
    void set_year(std::string y); // Jahr noch dazu 


private:
    unsigned int id{0};
    std::string day{};//Tag
    std::string month{};//Monat
    std::string year{}; //Jahr noch dazu

};

#endif /* ER_Appointment_H */
