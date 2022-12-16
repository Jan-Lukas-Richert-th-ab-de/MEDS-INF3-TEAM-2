#ifndef AR_UCI_SUMMARY_STATISTICS_ADMINISTRATION_OB_H
#define AR_UCI_SUMMARY_STATISTICS_ADMINISTRATION_OB_H
#include <vector>
#include <map>
#include <string> //string include

class AR_UCI_Summary_Statistics_Administration_OB { //->Summary_Statistics
   public:
      virtual void present_all(const std::vector<std::map<std::string, std::string>>& data) = 0; //data?

      virtual ~AR_UCI_Summary_Statistics_Administration_OB() = default;
      AR_UCI_Summary_Statistics_Administration_OB() = default;
      AR_UCI_Summary_Statistics_Administration_OB(const AR_UCI_Summary_Statistics_Administration_OB&) = default;
      AR_UCI_Summary_Statistics_Administration_OB& operator=(const AR_UCI_Summary_Statistics_Administration_OB&) = default;
};

#endif /* AR_UCI_Summary_Statistics_ADMINISTRATION_OB_H */