//
// Created by  liyixuan on 2018-12-10.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void merge (vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (nums2.empty()) {
            return;
        }
        vector<int> res;
        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                res.push_back(nums1[i++]);
            } else {
                res.push_back(nums2[j++]);
            }
        }
        while (i < m) {
            res.push_back(nums1[i++]);
        }
        while (j < n) {
            res.push_back(nums2[j++]);
        }
        nums1 = res;
    }
};


// declare a template for overloading the << operator for vector<T>
template<typename T>
std::ostream &operator<< (std::ostream &output, const vector<T> &v) {
    std::cout << "[";
    for (auto &i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return output;
}

int main () {
    Solution s;
    vector<int> nums1 {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 {2, 5, 6};
    int n = 3;
    s.merge(nums1, m, nums2, n);
    std::cout << nums1;
    return 0;
}