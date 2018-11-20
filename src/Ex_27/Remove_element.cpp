//
// Created by  liyixuan on 2018-11-19.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int length = static_cast<int>(nums.size());
        int res = length;
        for (int i = 0; i < length; i++) {
            if (nums[i] == val) {
                int tmp = i;
                int j;
                for (j = i + 1; j < length && nums[j] == val; j++) {
                    res--;
                }
                for (int k = j; k < length; k++, tmp++) {
                    nums[tmp] = nums[k];
                }
                length--;
                res--;
            }
        }
        if (res == -1)
            return 0;
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a {2, 2, 2};
    int end = s.removeElement(a, 2);
    std::cout << end << std::endl;
    for (int i = 0; i < end; i++) {
        std::cout << a[i] << " ";
    }
    return 0;
}