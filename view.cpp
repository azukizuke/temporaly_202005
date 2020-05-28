#include "view.hpp"

//iteratorのペアを受け取り、最初から最後まで表示させる。
void outputSchedule(std::pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> input_iter) {
    for (auto iter = input_iter.first; iter != input_iter.second; ++iter) {
        std::cout << "検索結果: " << iter->first;
        std::cout << "," << iter->second << std::endl;
    }
}
