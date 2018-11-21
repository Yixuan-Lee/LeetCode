//
// Created by  liyixuan on 2018-11-21.
//
// references:
//      https://leetcode.com/articles/next-permutation/
//      http://www.cplusplus.com/reference/algorithm/reverse/
//      http://www.cplusplus.com/reference/utility/swap/?kw=swap
//      http://www.cplusplus.com/reference/cstdlib/qsort/
//      https://stackoverflow.com/questions/12308243/trying-to-use-qsort-with-vector

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::reverse;

int compare(const void* a, const void* b) {
    return (*(int*) a - *(int*) b);
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        if (nums.size() == 1) {
            return;
        }
        int i = static_cast<int> (nums.size() - 2);
        // keep doing decrement, until finding a successive descending pair
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            // we found a descending pair
            // then swap nums[i] and the value p which is just bigger than nums[i],
            // and p locates in [i, nums.size()-1]
            int j = static_cast<int> (nums.size() - 1);
            // find the value which is just bigger than nums[i]
            // because nums[i+1...end] is descending, so the first element which is bigger than nums[i] is the just bigger one
            while (j >= i + 1 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }

private:
    void swap(vector<int> &vec, int i, int j) {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
};



int main() {
    Solution s;
    vector<int> vec {1, 1, 5};
    s.nextPermutation(vec);
    for (int i : vec) {
        std::cout << i << ",";
    }
    std::cout << std::endl;
    return 0;
}
