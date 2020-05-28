#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <cctype>
#include <codecvt>
#include <locale>
#include <vector>

class Schedule {
    private:
        //field
        unsigned int max_schedule_num_;
        std::multimap<std::string, std::string> schedule_child_map_;

        //function
        std::string makeOutputString(auto input_iter);
        bool isScheduleMax();
        std::pair<bool, std::string> isDateError(std::string date_index);
        bool isMonthError(int month);
        bool isDayError(int year, int month, int day);
        bool isHourError(int hour);
        bool isMinuteError(int minute);
        bool isDetailError(std::string detail);
        bool isLeapYear(int year);

    public:
        //function
        Schedule();
        Schedule(int input_max_schedule_num);
        bool setSchedule(std::string date_index, std::string detail);
        int getSize();
        std::multimap<std::string, std::string> getAllSchedule();
        std::multimap<std::string, std::string> getRangeSchedule(std::string start_date, std::string end_date);
        std::pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> getRangeScheduleIter(std::string start_date, std::string end_date);
};


#endif //SCHEDULE_H_
