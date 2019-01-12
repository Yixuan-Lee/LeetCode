// references:
//      https://leetcode.com/articles/minimum-size-subarray-sum/
//      https://en.cppreference.com/w/cpp/algorithm/lower_bound


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        auto n = static_cast<int> (nums.size());
        if (n == 0) {
            return 0;
        }

        int ans = INT_MAX;
        // stores the sums from the beginning of array
        vector<int> sums(static_cast<unsigned long> (n + 1), 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= n; i++) {
            int toFind = s + sums[i - 1];
            // template<class ForwardIt, class T>
            // ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value);
            //
            // returned value of lower_bound(first, last, value):
            // returns an iterator pointing to the first element in the range [first, last)
            // that is not less than value, or last if no such element is found
            //
            // complexity of lower_bound(first, last, value):
            // logarithmic, needs log2(last - first) + O(1) comparisons
            //
            auto bound = std::lower_bound(sums.begin(), sums.end(), toFind);
            if (bound != sums.end()) {
                ans = std::min(ans,
                        static_cast<int> (bound - (sums.begin() + i - 1)));
            }
        }

        return (ans != INT_MAX) ? ans : 0;
    }
};


int main() {
    Solution s;
    vector<int> nums;
    int target;

    nums = vector<int> {2, 3, 1, 2, 4, 3};
    target = 7;
    std::cout << s.minSubArrayLen(target, nums) << std::endl;   // 2

    nums = vector<int> {1, 2, 3, 4, 5};
    target = 15;
    std::cout << s.minSubArrayLen(target, nums) << std::endl;   // 5

    nums = vector<int> {1, 1};
    target = 3;
    std::cout << s.minSubArrayLen(target, nums) << std::endl;   // 0

    return 0;
}
