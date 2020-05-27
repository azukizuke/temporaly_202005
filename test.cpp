#include "test.hpp"
#include "view.hpp"

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
    schedule.setSchedule("203011150307", "テスト１２");
    schedule.setSchedule("203011150306", "テスト１１");
    schedule.setSchedule("203011150305", "テスト１０");
    //日時入力の境界値テスト エラーのものがエラー出力されればOK
    //最大日程、最小日程
    schedule.setSchedule("000001010000", "成功、最小の日程");
    schedule.setSchedule("999912312359", "成功、最大の日程");
    //年
    schedule.setSchedule("000011111111", "成功、年、最小値");
    schedule.setSchedule("888811111111", "成功、年、最大値");
    //月
    schedule.setSchedule("999900111111", "エラー、月、00");
    schedule.setSchedule("888801111111", "成功、月、最小値");
    schedule.setSchedule("888812111111", "成功、月、最大値");
    schedule.setSchedule("999913111111", "エラー、月、13");
    //日
    schedule.setSchedule("999912001111", "エラー、日、00");
    schedule.setSchedule("888812011111", "成功、日、最小値");
    schedule.setSchedule("888812311111", "成功、日、最大値");
    schedule.setSchedule("999912320237", "エラー、日、32");
    //日 30日までの月
    schedule.setSchedule("999911001111", "エラー、日、1100");
    schedule.setSchedule("888811011111", "成功、日、最小値");
    schedule.setSchedule("888811301111", "成功、日、1130");
    schedule.setSchedule("999911311111", "エラー、日、1131");
    //日 2月
    schedule.setSchedule("888802281111", "成功、日、0228");
    schedule.setSchedule("888802291111", "成功、日、0229、うるう年");
    schedule.setSchedule("880002291111", "成功、日、0229、400倍数うるう年");
    schedule.setSchedule("999902291111", "エラー、日、平年0229");
    schedule.setSchedule("990002291111", "エラー、日、0229、閏年例外100倍数");
    //時間
    schedule.setSchedule("888811110011", "成功、時、最小値");
    schedule.setSchedule("888811112311", "成功、時、最大値");
    schedule.setSchedule("999911112411", "エラー、時、24");
    //分
    schedule.setSchedule("888811111100", "成功、分、最小値");
    schedule.setSchedule("888811111159", "成功、分、最大値");
    schedule.setSchedule("999912310260", "エラー、分、60");
    //用件
    schedule.setSchedule("888802281111", "成功、要件文字数２５６文字あああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああ");
    schedule.setSchedule("999902281111", "エラー、要件文字数の超過あああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああ");
    //その他入力誤り
    schedule.setSchedule("99990229111", "エラー、桁数不足");
    schedule.setSchedule("999902291111123", "エラー、桁数超過");
    schedule.setSchedule("99990229111a", "エラー、数値出ない文字が含まれる");
    schedule.setSchedule("abcdefghijkl", "エラー、全部数値じゃない");

    std::cout << std::endl;
    std::cout << "----test 全要素表示----(000001010000,999912312359での検索)" << std::endl;
    std::cout << std::endl;

    outputSchedule(schedule.getRangeScheduleIter("000001010000", "999912312359"));

    std::cout << std::endl;
    std::cout << "----test テスト6,7,8だけ検索表示----(入力20250108108、202501100109)" << std::endl;
    outputSchedule(schedule.getRangeScheduleIter("202501080108", "202501100109"));
    std::cout << std::endl;
    return 0;
}
