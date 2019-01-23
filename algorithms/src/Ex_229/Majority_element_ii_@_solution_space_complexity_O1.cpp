// references:
//      https://leetcode.com/problems/majority-element-ii/discuss/63571/My-C%2B%2B-Solution
//      https://en.cppreference.com/w/cpp/algorithm/nth_element


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
        // partition nums using nth_element(first, nth, last)
        // nth_element is a partial sorting algorithm that re-arrange element
        // in [first, last); all of the elements before nth element are less
        // than or equal to the elements after nth element
        //
        // complexity: O(N) applications of the predicate, and O(NlogN) swaps,
        // where N = last - first
        std::nth_element(nums.begin(), nums.begin() + size / 3, nums.end());
        std::nth_element(nums.begin(), nums.begin() + 2 * size / 3,
                nums.end());

        // only the element at (size / 3) and (2*size / 3) are possible to be
        // candidates
        int candidate1 = nums[size / 3];
        int candidate2 = nums[2 * size / 3];
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == candidate1) {
                cnt1++;
            } else if (nums[i] == candidate2) {
                cnt2++;
            }
        }
        vector<int> ans;
        if (cnt1 > size / 3) {
            ans.push_back(candidate1);
        }
        if (cnt2 > size / 3) {
            ans.push_back(candidate2);
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

    return 0;
}
