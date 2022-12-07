#ifndef AR_UCI_APPOINTMENT_ADMINISTRATION_IB_H
#define AR_UCI_APPOINTMENT_ADMINISTRATION_IB_H
#include <string>

class AR_UCI_Appointment_Administration_IB {
   public:
      virtual void list_all() = 0; 
      virtual void create(std::string day, std::string month, std::string year, std::string time_start, std::string time) = 0; //d, m +y +ts, +t
      virtual void update(unsigned int id, std::string day, std::string month, std::string year, std::string time_start, std::string time) = 0; //d, m +y +ts, +t
      virtual void remove(unsigned int id) = 0;

      virtual ~AR_UCI_Appointment_Administration_IB() = default;
      AR_UCI_Appointment_Administration_IB() = default;
      AR_UCI_Appointment_Administration_IB(const AR_UCI_Appointment_Administration_IB&) = default;
      AR_UCI_Appointment_Administration_IB& operator=(const AR_UCI_Appointment_Administration_IB&) = default;
};

#endif /* AR_UCI_Appointment_ADMINISTRATION_IB_H */