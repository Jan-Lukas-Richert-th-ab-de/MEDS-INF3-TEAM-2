#ifndef AR_UCI_APPOINTMENT_ADMINISTRATION_OB_H
#define AR_UCI_APPOINTMENT_ADMINISTRATION_OB_H
#include <vector>
#include <map>
#include <string> //string include

class AR_UCI_Appointment_Administration_OB
{ //->Appointment
public:
   virtual void present_all(const std::vector<std::map<std::string, std::string>> &data) = 0; // data?

   virtual ~AR_UCI_Appointment_Administration_OB() = default;
   AR_UCI_Appointment_Administration_OB() = default;
   AR_UCI_Appointment_Administration_OB(const AR_UCI_Appointment_Administration_OB &) = default;
   AR_UCI_Appointment_Administration_OB &operator=(const AR_UCI_Appointment_Administration_OB &) = default;
};

#endif /* AR_UCI_Appointment_ADMINISTRATION_OB_H */