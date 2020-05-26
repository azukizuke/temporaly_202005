#include "view.hpp"

void outputScheduleSummary(std::multimap<std::string, std::string> input_schedule) {
    std::cout << "検索結果の要素数：";
    std::cout << input_schedule.size() << std::endl;
    auto start_iter = input_schedule.cbegin();
    auto end_iter = input_schedule.cend();
    std::cout << "最初の要素：";
    std::cout <<  start_iter->first;
    std::cout << "：";
    std::cout <<  start_iter->second << std::endl;
    std::cout << "最後の要素：";
    std::cout <<  start_iter->first;
    std::cout << "：";
    std::cout <<  start_iter->second << std::endl;
}

void outputScheduleAll(std::multimap<std::string, std::string> input_schedule) {
    for (auto iter = input_schedule.cbegin(); iter != input_schedule.cend(); ++iter) {
        std::cout << iter->first;
        std::cout << iter->second << std::endl;
    }
}
