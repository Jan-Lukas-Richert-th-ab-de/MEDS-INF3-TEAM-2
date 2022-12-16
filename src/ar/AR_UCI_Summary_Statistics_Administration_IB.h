#ifndef AR_UCI_SUMMARY_STATISTICS_ADMINISTRATION_IB_H
#define AR_UCI_SUMMARY_STATISTICS_ADMINISTRATION_IB_H
#include <string>

class AR_UCI_Summary_Statistics_Administration_IB {
   public:
      virtual void list_all() = 0; 
      virtual void update(unsigned int id, std::string day, std::string month, std::string year) = 0; //d, m +y +ts, +t

   virtual ~AR_UCI_Summary_Statistics_Administration_IB() = default;
   AR_UCI_Summary_Statistics_Administration_IB() = default;
   AR_UCI_Summary_Statistics_Administration_IB(const AR_UCI_Summary_Statistics_Administration_IB &) = default;
   AR_UCI_Summary_Statistics_Administration_IB &operator=(const AR_UCI_Summary_Statistics_Administration_IB &) = default;
};

#endif /* AR_UCI_Summary_Statistics_ADMINISTRATION_IB_H */