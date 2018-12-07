//
// Created by  liyixuan on 2018-12-07.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne (vector<int> &digits) {
        if (digits.empty()) {
            return digits;
        }

        auto size = static_cast<int>(digits.size());
        // add 1 at the ending position
        digits[size - 1]++;
        // adjust the numbers
        for (int i = size - 1; i >= 0; i--) {
            // if the first position is 10, then need to add a leading 1 (new
            // first position), and set the previous last position as 0
            if (i == 0 && digits[i] == 10) {
                digits[i] = 0;
                addLeadingOne(digits);
                break;
            }
            if (digits[i] == 10) {
                digits[i - 1]++;
                digits[i] = 0;
            } else {
                break;
            }
        }
        return digits;
    }

private:
    void addLeadingOne (vector<int> &digit) {
        vector<int> res {1};
        for (int i : digit) {
            res.push_back(i);
        }
        digit = res;
    }
};

// declare a template for overloading the << operator for vector<T>
template<typename T>
std::ostream &operator<< (std::ostream &output, const vector<T> &v) {
    std::cout << "[";
    for (auto &i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return output;
}

int main () {
    Solution s;
    vector<int> input {1, 9, 8, 9};
    vector<int> res = s.plusOne(input);
    std::cout << res << std::endl;
    return 0;
}