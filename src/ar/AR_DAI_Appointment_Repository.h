#ifndef AR_DAI_APPOINTMENT_REPOSITORY_H
#define AR_DAI_APPOINTMENT_REPOSITORY_H
#include <vector>
#include "ER_Appointment.h"

class AR_DAI_Appointment_Repository {  //Person->Appointment
   public:
      virtual std::vector<ER_Appointment> find_all() = 0; 
      virtual ER_Appointment find(unsigned int id) = 0;
      virtual ER_Appointment save(const ER_Appointment& appointment) = 0;
      virtual void remove(unsigned int id) = 0;
      virtual void remove_all() = 0;

      virtual ~AR_DAI_Appointment_Repository() = default;
      AR_DAI_Appointment_Repository() = default;
      AR_DAI_Appointment_Repository(const AR_DAI_Appointment_Repository&) = default;
      AR_DAI_Appointment_Repository& operator=(const AR_DAI_Appointment_Repository&) = default;
};

#endif /* AR_DAI_Appointment_REPOSITORY_H */