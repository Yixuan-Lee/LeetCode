//
// Created by  liyixuan on 2018-11-10.
//
// references:
//      http://www.drdobbs.com/parallel/finding-the-median-of-two-sorted-arrays/240169222
//      https://www.geeksforgeeks.org/median-two-sorted-arrays-different-sizes-ologminn-m/

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int min_index = 0, max_index = nums1.size();
        int i, j, median;
        int n = nums1.size(), m = nums2.size();

        while (min_index <= max_index) {
            i = (min_index + max_index) / 2;
            j = ((n + m + 1) / 2) - i;
            // if i = n, it means that elements from nums1 in the second half is an empty set.
            // if j = 0, it means that elements from nums2 in the first half is an empty set.
            // searching on right
            if (i < n && j > 0 && nums2[j - 1] > nums1[i]) {
                min_index = i + 1;
            }

            // if i = 0, it means that elements from nums1 in the first half is an empty set.
            // if j = m, it means that elements from nums2 in the second half is an empty set
            // searching on left
            else if (i > 0 && j < m && nums2[j] < nums1[i - 1]) {
                max_index = i - 1;
            }

            // we have found the desired halves.
            else {
                // this condition happens when we don't have any elements in the first half from nums1
                // we return the last element in nums2 from the first half
                if (i == 0)
                    median = nums2[j - 1];

                // this condition happens when we don't have any elements in the first half from nums2
                // we return the last element in nums1 from the first half
                else if (j == 0)
                    median = nums1[i - 1];

                else
                    median = fmax(nums1[i - 1], nums2[j - 1]);

                break;
            }
        }

        // calculating the median
        // if the number of elements is odd, there is one middle element
        if ((n + m) % 2 == 1)
            return (double) median;

        // elements from nums1 in the second half is an empty set
        if (i == n)
            return (median + nums2[j]) / 2.0;

        // elements from nums2 in the second half is an empty set
        if (j == m)
            return (median + nums1[i]) / 2.0;

        return (median + fmin(nums1[i], nums2[j])) / 2.0;
    }
};

int main() {
    Solution s;
    vector<int> num1 {1, 2, 4};
    vector<int> num2 {3, 5};
    std::cout << s.findMedianSortedArrays(num1, num2) << std::endl;
    return 0;
}