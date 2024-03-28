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
                numbers_[2] == dice2.getRight() &&
                numbers_[3] == dice2.getLeft()) {
                return true;
            }

            rollEast();
        }
        return false;
    }
};

int main() {
    std::vector<int> nums(6);
    for (int i = 0; i < 6; ++i) {
        std::cin >> nums[i];
    }
    Dice dice(nums);
    for (int i = 0; i < 6; ++i) {
        std::cin >> nums[i];
    }
    Dice dice2(nums);

    if (dice.ChackDice(dice2) == true) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    
   
    return 0;
}