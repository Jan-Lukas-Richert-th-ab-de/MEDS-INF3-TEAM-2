#ifndef AR_DAI_PERSON_REPOSITORY_H
#define AR_DAI_PERSON_REPOSITORY_H
#include <vector>
#include "ER_Person.h"

class AR_DAI_Person_Repository {
   public:
      virtual std::vector<ER_Person> find_all() = 0; 
      virtual ER_Person find(unsigned int id) = 0;
      virtual ER_Person save(const ER_Person& person) = 0;
      virtual void remove(unsigned int id) = 0;
      virtual void remove_all() = 0;

      virtual ~AR_DAI_Person_Repository() = default;
      AR_DAI_Person_Repository() = default;
      AR_DAI_Person_Repository(const AR_DAI_Person_Repository&) = default;
      AR_DAI_Person_Repository& operator=(const AR_DAI_Person_Repository&) = default;
};

#endif /* AR_DAI_PERSON_REPOSITORY_H */