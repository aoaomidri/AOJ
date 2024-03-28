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
};

int main() {
    std::vector<int> nums(6);
    for (int i = 0; i < 6; ++i) {
        std::cin >> nums[i];
    }

    std::string commands;
    std::cin >> commands;

    Dice dice(nums);

    for (char command : commands) {
        switch (command) {
        case 'N':
            dice.rollNorth();
            break;
        case 'S':
            dice.rollSouth();
            break;
        case 'E':
            dice.rollEast();
            break;
        case 'W':
            dice.rollWest();
            break;
        }
    }

    std::cout << dice.getTop() << std::endl;

    return 0;
}