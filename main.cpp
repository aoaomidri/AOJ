#include <iostream>
#include <vector>
#include <string>

class Dice {
private:
    std::vector<int> numbers;

public:
    Dice(const std::vector<int>& nums) : numbers(nums) {}

    void rollNorth() {
        std::swap(numbers[0], numbers[1]);
        std::swap(numbers[1], numbers[5]);
        std::swap(numbers[5], numbers[4]);
    }

    void rollSouth() {
        std::swap(numbers[0], numbers[4]);
        std::swap(numbers[4], numbers[5]);
        std::swap(numbers[5], numbers[1]);
    }

    void rollEast() {
        std::swap(numbers[0], numbers[3]);
        std::swap(numbers[3], numbers[5]);
        std::swap(numbers[5], numbers[2]);
    }

    void rollWest() {
        std::swap(numbers[0], numbers[2]);
        std::swap(numbers[2], numbers[5]);
        std::swap(numbers[5], numbers[3]);
    }

    int getTop() const {
        return numbers[0];
    }

    int getRight(int top, int front) {
        // �T�C�R���𐳂��������ɉ�]������
        if (front == numbers[2]){
            rollWest();
        }
        else if(front == numbers[3]) {
            rollEast();
        }

        while (numbers[1] != front) {
            rollNorth();
        }
        while (numbers[0] != top) {
            rollEast();
        }

        // �E���̖ʂ̐�����Ԃ�
        return numbers[2];
    }
};

int main() {
    std::vector<int> nums(6);
    std::vector<int> result;
    for (int i = 0; i < 6; ++i) {
        std::cin >> nums[i];
    }

    Dice dice(nums);

    // ����̐����󂯎��
    int q;
    std::cin >> q;

    // �e����ɑ΂��ăT�C�R������]�����A�E���̖ʂ̐������o��
    for (int i = 0; i < q; ++i) {
        int top, front;
        std::cin >> top >> front;
        result.push_back(dice.getRight(top, front));
    }
    for (int i = 0; i < q; ++i) {
        std::cout << result[i] << std::endl;
    }
    return 0;
}