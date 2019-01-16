// references:
//      https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (nums.empty() || nums.size() == 1) {
            return false;
        }

        vector<long> per;
        int del = nums[0];  // need to delete in per when sliding the window right
        // push the nums[0...k] elements
        int range = std::min(static_cast<int> (nums.size() - 1), k);
        for (int i = 0; i <= range; i++) {
            per.push_back(nums[i]);
        }
        // sort the nums[0...k] elements
        std::sort(per.begin(), per.end());
        // prove that differences between the nums[0...k] elements are bigger than t
        for (int i = 0; i < range; i++) {
            if (std::abs(per[i + 1] - per[i]) <= t) {
                return true;
            }
        }

        // slide the window right and delete the del
        for (int j = k + 1; j < nums.size(); j++) {
            // delete the del
            per.erase(std::remove(per.begin(), per.end(), del), per.end());
            // set the new delete value for next time
            del = nums[j - k];
//            // push the new element
//            per.push_back(nums[j]);
//            // sort again
//            std::sort(per.begin(), per.end());
//            // prove that difference are bigger than t
//            for (int i = 0; i < k; i++) {
//                if (per[i + 1] - per[i] <= t) {
//                    return true;
//                }
//            }
            vector<long> newPer;
            bool push = true;
            for (long i : per) {
                if (std::abs(i - nums[j]) <= t) {
                    return true;
                } else {
                    if (i < nums[j]) {
                        newPer.push_back(i);
                    } else {
                        if (push) {
                            newPer.push_back(nums[j]);
                            push = false;
                        }
                        newPer.push_back(i);
                    }
                }
            }
            if (per[per.size() - 1] < nums[j]) {
                per.push_back(nums[j]);
            }
            per = newPer;
        }

        return false;
    }
};


int main() {
    Solution s;
    vector<int> input;
    int k;
    int t;

    input = vector<int> {1, 2, 3, 1};
    k = 3;
    t = 0;
    std::cout << s.containsNearbyAlmostDuplicate(input, k, t)
              << std::endl;     // 1

    input = vector<int> {1, 0, 1, 1};
    k = 1;
    t = 2;
    std::cout << s.containsNearbyAlmostDuplicate(input, k, t)
              << std::endl;     // 1

    input = vector<int> {1, 5, 9, 1, 5, 9};
    k = 2;
    t = 3;
    std::cout << s.containsNearbyAlmostDuplicate(input, k, t)
              << std::endl;     // 0

    input = vector<int> {4, 2};
    k = 2;
    t = 1;
    std::cout << s.containsNearbyAlmostDuplicate(input, k, t)
              << std::endl;     // 0

    input = vector<int> {-1, 2147483647};
    k = 1;
    t = 2147483647;
    std::cout << s.containsNearbyAlmostDuplicate(input, k, t)
              << std::endl;     // 0

    return 0;
}
