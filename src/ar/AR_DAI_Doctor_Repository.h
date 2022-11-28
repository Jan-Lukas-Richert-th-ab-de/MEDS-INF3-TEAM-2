#ifndef AR_DAI_DOCTOR_REPOSITORY_H
#define AR_DAI_DOCTOR_REPOSITORY_H
#include <vector>
#include "ER_Doctor.h"

class AR_DAI_Doctor_Repository
{
public:
   virtual std::vector<ER_Doctor> find_all() = 0;
   virtual ER_Doctor find(unsigned int id) = 0;
   virtual ER_Doctor save(const ER_Doctor &Doctor) = 0;
   virtual void remove(unsigned int id) = 0;
   virtual void remove_all() = 0;

   virtual ~AR_DAI_Doctor_Repository() = default;
   AR_DAI_Doctor_Repository() = default;
   AR_DAI_Doctor_Repository(const AR_DAI_Doctor_Repository &) = default;
   AR_DAI_Doctor_Repository &operator=(const AR_DAI_Doctor_Repository &) = default;
};

#endif /* AR_DAI_Doctor_REPOSITORY_H */