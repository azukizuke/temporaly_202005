#include "manual_test.hpp"

int main() {
    Schedule schedule(300);
    //test insert
    schedule.setSchedule("000001010101", "テスト０");
    std::cout << std::endl;
    std::cout << "----test displey----" << std::endl;
    std::cout << std::endl;

    //test display
    schedule.outputAllSchedule();
    schedule.outputRangeSchedule("202011140000","202011180000");
    schedule.outputRangeSchedule("202011150305","202011150306");
    schedule.outputRangeSchedule("202011150305","999912300000");
    return 0;
}
