#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include <iostream>
#include <map>
#include <string>
#include <utility>

class Schedule {
    private:
        //field
        unsigned int max_schedule_num_;
        std::multimap<std::string, std::string> schedule_child_map_;

        //function
        std::string makeOutputString(auto input_iter);
        bool isScheduleMax();
        bool isDateError(std::string date_index);
        bool isMonthError(int month);
        bool isDayError(int year, int month, int day);
        bool isHourError(int hour);
        bool isMinuteError(int minute);
        bool isDetailError(std::string detail);

    public:
        //function
        Schedule();
        Schedule(int input_max_schedule_num);
        bool setSchedule(std::string date_index, std::string detail);
        void outputAllSchedule();
        void outputRangeSchedule(std::string start_date, std::string end_date);
};


#endif //SCHEDULE_H_
