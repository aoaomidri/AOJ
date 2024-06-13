#include <iostream>
#include <vector>
#include<algorithm>
#include <string>

bool chackDecreaseFlug(const std::string number) {
    for (size_t i = 0; i < number.size(); i++) {
        auto it = number[i];
        if (it == '6' || it == '7' || it == '8' || it == '9') {

            return true;
        }
    }

    return false;
}

bool chackAddFlug(const std::string number) {
    for (size_t i = 0; i < number.size(); i++) {
        auto it = number[i];
        if (it == '0' || it == '1' || it == '3' || it == '5' || it == '6' || it == '9') {
            return true;
        }
    }

    return false;
}

void changeNumber(const std::string number,std::vector<std::string>& numberCon) {
    std::string num;
    bool isDecrease = false;
    bool isAdd = false;
    bool isChange = false;

    isDecrease = chackDecreaseFlug(number);
    if (isDecrease){
        isAdd = chackAddFlug(number);
    }
    if (isDecrease and isAdd){
        isChange = true;
    }

    for (size_t i = 0; i < number.size(); i++){
        num = number;
       
        if (number[i] == '0') {
            if (isChange){
                for (size_t j = 0; j < number.size(); j++) {
                    if (j == i) {
                        continue;
                    }
                    if (number[j] == '6'){
                        num[i] = '8';
                        num[j] = '5';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '7'){
                        num[i] = '8';
                        num[j] = '1';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '8') {
                        num[i] = '8';
                        num[j] = '0';
                        numberCon.push_back(num);
                        num[j] = '6';
                        numberCon.push_back(num);
                        num[j] = '9';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '9') {
                        num[i] = '8';
                        num[j] = '3';
                        numberCon.push_back(num);
                        num[j] = '5';
                        numberCon.push_back(num);
                    }
                    
                }
            }
            num = number;
            num[i] = '6';
            numberCon.push_back(num);
            num[i] = '9';
            numberCon.push_back(num);
           
        }
        else if (number[i] == '1') {
            if (isChange) {
                for (size_t j = 0; j < number.size(); j++) {
                    if (j == i) {
                        continue;
                    }
                    if (number[j] == '6') {
                        num[i] = '7';
                        num[j] = '5';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '7') {
                        num[i] = '7';
                        num[j] = '1';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '8') {
                        num[i] = '7';
                        num[j] = '0';
                        numberCon.push_back(num);
                        num[j] = '6';
                        numberCon.push_back(num);
                        num[j] = '9';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '9') {
                        num[i] = '7';
                        num[j] = '3';
                        numberCon.push_back(num);
                        num[j] = '5';
                        numberCon.push_back(num);
                    }

                }
            }
            num = number;

        }
        else if (number[i] == '2') {
            num[i] = '3';
            numberCon.push_back(num);
        }
        else if (number[i] == '3') {
            if (isChange) {
                for (size_t j = 0; j < number.size(); j++) {
                    if (j == i) {
                        continue;
                    }
                    if (number[j] == '6') {
                        num[i] = '9';
                        num[j] = '5';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '7') {
                        num[i] = '9';
                        num[j] = '1';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '8') {
                        num[i] = '9';
                        num[j] = '0';
                        numberCon.push_back(num);
                        num[j] = '6';
                        numberCon.push_back(num);
                        num[j] = '9';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '9') {
                        num[i] = '9';
                        num[j] = '3';
                        numberCon.push_back(num);
                        num[j] = '5';
                        numberCon.push_back(num);
                    }

                }
            }
            num = number;
            num[i] = '2';
            numberCon.push_back(num);
            num[i] = '5';
            numberCon.push_back(num);
        }
        else if (number[i] == '4') {

        }
        else if (number[i] == '5') {
            if (isChange) {
                for (size_t j = 0; j < number.size(); j++) {
                    if (j == i) {
                        continue;
                    }
                    if (number[j] == '6') {
                        num[i] = '6';
                        num[j] = '5';
                        numberCon.push_back(num);
                        num[i] = '9';
                        num[j] = '5';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '7') {
                        num[i] = '6';
                        num[j] = '1';
                        numberCon.push_back(num);
                        num[i] = '9';
                        num[j] = '1';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '8') {
                        num[i] = '6';
                        num[j] = '0';
                        numberCon.push_back(num);
                        num[j] = '6';
                        numberCon.push_back(num);
                        num[j] = '9';
                        numberCon.push_back(num);
                        num[i] = '9';
                        num[j] = '0';
                        numberCon.push_back(num);
                        num[j] = '6';
                        numberCon.push_back(num);
                        num[j] = '9';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '9') {
                        num[i] = '6';
                        num[j] = '3';
                        numberCon.push_back(num);
                        num[j] = '5';
                        numberCon.push_back(num);
                        num[i] = '9';
                        num[j] = '3';
                        numberCon.push_back(num);
                        num[j] = '5';
                        numberCon.push_back(num);
                    }

                }
            }
            num = number;
            num[i] = '3';
            numberCon.push_back(num);
        }
        else if (number[i] == '6') {
            if (isChange) {
                for (size_t j = 0; j < number.size(); j++) {
                    if (j == i) {
                        continue;
                    }
                    if (number[j] == '6') {
                        num[i] = '8';
                        num[j] = '5';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '7') {
                        num[i] = '8';
                        num[j] = '1';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '8') {
                        num[i] = '8';
                        num[j] = '0';
                        numberCon.push_back(num);
                        num[j] = '6';
                        numberCon.push_back(num);
                        num[j] = '9';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '9') {
                        num[i] = '8';
                        num[j] = '3';
                        numberCon.push_back(num);
                        num[j] = '5';
                        numberCon.push_back(num);
                    }

                }
            }
            num = number;
            num[i] = '0';
            numberCon.push_back(num);
            num[i] = '9';
            numberCon.push_back(num);
        }
        else if (number[i] == '7') {
            for (size_t j = i; j < number.size(); j++) {

            }

        }
        else if (number[i] == '8') {
            for (size_t j = i; j < number.size(); j++) {

            }

        }
        else if (number[i] == '9') {
            if (isChange) {
                for (size_t j = 0; j < number.size(); j++) {
                    if (j == i) {
                        continue;
                    }
                    if (number[j] == '6') {
                        num[i] = '8';
                        num[j] = '5';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '7') {
                        num[i] = '8';
                        num[j] = '1';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '8') {
                        num[i] = '8';
                        num[j] = '0';
                        numberCon.push_back(num);
                        num[j] = '6';
                        numberCon.push_back(num);
                        num[j] = '9';
                        numberCon.push_back(num);
                    }
                    else if (number[j] == '9') {
                        num[i] = '8';
                        num[j] = '3';
                        numberCon.push_back(num);
                        num[j] = '5';
                        numberCon.push_back(num);
                    }

                }
            }
            num = number;
            num[i] = '0';
            numberCon.push_back(num);
            num[i] = '6';
            numberCon.push_back(num);
        }
    }


}

int main() {
    std::string num;
    std::cin >> num;
    std::vector<std::string> result;
    
    changeNumber(num, result);

    // Œ‹‰Ê‚ğo—Í
    std::sort(result.begin(), result.end());
    if (result.size() != 0) {
        for (size_t i = 0; i < result.size(); i++) {
            std::cout << result[i] << std::endl;
        }
    }
    else {
        std::cout << "none" << std::endl;
    }

    return 0;
}