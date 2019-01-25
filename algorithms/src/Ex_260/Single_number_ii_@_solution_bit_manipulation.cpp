// references:
//      https://leetcode.com/problems/single-number-iii/discuss/68900/Accepted-C%2B%2BJava-O(n)-time-O(1)-space-Easy-Solution-with-Detail-Explanations
//      https://en.cppreference.com/w/cpp/algorithm/accumulate


#include <iostream>
#include <numeric>  // accumulate()
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        // pass 1:
        // get the xor of the two numbers we need to find
        int diff = std::accumulate(nums.begin(), nums.end(), 0,
                std::bit_xor<int>());
        // get its last set bit, this step is to find the rightmost 1 in the diff
        // for example: nums = {1, 2, 1, 3, 2, 5}
        //      0 0 0 1     // 1
        //      0 0 1 0     // 2
        //      0 0 0 1     // 1
        //      0 0 1 1     // 3
        //      0 0 1 0     // 2
        // ^    0 1 0 1     // 5
        // -------------
        // diff=0 1 1 0
        //
        // diff &= OxFF ^ (diff - 1)
        //      1 1 1 1     // OxFF
        // ^    0 1 0 1     // diff - 1
        // ------------
        // res= 1 0 1 0
        // &    0 1 1 0     // diff
        // ------------
        // diff=0 0 1 0     // get the rightmost 1
        diff = diff & (-diff);      // equals to: diff &= OxFF ^ (diff - 1)

        // pass 2:
        // divide all number into two groups
        // one with the aforementioned rightmost 1  (e.g. 2, 3, 2)
        // another without the rightmost 1          (e.g. 1, 1, 5)
        vector<int> rets = {0, 0};
        for (auto &num : nums) {
            if ((num & diff) == 0) {
                // the bit is not set
                rets[0] ^= num;
            } else {
                // the bit is set
                rets[1] ^= num;
            }
        }

        return rets;
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

    nums = vector<int> {-31, 31, 22, 22, -31, 31, 30, 26};
    std::cout << s.singleNumber(nums) << std::endl;     // [26, 30]

    nums = vector<int> {-1139700704, -1653765433};
    std::cout << s.singleNumber(nums)
              << std::endl;     // [-1139700704, -1653765433]  (not pass)

    return 0;
}
