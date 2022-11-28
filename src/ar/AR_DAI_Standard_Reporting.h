#ifndef AR_DAI_STANDARD_REPORTING.H
#define AR_DAI_STANDARD_REPORTING.H
#include <vector>
#include "ER_Person.h"

class AR_DAI_Standard_Reporting {
   public:
      virtual std::vector<ER_Person> find_all() = 0; 
      virtual ER_Person find(unsigned int id) = 0;
      virtual ER_Person save(const ER_Person& person) = 0;
      virtual void remove(unsigned int id) = 0;
      virtual void remove_all() = 0;

      virtual ~AR_DAI_Standard_Reporting() = default;
      AR_DAI_Standard_Reporting() = default;
      AR_DAI_Standard_Reporting(const AR_DAI_Standard_Reporting&) = default;
      AR_DAI_Standard_Reporting& operator=(const AR_DAI_Standard_Reporting&) = default;
};

#endif /* AR_DAI_STANDARD_REPORTING.H */