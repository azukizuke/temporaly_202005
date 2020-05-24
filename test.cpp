#include "test.hpp"

int main() {
    Schedule schedule(300);
    //test insert
    schedule.setSchedule("000001010101", "test0000");
    schedule.setSchedule("200011101210", "test0");
    schedule.setSchedule("200011101211", "test1");
    schedule.setSchedule("200011101212", "test2");
    schedule.setSchedule("200011101213", "test3");
    schedule.setSchedule("200011101214", "test4");
    schedule.setSchedule("202501080108", "test8");
    schedule.setSchedule("202501090109", "test9");
    schedule.setSchedule("202501090109", "test9-2");
    schedule.setSchedule("202501100110", "test10");
    schedule.setSchedule("202011150305", "test5");
    schedule.setSchedule("202011150306", "test6");
    schedule.setSchedule("202011150307", "test7");
    //border ok
    schedule.setSchedule("999901111111", "ok-month-min");
    schedule.setSchedule("999912111111", "ok-month-max");
    schedule.setSchedule("999910011111", "ok-day-min");
    schedule.setSchedule("999910311111", "ok-day-max");
    schedule.setSchedule("999910100111", "ok-day-min");
    schedule.setSchedule("999910312311", "ok-day-max");
    schedule.setSchedule("999911302311", "ok-day-1130");
    schedule.setSchedule("999902281111", "ok-day-0228");
    schedule.setSchedule("999802281111", "ok-day-0229-uruu");
    schedule.setSchedule("999910101100", "ok-minute-min");
    schedule.setSchedule("999910101159", "ok-minute-max");
    //err
    schedule.setSchedule("999900140237", "error-month-00");
    schedule.setSchedule("999913140237", "error-month-13");
    schedule.setSchedule("999912000237", "error-day-00");
    schedule.setSchedule("999912320237", "error-day-32");
    schedule.setSchedule("999911312311", "error-day-1131");
    schedule.setSchedule("999902291111", "error-day-0229");
    schedule.setSchedule("999912392413", "error-hour-24");
    schedule.setSchedule("999912390260", "error-minute-60");

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
