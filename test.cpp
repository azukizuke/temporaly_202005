#include "test.hpp"

int main() {
    Schedule schedule(300);
    //test insert test
    schedule.setSchedule("000001010101", "テスト０");
    schedule.setSchedule("200011101210", "テスト１");
    schedule.setSchedule("200011101211", "テスト２");
    schedule.setSchedule("200011101212", "テスト３");
    schedule.setSchedule("200011101213", "テスト４");
    schedule.setSchedule("200011101214", "テスト５");
    schedule.setSchedule("202501080108", "テスト６");
    schedule.setSchedule("202501090109", "テスト７");
    schedule.setSchedule("202501090109", "テスト８");
    schedule.setSchedule("202501100110", "テスト９");
    schedule.setSchedule("203011150306", "テスト１１");
    schedule.setSchedule("203011150305", "テスト１０");
    schedule.setSchedule("203011150307", "テスト１２");
    //border ok
    schedule.setSchedule("999901111111", "成功、月、最小値");
    schedule.setSchedule("999912111111", "成功、月、最大値");
    schedule.setSchedule("999910011111", "成功、日、min");
    schedule.setSchedule("999910311111", "成功、日、最大値");
    schedule.setSchedule("999910100111", "成功、日、min");
    schedule.setSchedule("999910312311", "成功、日、最大値");
    schedule.setSchedule("999911302311", "成功、日、1130");
    schedule.setSchedule("999902281111", "成功、日、0228");
    schedule.setSchedule("888802291111", "成功、日、0229、leap");
    schedule.setSchedule("880002291111", "成功、日、0229、400leap");
    schedule.setSchedule("999910101100", "成功、分、min");
    schedule.setSchedule("999910101159", "成功、分、最大値");
    schedule.setSchedule("999902281111", "成功、要件文字数２５６文字あああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああ");
    //err
    schedule.setSchedule("999900140237", "エラー、月、00");
    schedule.setSchedule("999913140237", "エラー、月、13");
    schedule.setSchedule("999912000237", "エラー、日、00");
    schedule.setSchedule("999912320237", "エラー、日、32");
    schedule.setSchedule("999911312311", "エラー、日、1131");
    schedule.setSchedule("999902291111", "エラー、日、0229");
    schedule.setSchedule("999912312413", "エラー、時、24");
    schedule.setSchedule("999912310260", "エラー、分、60");
    schedule.setSchedule("870002291111", "エラー、日、0229、閏年例外");
    schedule.setSchedule("87000229111", "エラー、桁数不足");
    schedule.setSchedule("870002291111123", "エラー、桁数超過");
    schedule.setSchedule("87000229111a", "エラー、数値出ない文字が含まれる");
    schedule.setSchedule("llllllllllll", "エラー、全部数値じゃない");
    schedule.setSchedule("999902281111", "エラー、要件文字数の超過あああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああ");

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
