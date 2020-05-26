#include "auto_test.hpp"

//ランダムな12桁のstringを返す 条件に合うもののみ作る
std::string makeRandomDate(){
    std::string year = makeRandomDateElement(0, 9999, 4);
    std::string month = makeRandomDateElement(1, 12, 2);
    std::string day = makeRandomDateElement(1, 28, 2);
    std::string hour = makeRandomDateElement(0, 23, 2);
    std::string minute = makeRandomDateElement(0, 59, 2);
    std::string output_date = year + month + day + hour + minute;
    return output_date;
}

//N桁のランダムなstring型の数値を返す
std::string makeRandomDateElement(int min, int max, int digit) {
    //init
    std::string output_string;

    //random init
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 9);

    while(true) {
        output_string = "";
        for (int i = 0; i < digit; i++) {
            output_string += std::to_string(dist(mt));
        }
        if ((min <= std::stoi(output_string)) && std::stoi(output_string) <= max) break;
    }
    return output_string;
}

std::string makeRandomDetail(){
    return "test";
}

//Nパターンのスケジュールを新たに追加
void autoInsert(Schedule& schedule, int schedule_num){
    for (int i = 0; i < schedule_num; i++) {
        schedule.setSchedule(makeRandomDate(), "テストです");
    }
}

//N回ランダムな日程で検索する
void autoSearch(Schedule& schedule, int search_num){
    std::string search_start_date;
    std::string search_end_date;
    std::multimap<std::string, std::string> range_schedule;
    //計測用変数定義
    std::chrono::system_clock::time_point chrono_start, chrono_end;
    double exec_time;

    for (int i = 0; i < search_num; i++) {
        //2つのランダムな日程を作成
        search_start_date = makeRandomDate();
        search_end_date = makeRandomDate();
        //startが大きい場合はswap
        if (search_start_date > search_end_date) std::swap(search_start_date, search_end_date);
        //検索 + 計測
        chrono_start = std::chrono::system_clock::now();
        range_schedule = schedule.getRangeSchedule(search_start_date, search_end_date);
        chrono_end = std::chrono::system_clock::now();
        exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(chrono_end-chrono_start).count();
        //計測終了 結果表示
        outputScheduleSummary(range_schedule);
        std::cout << "実行時間(ms): " << exec_time << std::endl;
    }
}

int main() {
    std::cout << "自動性能テスト" << std::endl;
    Schedule schedule(10000000);
    std::cout << "全要素数: 10" << std::endl;
    autoInsert(schedule, 10);
    autoSearch(schedule, 1);
    std::cout << "全要素数: 100" << std::endl;
    autoInsert(schedule, 90);
    autoSearch(schedule, 1);
    std::cout << "全要素数: 1000" << std::endl;
    autoInsert(schedule, 900);
    autoSearch(schedule, 1);
    std::cout << "全要素数: 10000" << std::endl;
    autoInsert(schedule, 9000);
    autoSearch(schedule, 1);
    std::cout << "全要素数: 100000" << std::endl;
    autoInsert(schedule, 90000);
    autoSearch(schedule, 1);
    std::cout << "全要素数: 1000000" << std::endl;
    autoInsert(schedule, 900000);
    autoSearch(schedule, 1);
    return 0;
}
