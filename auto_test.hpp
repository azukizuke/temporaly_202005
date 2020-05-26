#ifndef AUTO_TEST_H_
#define AUTO_TEST_H_

#include <iostream>
#include <string>
#include <utility>
#include <chrono>
#include <random>
#include <map>
#include <numeric>
#include "schedule.hpp"
#include "view.hpp"

std::string makeRandomDate();
std::string makeRandomDetail();
std::string makeRandomDateElement(int min, int max, int digit);
void autoSearch(Schedule& schedule, int search_num);
void autoInsert(Schedule& schedule, int schedule_num);

#endif //AUTO_TEST_H_
