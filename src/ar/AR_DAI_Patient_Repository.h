#ifndef AR_DAI_Patient_REPOSITORY_H
#define AR_DAI_Patient_REPOSITORY_H
#include <vector>
#include "ER_Patient.h"

class AR_DAI_Patient_Repository
{
public:
   virtual std::vector<ER_Patient> find_all() = 0;
   virtual ER_Patient find(unsigned int id) = 0;
   virtual ER_Patient save(const ER_Patient &Patient) = 0;
   virtual void remove(unsigned int id) = 0;
   virtual void remove_all() = 0;

   virtual ~AR_DAI_Patient_Repository() = default;
   AR_DAI_Patient_Repository() = default;
   AR_DAI_Patient_Repository(const AR_DAI_Patient_Repository &) = default;
   AR_DAI_Patient_Repository &operator=(const AR_DAI_Patient_Repository &) = default;
};

#endif /* AR_DAI_Patient_REPOSITORY_H */