// references:
//      https://leetcode.com/submissions/detail/201716141/  (sample 16ms submission)
//      http://www.cplusplus.com/reference/set/set/lower_bound/


#include <iostream>
#include <vector>
#include <set>

using std::set;
using std::vector;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long> setNums;
        set<long>::iterator lowerBound;

        // insert elements to binary search tree
        for (int i = 0; i < nums.size(); i++) {
            long n = nums[i];

            // delete the past element in set
            if (i > k) {
                setNums.erase(nums[i - k - 1]);
            }

            // get the iterator pointing to the closest left value to n-t in the setNums
            // n-t: largest boundary
            lowerBound = setNums.lower_bound(n - t);
            // check if difference is smaller than t
            if (lowerBound != setNums.end() && *lowerBound - n <= t) {
                return true;
            }

            setNums.insert(n);
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
