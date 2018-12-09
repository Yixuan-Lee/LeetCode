//
// Created by  liyixuan on 2018-12-01.
//
// references:
//      https://stackoverflow.com/questions/8690567/setting-an-int-to-infinity-in-c
//

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>

using std::vector;

class Solution {
public:
    int threeSumClosest (vector<int> &nums, int target) {
        if (nums.size() < 3) {
            return -1;
        } else if (nums.size() == 3) {
            return nums[0] + nums[1] + nums[2];
        }

        unsigned int l, r;
        unsigned int size = static_cast<int> (nums.size());
        // set gap to a very far number from target
        int gap = std::numeric_limits<int>::max();
        int cloest2Target = 0;

        std::sort(nums.begin(), nums.end());

        for (unsigned int i = 0; i < size - 2; i++) {
            l = i + 1;
            r = size - 1;
            while (l < r) {
                // calculate the gap between three numbers and the target
                int per = nums[i] + nums[l] + nums[r] - target;
                if (per == 0) {
                    return target;
                }

                if (per > 0) {
                    // per is positive
                    if (gap > 0) {
                        // if previous minimum gap is positive
                        if (per < gap) {
                            cloest2Target = nums[i] + nums[l] + nums[r];
                            gap = per;
                        }
                        r--;
                    } else {
                        // if previous minimum gap is negative
                        if (per < abs(gap)) {
                            cloest2Target = nums[i] + nums[l] + nums[r];
                            gap = per;
                        }
                        r--;
                    }
                } else {
                    // per is negative
                    if (gap < 0) {
                        // if previous minimum gap is negative
                        if (abs(per) < abs(gap)) {
                            cloest2Target = nums[i] + nums[l] + nums[r];
                            gap = per;
                        }
                        l++;
                    } else {
                        // if previous minimum gap is positive
                        if (abs(per) < gap) {
                            cloest2Target = nums[i] + nums[l] + nums[r];
                            gap = per;
                        }
                        l++;
                    }
                }
            }
        }
        return cloest2Target;
    }
};


int main () {
    Solution s;

    vector<int> vec {-3, -2, -5, 3, -4};
    int target = -1;
    std::cout << s.threeSumClosest(vec, target) << std::endl;
    return 0;
}