#ifndef IA_TEST_SUMMARY_STATISTICS_CONTROLLER
#define IA_TEST_SUMMARY_STATISTICST_CONTROLLER
#include "IA_Summary_Statistics_Controller.h"

class IA_test_Summary_Statistics_Controller
{
public:
    IA_test_Summary_Statistics_Controller(
        IA_Summary_Statistics_Controller &a_Summary_Statistics_Controller);
    void control_application_start();
    void chooce_Summary_Statistics();

private:
    IA_Summary_Statistics_Controller &Summary_Statistics_Controller;

      void
    show_menu_message_prompt();
    void show_menu_message_unexpected_input();
};
#endif /* test_Summary_Statistics_Controller */