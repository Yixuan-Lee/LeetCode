//
// Created by  liyixuan on 2018-12-03.
//
// references:
//      https://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/
//      https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/


#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution {
public:
    vector<vector<int>> fourSum (vector<int> &nums, int target) {
        vector<vector<int>> res;
        if (nums.size() <= 3) {
            return res;
        }

        // sort the nums in ascending order
        std::sort(nums.begin(), nums.end());

        // store the all possible results, may contains duplicated ones
        set<vector<int>> setRes;

        // declare two pointers
        int left;
        int right;
        int size = static_cast<int>(nums.size());

        for (int i = 0; i < size - 3; i++) {
            for (int j = i + 1; j < size - 2; j++) {
                // fix the first element as nums[i], and
                // fix the second element as nums[j]
                // the last two elements varies from ~ [j+1, size-1]
                left = j + 1;
                right = size - 1;
                while (left < right) {
                    if (nums[i] + nums[j] + nums[left] + nums[right]
                        == target) {
                        vector<int> v {
                                nums[i], nums[j], nums[left], nums[right]
                        };
                        if (setRes.count(v) == 0) {
                            setRes.insert(v);
                        }
                        left++;
                    } else if (nums[i] + nums[j] + nums[left] + nums[right]
                               < target) {
                        left++;
                    } else if (nums[i] + nums[j] + nums[left] + nums[right]
                               > target) {
                        right--;
                    }
                }
            }
        }

        for (const auto &setRe : setRes) {
            res.push_back(setRe);
        }

        return res;
    }
};


int main () {
    Solution s;
    vector<int> nums {0, 0, 0, 0};
    int target = 1;
    vector<vector<int>> res = s.fourSum(nums, target);

    std::cout << "[" << std::endl;
    for (auto &re : res) {
        std::cout << "\t[";
        for (int j : re) {
            std::cout << j << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
    return 0;
}