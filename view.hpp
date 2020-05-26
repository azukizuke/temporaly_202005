#ifndef VIEW_H_
#define VIEW_H_

#include <iostream>
#include <string>
#include <map>
#include <utility>

void outputScheduleSummary(std::multimap<std::string, std::string> input_schedule);
void outputScheduleAll(std::multimap<std::string, std::string> input_schedule);
void outputSchedule(std::pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> input_iter);

#endif //VIEW_H_
