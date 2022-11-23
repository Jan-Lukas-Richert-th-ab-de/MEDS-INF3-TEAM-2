#ifndef AR_UCI_Patient_ADMINISTRATION_OB_H
#define AR_UCI_Patient_ADMINISTRATION_OB_H
#include <vector>
#include <map>

class AR_UCI_Patient_Administration_OB
{
public:
   virtual void present_all(const std::vector<std::map<std::string, std::string>> &data) = 0;

   virtual ~AR_UCI_Patient_Administration_OB() = default;
   AR_UCI_Patient_Administration_OB() = default;
   AR_UCI_Patient_Administration_OB(const AR_UCI_Patient_Administration_OB &) = default;
   AR_UCI_Patient_Administration_OB &operator=(const AR_UCI_Patient_Administration_OB &) = default;
};

#endif /* AR_UCI_Patient_ADMINISTRATION_OB_H */