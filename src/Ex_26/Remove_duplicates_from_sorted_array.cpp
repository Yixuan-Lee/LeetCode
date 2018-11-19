//
// Created by  liyixuan on 2018-11-19.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        } else if (nums.size() == 1) {
            return 1;
        }
        int* p = &nums[0];  // always pointing to the position in non-duplicated array (good-boy pointer)
        int* q = &nums[1];  // pointing to the position in potential duplicated array (pioneer pointer)
        int idx_p = 0;
        int idx_q = 1;
        while (idx_q < nums.size()) {
            if (*p != *q) {
                p = &nums[++idx_p];
                *p = *q;
                q = &nums[++idx_q];
            } else {
              q = &nums[++idx_q];
            }
        }
        return idx_p + 1;
    }
};

int main() {
    Solution s;
    vector<int> a {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int end = s.removeDuplicates(a);
    std::cout << end << std::endl;
    for (int i = 0; i < end; i++) {
        std::cout << a[i] << " ";
    }
    return 0;
}