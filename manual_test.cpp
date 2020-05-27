#include "manual_test.hpp"
#include "view.hpp"

bool insertPhase(Schedule& schedule) {
    std::string user_input_mode;
    std::string user_input_date;
    std::string user_input_detail;
    while(true) {
        std::cout << std::endl;
        std::cout << "1,2,3 いずれかを入力してください" << std::endl;
        std::cout << "  1: 予定を新規追加する" << std::endl;
        std::cout << "  2: 予定の検索テストを実施する" << std::endl;
        std::cout << "  3: テストプログラムを終了する" << std::endl;
        std::cin >> user_input_mode;

        // 文字列など入力された際はstoiエラーを防ぐために一旦9に変更しswitch文を通過させ再入力させる
        if (isInputModeError(user_input_mode)) user_input_mode = "9";

        switch (stoi(user_input_mode)) {
            case 1:
                std::cout << std::endl;
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
                std::cout << "1,2,3 以外が入力されました、再入力をしてください" << std::endl;
                break;
        }
    }
}
bool searchPhase(Schedule& schedule) {
    std::string user_input_mode;
    std::string user_input_start_date;
    std::string user_input_end_date;
    while(true) {
        std::cout << std::endl;
        std::cout << "1,2,3,4 いずれかを入力し検索方法を決定ください" << std::endl;
        std::cout << "  1: 検索条件を入力し検索を実施する" << std::endl;
        std::cout << "  2: 全ての予定の表示する" << std::endl;
        std::cout << "  3: 新規予定の入力に戻る" << std::endl;
        std::cout << "  4: テストプログラムを終了する" << std::endl;
        std::cin >> user_input_mode;
        if (isInputModeError(user_input_mode)) user_input_mode = "9";
        switch (stoi(user_input_mode)) {
            case 1:
                std::cout << "検索開始日時を入力してください" << std::endl;
                std::cin >> user_input_start_date;
                std::cout << "検索終了日時を入力してください" << std::endl;
                std::cin >> user_input_end_date;
                std::cout << std::endl;
                std::cout << "検索結果を表示します" << std::endl;
                std::cout << "----" << std::endl;
                outputSchedule(schedule.getRangeScheduleIter(user_input_start_date, user_input_end_date));
                std::cout << "----" << std::endl;
                break;
            case 2:
                std::cout << std::endl;
                std::cout << "検索結果を表示します" << std::endl;
                std::cout << "----" << std::endl;
                outputSchedule(schedule.getRangeScheduleIter("000001010000", "999912312359"));
                std::cout << "----" << std::endl;
                break;
            case 3:
                return true;
                break;
            case 4:
                return false;
                break;
            default:
                std::cout << "1,2,3,4 以外が入力されました、再入力をしてください" << std::endl;
                break;
        }
    }
    return true;
}

//入力は1桁数字のみ想定。2桁以上またはdigit出ない場合はtrue
bool isInputModeError(std::string input) {
    if (!std::all_of(input.cbegin(), input.cend(), isdigit)) {
        return true;
    }
    return false;
}

int main() {
    std::cout << "予定表クラスの手動動作確認を開始します" << std::endl << std::endl;

    // init schedule class
    std::string input_schedule_max;
    while (true) {
        std::cout << "登録できる予定の上限数を入力してください" << std::endl;
        std::cin >> input_schedule_max;
        if(!isInputModeError(input_schedule_max)) break;
        std::cout << "半角数字にて入力してください" << std::endl;
    }
    std::cout << std::endl;
    Schedule schedule(std::stoi(input_schedule_max));

    //rootin
    while(true) {
        if (!insertPhase(schedule)) break;
        if (!searchPhase(schedule)) break;
    }

    std::cout << "プログラム終了" << std::endl;

    return 0;
}
