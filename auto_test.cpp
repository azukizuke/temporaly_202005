#include "auto_test.hpp"

//ランダムな12桁のstringを返す 条件に合うもののみ作成
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
        schedule.setSchedule(makeRandomDate(), "性能テスト用用件");
    }
}

//N回ランダムな日程で検索し、検索にかかった時間の最大値と最小値を出力する
void autoSearch(Schedule& schedule, int search_num){
    std::string search_start_date;
    std::string search_end_date;
    std::multimap<std::string, std::string> range_schedule;
    std::chrono::system_clock::time_point chrono_start, chrono_end;
    double exec_time;
    std::vector<double> exec_time_vector;

    std::cout << "全要素数: " << schedule.getSize() << std::endl;
    //N回検索ルーチン
    for (int i = 0; i < search_num; i++) {
        //2つのランダムな日程を作成
        search_start_date = makeRandomDate();
        search_end_date = makeRandomDate();
        //startが大きい場合はswap
        if (search_start_date > search_end_date) std::swap(search_start_date, search_end_date);
        //計測開始
        chrono_start = std::chrono::system_clock::now();
        //検索実施。始点と終点のiteratorを結果として受け取る。iterator受け取るまでを経過時間。実際の表示は計測に含まない。また、出力もものすごい時間がかかるので本プログラムでは省略
        std::pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> iter_pair = schedule.getRangeScheduleIter(search_start_date, search_end_date);
        chrono_end = std::chrono::system_clock::now();
        exec_time = std::chrono::duration_cast<std::chrono::microseconds>(chrono_end-chrono_start).count();
        //計測終了 経過時間はvectorへ入れる
        exec_time_vector.push_back(exec_time);
    }
    //最小時間と最大時間を出力
    std::cout << "  検索時間(最小値、平均値、最大値)(μs)：";
    std::cout << *std::min_element(exec_time_vector.begin(), exec_time_vector.end());
    std::cout << ", ";
    std::cout << std::accumulate(exec_time_vector.begin(), exec_time_vector.end(), 0) / exec_time_vector.size();
    std::cout << ", ";
    std::cout << *std::max_element(exec_time_vector.begin(), exec_time_vector.end()) << std::endl << std::endl;
}

int main() {
    int test_num = 10000;

    std::cout << "性能テスト" << std::endl;
    std::cout << "各要素数の予定表に対してランダムな日程で" << test_num << "回検索を実施。最大時間と最小時間を出力" << std::endl << std::endl;
    Schedule schedule(100000000);

    //10
    autoInsert(schedule, 10);
    autoSearch(schedule, test_num);

    //100
    autoInsert(schedule, 90);
    autoSearch(schedule, test_num);

    //1000
    autoInsert(schedule, 900);
    autoSearch(schedule, test_num);

    //10000
    autoInsert(schedule, 9000);
    autoSearch(schedule, test_num);

    //100000
    autoInsert(schedule, 90000);
    autoSearch(schedule, test_num);

    //1000000
    autoInsert(schedule, 900000);
    autoSearch(schedule, test_num);

    //10000000
    //1千万は準備のinsertに30分くらい時間かかるのでコメントアウト
    //autoInsert(schedule, 9000000);
    //autoSearch(schedule, test_num);
    
    return 0;
}
