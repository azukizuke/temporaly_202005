#include "view.hpp"

void outputScheduleSummary(std::multimap<std::string, std::string> input_schedule) {
    std::cout << "検索結果の要素数：";
    std::cout << input_schedule.size() << std::endl;
    auto start_iter = input_schedule.cbegin();
    auto end_iter = input_schedule.crbegin();
    std::cout << "最初の要素：";
    std::cout <<  start_iter->first;
    std::cout << "：";
    std::cout <<  start_iter->second << std::endl;
    std::cout << "最後の要素：";
    std::cout <<  end_iter->first;
    std::cout << "：";
    std::cout <<  end_iter->second << std::endl;
}

void outputScheduleAll(std::multimap<std::string, std::string> input_schedule) {
    for (auto iter = input_schedule.cbegin(); iter != input_schedule.cend(); ++iter) {
        std::cout << iter->first;
        std::cout << iter->second << std::endl;
    }
}

//iteratorのペアを受け取り、最初から最後まで表示させる。
void outputSchedule(std::pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> input_iter) {
    for (auto iter = input_iter.first; iter != input_iter.second; ++iter) {
        std::cout << "検索結果: " << iter->first;
        std::cout << "," << iter->second << std::endl;
    }
}
