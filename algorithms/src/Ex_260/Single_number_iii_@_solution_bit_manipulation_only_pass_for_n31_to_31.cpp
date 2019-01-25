#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int sequencePositive = 0;
        int sequenceNegative = 0;
        int countZero = 0;
        for (auto &i : nums) {
            if (i > 0) {
                sequencePositive ^= (1 << (i - 1));
            } else if (i < 0) {
                i = -i;
                sequenceNegative ^= (1 << (i - 1));
            } else {
                countZero++;
            }
        }

        vector<int> ans;
        for (int i = 0; i <= 32; i++) {
            if (sequenceNegative & 1 == 1) {
                ans.push_back(-(i + 1));
            }
            if (sequencePositive & 1 == 1) {
                ans.push_back(i + 1);
            }

            sequenceNegative >>= 1;
            sequencePositive >>= 1;
        }
        if (countZero % 2 == 1) {
            ans.push_back(0);
        }

        return ans;
    }
};


// declare a template for overloading the << operator for vector<T>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<T> &v) {
    std::cout << "[";
    for (auto &i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;
    vector<int> nums;

    nums = vector<int> {1, 2, 1, 3, 2, 5};
    std::cout << s.singleNumber(nums) << std::endl;     // [3, 5]

    nums = vector<int> {-1, 0};
    std::cout << s.singleNumber(nums) << std::endl;     // [-1, 0]

    nums = vector<int> {-1, 1, 2, -2, -1, 1, 0, 6};
    std::cout << s.singleNumber(nums) << std::endl;     // [-2, 0, 2, 6]

    nums = vector<int> {-31, 31, 22, -22, -31, 31, 30, 26};
    std::cout << s.singleNumber(nums) << std::endl;     // [-22, 22, 26, 30]

    nums = vector<int> {-1139700704, -1653765433};
    std::cout << s.singleNumber(nums)
              << std::endl;     // [-1139700704, -1653765433]  (not pass)

    return 0;
}
