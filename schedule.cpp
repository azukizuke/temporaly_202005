#include "schedule.hpp"

//Constructor
Schedule::Schedule() {
}

Schedule::Schedule(const int input_max_schedule_num){
    max_schedule_num_ = input_max_schedule_num;
}

//private
std::string Schedule::makeOutputString(const auto input_iter){
    std::string output_string = "-";
    output_string += input_iter->first;
    output_string += " : ";
    output_string += input_iter->second;
    return output_string;
}

bool Schedule::isScheduleMax(){
    if (schedule_child_map_.size() == max_schedule_num_) {
        return true;
    } else {
        return false;
    }
}

bool Schedule::isDateError(const std::string date_index) {
    const int year = std::stoi(date_index.substr(0, 4));
    const int month = std::stoi(date_index.substr(4, 2));
    const int day = std::stoi(date_index.substr(6, 2));
    const int hour = std::stoi(date_index.substr(8, 2));
    const int minute = std::stoi(date_index.substr(10, 2));
    if (isMonthError(month)) return true;
    if (isDayError(year, month, day)) return true;
    if (isHourError(hour)) return true;
    if (isMinuteError(minute)) return true;
    return false;
}

bool Schedule::isMonthError(int month) {
    // 1 ~ 12 is ok
    if (month < 1 || month > 12) return true;
    return false;
}

bool Schedule::isDayError(int year, int month, int day) {
    switch (month) {
        case 2:
            if (year % 4 == 0) {
                if (day < 1 || day > 29) return true;
            }
            if (day < 1 || day > 28) return true;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day < 1 || day > 30) return true;
            break;
        default:
            if (day < 1 || day > 31) return true;
            break;
    }
    // has not 31 month
    // Februery day check
    return false;
}

bool Schedule::isHourError(int hour) {
    if (hour < 0 || hour > 23) return true;
    return false;
}

bool Schedule::isMinuteError(int minute) {
    if (minute < 0 || minute > 59) return true;
    return false;
}

bool Schedule::isDetailError(const std::string detail) {
    return false;
}

//public
bool Schedule::setSchedule(const std::string date_index, const std::string detail) {
    std::cout << date_index << " : " << detail;
    if (isDateError(date_index)) {
        std::cout << " : date is error. not insert" << std::endl;
        return false;
    }
    if (isScheduleMax()) {
        std::cout << " : schedule is max. not insert" << std::endl;
        return false;
    }
    schedule_child_map_.insert(std::make_pair(date_index, detail));
    std::cout << " : insert success" <<std::endl;
    return true;
}

void Schedule::outputAllSchedule(){
    std::cout << "display all schedule" << std::endl;
    //rootin all element
    for (auto iter = schedule_child_map_.cbegin(); iter != schedule_child_map_.cend(); ++iter) {
        std::cout << makeOutputString(iter) << std::endl;
    }
}

void Schedule::outputRangeSchedule(const std::string start_date, const std::string end_date){
    std::cout << "display range schedule : " << start_date << "-" << end_date << std::endl;
    auto lower_iter = schedule_child_map_.lower_bound(start_date);
    auto upper_iter = schedule_child_map_.upper_bound(end_date);
    for (auto iter = lower_iter; iter != upper_iter; ++iter) {
        std::cout << makeOutputString(iter) << std::endl;
    }
}
