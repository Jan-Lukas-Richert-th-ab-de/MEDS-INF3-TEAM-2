#ifndef AR_UCI_DOCTOR_ADMINISTRATION_IB_H
#define AR_UCI_DOCTOR_ADMINISTRATION_IB_H
#include <string>

class AR_UCI_Doctor_Administration_IB
{
public:
  virtual void list_all() = 0;
  virtual void create(std::string first_name, std::string last_name, std::string doctors_specialties) = 0;
  virtual void update(unsigned int id, std::string first_name, std::string last_name, std::string doctors_specialties) = 0;
  virtual void remove(unsigned int id) = 0;

   virtual ~AR_UCI_Doctor_Administration_IB() = default;
   AR_UCI_Doctor_Administration_IB() = default;
   AR_UCI_Doctor_Administration_IB(const AR_UCI_Doctor_Administration_IB &) = default;
   AR_UCI_Doctor_Administration_IB &operator=(const AR_UCI_Doctor_Administration_IB &) = default;
};

#endif /* AR_UCI_Doctor_ADMINISTRATION_IB_H */