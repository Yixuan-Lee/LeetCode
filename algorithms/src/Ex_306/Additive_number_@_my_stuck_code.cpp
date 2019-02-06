#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        auto length = static_cast<int> (num.length());
        if (length < 3) {
            return false;
        }

        bool equal = false;

        // indicate the starting position of first substring
        int num1_left = 0;
        // i means first substring's length
        for (int i = 1; i < length / 2; i++) {
            if (num1_left + i == length) {
                break;
            }
            // num1 => num[num1_left ... num1_left + i - 1]
            int num1 = std::stoi(num.substr(num1_left, i));
            // j means second substring's length
            for (int j = 1; j < std::min(length - i + 1, length / 2); j++) {
                if (num1_left + i + j == length) {
                    break;
                }
                // nums => num[num1_left + i ... nums1_left + i - 1 + j]
                int num2 = std::stoi(num.substr(num1_left + i, j));

                // expected result starts from num1_left + i + j
                int expected_res_left = num1_left + i + j;
                // expected result's length should be [max(i,j), max(i,j) + 1]
                int expected_res_length;
                for (expected_res_length = std::max(i, j);
                     expected_res_left + expected_res_length - 1 < length;
                     expected_res_length++) {
                    if (num[expected_res_left] == '0') {
                        break;
                    }
                    if (expected_res_length > std::max(i, j) + 1) {
                        // 99 + 99 < 1000
                        break;
                    }
                    int expected_res = std::stoi(num.substr(expected_res_left,
                            expected_res_length));
                    if (num1 + num2 == expected_res) {
                        equal = true;
                        break;
                    }
                }
                if (equal) {
                    if (expected_res_left + expected_res_length == length) {
                        return true;
                    }
                    num1_left += i;
                    equal = false;
                    i = 0;
                    break;
                }
            }
        }

        return false;
    }
};


int main() {
    Solution s;

    std::cout << s.isAdditiveNumber("12012122436") << std::endl;     // 1

    std::cout << s.isAdditiveNumber("121474836472147483648") << std::endl;// 0

    std::cout << s.isAdditiveNumber("199100199") << std::endl;     // 1

    std::cout << s.isAdditiveNumber("112358") << std::endl;     // 1

    std::cout << s.isAdditiveNumber("114358") << std::endl;     // 0

    std::cout << s.isAdditiveNumber("114") << std::endl;     // 0

    return 0;
}
