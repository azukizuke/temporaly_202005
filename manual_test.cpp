#include "manual_test.hpp"

bool insertPhase(Schedule& schedule) {
    std::string user_input_mode;
    std::string user_input_date;
    std::string user_input_detail;
    while(true) {
        std::cout << "1,2,3 いずれかを入力してください" << std::endl;
        std::cout << "1: 予定を新規追加する" << std::endl;
        std::cout << "2: 予定の検索テストを実施する" << std::endl;
        std::cout << "3: テストプログラムを終了する" << std::endl;
        std::cin >> user_input_mode;

        switch (stoi(user_input_mode)) {
            case 1:
                std::cout << "日時YYYYMMDDhhmmを12桁の半角数字で入力してください" << std::endl;
                std::cin >> user_input_date;
                std::cout << "用件を全角文字列256文字以内で入力してください" << std::endl;
                std::cin >> user_input_detail;
                schedule.setSchedule(user_input_date, user_input_detail);
                break;
            case 2:
                return true;
                break;
            case 3:
                return false;
                break;
            default:
                break;
        }
    }
}
bool searchPhase(Schedule& schedule) {
    std::string user_input_mode;
    std::string user_input_start_date;
    std::string user_input_end_date;
    while(true) {
        std::cout << "1,2,3 いずれかを入力してください" << std::endl;
        std::cout << "1: 検索条件を入力し検索を実施する" << std::endl;
        std::cout << "2: 全ての予定の表示する" << std::endl;
        std::cout << "3: 新規予定の入力を実施する" << std::endl;
        std::cout << "4: テストプログラムを終了する" << std::endl;
        std::cin >> user_input_mode;
        switch (stoi(user_input_mode)) {
            case 1:
                std::cout << "検索開始日時を入力してください" << std::endl;
                std::cin >> user_input_start_date;
                std::cout << "検索終了日時を入力してください" << std::endl;
                std::cin >> user_input_end_date;
                schedule.outputRangeSchedule(user_input_start_date ,user_input_end_date);
                break;
            case 2:
                schedule.outputAllSchedule();
                break;
            case 3:
                return true;
                break;
            default:
                return false;
                break;
        }
    }
    return true;
}

int main() {
    std::cout << "予定表クラスの手動動作確認を開始します" << std::endl;
    std::cout << "登録できる予定の上限数を入力してください" << std::endl;

    // init schedule class
    std::string input_schedule_max;
    std::cin >> input_schedule_max;
    Schedule schedule(std::stoi(input_schedule_max));

    //rootin
    while(true) {
        if (!insertPhase(schedule)) break;
        if (!searchPhase(schedule)) break;
    }

    std::cout << "プログラム終了" << std::endl;

    return 0;
}
