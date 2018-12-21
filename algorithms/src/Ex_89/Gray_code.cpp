// references:
//      https://leetcode.com/problems/gray-code/discuss/29881/An-accepted-three-line-solution-in-JAVA

/**
 * description:
 * for example you have the answer for n = 2 as (00, 01, 11, 10), how you can get the answer for n = 3?
 * solution:
 *      #1. get all the answer in n = 2, add the prefix 0 to them (000, 001, 011, 010);
 *      #2. add pow(2,2) = 4 to all the answer in n = 2 as in #1 and add them to n = 3, BUT! start from the last element, that is (110, 111, 101, 100)
 *
 * why the algorithm works?
 *      #1. the answer n = 2 is valid, so values (000, 001, 011, 010) are valid
 *      #2. since we add the prefix 1 starting from the last element, that is 10, so it becomes 110. 010, 110 differ 1 bit, still valid
 *      #3. since we add the prefix 1 to all the answer in n = 2, so the answer still differ 1 bit, so values (110, 111, 101, 100) are valid
 *      #4. the result (000, 001, 011, 010, 110, 111, 101, 100) is valid
 */

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if (n == 0) {
            ans.push_back(0);
            return ans;
        }
        // get all the answer in n-1
        vector<int> prev = grayCode(n - 1);
        // deep copy the answer to curr
        vector<int> curr(prev);

        // add feed to all the answer of n-1,
        // and push them from the end element to the first element
        auto feed = (int) std::pow(2, n - 1);
        for (auto i = static_cast<int> (prev.size() - 1); i >= 0; i--) {
            curr.push_back(prev[i] + feed);
        }

        return curr;
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
    vector<int> res = s.grayCode(3);
    std::cout << res << std::endl;
    return 0;
}
