#include <iostream>
#include <vector>
#include <string>

class Dice {
private:
    std::vector<int> numbers_;

public:
    Dice(const std::vector<int>& nums) : numbers_(nums) {}

    void rollNorth() {
        std::swap(numbers_[0], numbers_[1]);
        std::swap(numbers_[1], numbers_[5]);
        std::swap(numbers_[5], numbers_[4]);
    }

    void rollSouth() {
        std::swap(numbers_[0], numbers_[4]);
        std::swap(numbers_[4], numbers_[5]);
        std::swap(numbers_[5], numbers_[1]);
    }

    void rollEast() {
        std::swap(numbers_[0], numbers_[3]);
        std::swap(numbers_[3], numbers_[5]);
        std::swap(numbers_[5], numbers_[2]);
    }

    void rollWest() {
        std::swap(numbers_[0], numbers_[2]);
        std::swap(numbers_[2], numbers_[5]);
        std::swap(numbers_[5], numbers_[3]);
    }

    int getTop() const {
        return numbers_[0];
    }

    int getFront() const {
        return numbers_[1];
    }

    int getRight() const {
        return numbers_[2];
    }

    int getLeft() const {
        return numbers_[3];
    }

    int getBack() const {
        return numbers_[4];
    }

    int getUnder() const {
        return numbers_[5];
    }

    int getMax()const {
        int max_value = numbers_[0];
        for (int num : numbers_) {
            max_value = std::max(max_value, num);
        }
        return max_value;
    }

    int getRight(int top, int front) {
        // サイコロを正しい方向に回転させる
        if (front == numbers_[2]){
            rollWest();
        }
        else if(front == numbers_[3]) {
            rollEast();
        }

        while (numbers_[1] != front) {
            rollNorth();
        }
        while (numbers_[0] != top) {
            rollEast();
        }

        // 右側の面の整数を返す
        return numbers_[2];
    }

    //このダイスと同一の物か確認する
    bool ChackDice(const Dice& dice2) {
        if (getMax() != dice2.getMax()){
            return false;
        }
        
        if (dice2.getFront() == numbers_[2]) {
            rollWest();
        }
        else if (dice2.getFront()== numbers_[3]) {
            rollEast();
        }
        while (numbers_[1] != dice2.getFront()) {
            rollNorth();
        }
        for (int i = 0; i < 4; i++){
            if (numbers_[0] == dice2.getTop() &&
                numbers_[2] == dice2.getRight()) {
                break;
            }

            rollEast();
        }
        if (numbers_[0] == dice2.getTop() &&
            numbers_[2] == dice2.getRight() &&
            numbers_[3] == dice2.getLeft()&&
            getBack() == dice2.getBack() &&
            getUnder() == dice2.getUnder()) {
            return true;
        }
        
        return false;
    }
};

int main() {
    int num;
    std::vector<Dice> dices;
    std::cin >> num;
    for (int i = 0; i < num; i++){
        std::vector<int> nums(6);
        for (int j = 0; j < 6; ++j) {
            std::cin >> nums[j];
        }
        Dice dice(nums);

        dices.push_back(dice);
    }

    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (dices[i].ChackDice(dices[j]) == true) {
                std::cout << "No" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}