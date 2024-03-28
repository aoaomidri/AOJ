#include <iostream>
#include <vector>
#include <string>

class Dice {
private:
    std::vector<int> numbers_;

public:
    Dice(const std::vector<int>& nums) : numbers_(nums) {}

    void RollNorth() {
        std::swap(numbers_[0], numbers_[1]);
        std::swap(numbers_[1], numbers_[5]);
        std::swap(numbers_[5], numbers_[4]);
    }

    void RollSouth() {
        std::swap(numbers_[0], numbers_[4]);
        std::swap(numbers_[4], numbers_[5]);
        std::swap(numbers_[5], numbers_[1]);
    }

    void RollEast() {
        std::swap(numbers_[0], numbers_[3]);
        std::swap(numbers_[3], numbers_[5]);
        std::swap(numbers_[5], numbers_[2]);
    }

    void RollWest() {
        std::swap(numbers_[0], numbers_[2]);
        std::swap(numbers_[2], numbers_[5]);
        std::swap(numbers_[5], numbers_[3]);
    }

    int GetTop() const {
        return numbers_[0];
    }

    int GetFront() const {
        return numbers_[1];
    }

    int GetRight() const {
        return numbers_[2];
    }

    int GetLeft() const {
        return numbers_[3];
    }

    int GetBack() const {
        return numbers_[4];
    }

    int GetUnder() const {
        return numbers_[5];
    }

    int GetMax()const {
        int max_value = numbers_[0];
        for (int num : numbers_) {
            max_value = std::max(max_value, num);
        }
        return max_value;
    }

    int GetRight(int top, int front) {
        // �T�C�R���𐳂��������ɉ�]������
        if (front == numbers_[2]){
            RollWest();
        }
        else if(front == numbers_[3]) {
            RollEast();
        }

        while (numbers_[1] != front) {
            RollNorth();
        }
        while (numbers_[0] != top) {
            RollEast();
        }

        // �E���̖ʂ̐�����Ԃ�
        return numbers_[2];
    }

    //���̃_�C�X�Ɠ���̕����m�F����
    bool ChackDice(const Dice& dice2) {
        if (GetMax() != dice2.GetMax()){
            return false;
        }
        
        if (dice2.GetFront() == numbers_[2]) {
            RollWest();
        }
        else if (dice2.GetFront()== numbers_[3]) {
            RollEast();
        }
        while (numbers_[1] != dice2.GetFront()) {
            RollNorth();
        }
        for (int i = 0; i < 4; i++){
            if (numbers_[0] == dice2.GetTop() &&
                numbers_[2] == dice2.GetRight()) {
                break;
            }

            RollEast();
        }
        if (numbers_[0] == dice2.GetTop() &&
            numbers_[2] == dice2.GetRight() &&
            numbers_[3] == dice2.GetLeft()&&
            GetBack() == dice2.GetBack() &&
            GetUnder() == dice2.GetUnder()) {
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