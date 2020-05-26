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

std::pair<bool, std::string> Schedule::isDateError(const std::string date_index) {
    //index length check
    if (date_index.length() != 12) return std::make_pair(true, "length");
    //not number check
    if (!std::all_of(date_index.cbegin(), date_index.cend(), isdigit)) return std::make_pair(true, "not number");
    //every date elemental check
    const int year = std::stoi(date_index.substr(0, 4));
    const int month = std::stoi(date_index.substr(4, 2));
    const int day = std::stoi(date_index.substr(6, 2));
    const int hour = std::stoi(date_index.substr(8, 2));
    const int minute = std::stoi(date_index.substr(10, 2));
    if (isMonthError(month)) return std::make_pair(true, "month");
    if (isDayError(year, month, day)) return std::make_pair(true, "day");
    if (isHourError(hour)) return std::make_pair(true, "hour");
    if (isMinuteError(minute)) return std::make_pair(true, "minute");
    return std::make_pair(false, "noerro");
}

bool Schedule::isMonthError(int month) {
    // 1 ~ 12 is ok
    if (month < 1 || month > 12) return true;
    return false;
}

bool Schedule::isDayError(int year, int month, int day) {
    switch (month) {
        case 2:
            //Leap Year Februery
            if (isLeapYear(year)) {
                if (day < 1 || day > 29) return true;
                break;
            }
            //Normal Year Februery
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
    return false;
}

bool Schedule::isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
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
    //convert multi byte
    std::wstring wstring_detail = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(detail);
    if (wstring_detail.length() > 256) return true;
    return false;
}

//public
bool Schedule::setSchedule(const std::string date_index, const std::string detail) {

    // check date error
    std::pair<bool, std::string> pair_date_error = isDateError(date_index);
    bool is_date_error = pair_date_error.first;
    std::string string_date_error = pair_date_error.second;
    if (is_date_error) {
        std::cerr << "[追加エラー]" << string_date_error;
        std::cerr << "日程エラーのため本日程は追加しません";
        std::cerr << "(";
        std::cerr << date_index << " : ";
        std::cerr << detail;
        std::cerr << ")" << std::endl;
        return false;
    }
    // max schedule map check
    if (isScheduleMax()) {
        std::cerr << "[追加エラー]スケジュール数が最大のため追加ができません";
        std::cerr << "(";
        std::cerr << date_index << " : ";
        std::cerr << detail;
        std::cerr << ")" << std::endl;
        return false;
    }

    // detail error check
    if (isDetailError(detail)) {
        std::cerr << "[追加エラー]用件が256文字を超えているため本日程は追加致しません";
        std::cerr << "(";
        std::cerr << date_index << " : ";
        std::cerr << detail;
        std::cerr << ")" << std::endl;
        return false;
    }
    
    //success insert
    schedule_child_map_.insert(std::make_pair(date_index, detail));
    //std::cout << " : insert success" <<std::endl; //debug用途のための成功表示
    return true;
}

std::pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> Schedule::getRangeScheduleIter(std::string start_date, std::string end_date){
    auto lower_iter = schedule_child_map_.lower_bound(start_date);
    auto upper_iter = schedule_child_map_.upper_bound(end_date);
    return std::make_pair(lower_iter, upper_iter);
}

int Schedule::getSize() {
    return schedule_child_map_.size();
}
