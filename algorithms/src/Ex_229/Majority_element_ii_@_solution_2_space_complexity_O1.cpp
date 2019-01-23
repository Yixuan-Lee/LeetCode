// references:
//      https://leetcode.com/problems/majority-element-ii/discuss/63571/My-C%2B%2B-Solution


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        if (nums.empty()) {
            return vector<int> {};
        }

        auto size = static_cast<int> (nums.size());
        if (size == 1) {
            return vector<int> {nums[0]};
        } else if (size == 2) {
            return nums[0] == nums[1] ? vector<int> {nums[0]}
                                      : vector<int> {nums[0], nums[1]};
        }

        vector<int> ans;
        int count1 = 0;
        int count2 = 0;
        int result1 = nums[0];
        count1 = 1;
        int result2;
        int j;
        for (j = 1; j < size; j++) {
            if (nums[j] != result1) {
                result2 = nums[j];
                count2 = 1;
                break;
            } else {
                count1++;
            }
        }

        for (int i = j + 1; i < size; i++) {
            if (nums[i] == result1) {
                count1++;
            } else if (nums[i] == result2) {
                count2++;
            } else if (count1 == 0) {
                result1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                result2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for (const int &n : nums) {
            if (n == result1) {
                count1++;
            } else if (n == result2) {
                count2++;
            }
        }

        if (count1 > size / 3) {
            ans.push_back(result1);
        }
        if (count2 > size / 3) {
            ans.push_back(result2);
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

    nums = vector<int> {3, 2, 3};
    std::cout << s.majorityElement(nums) << std::endl;  // [3]

    nums = vector<int> {1, 1, 1, 3, 3, 2, 2, 2};
    std::cout << s.majorityElement(nums) << std::endl;  // [1, 2]

    nums = vector<int> {1, 3, 2, 2, 1, 3, 1, 2};
    std::cout << s.majorityElement(nums) << std::endl;  // [1, 2]

    nums = vector<int> {3, 3};
    std::cout << s.majorityElement(nums) << std::endl;  // [3]

    nums = vector<int> {3, 3, 3};
    std::cout << s.majorityElement(nums) << std::endl;  // [3]

    nums = vector<int> {1, 2};
    std::cout << s.majorityElement(nums) << std::endl;  // [1, 2]

    nums = vector<int> {8, 8, 8, 8};
    std::cout << s.majorityElement(nums) << std::endl;  // [8]

    nums = vector<int> {1, 2, 3, 1, 2, 2, 1, 2, 3};
    std::cout << s.majorityElement(nums) << std::endl;  // [2]

    nums = vector<int> {2, 2, 1, 3};
    std::cout << s.majorityElement(nums) << std::endl;  // [2]

    return 0;
}
