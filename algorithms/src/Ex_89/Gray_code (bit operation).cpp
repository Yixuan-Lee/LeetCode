// references:
//      https://leetcode.com/problems/gray-code/discuss/29881/An-accepted-three-line-solution-in-JAVA


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for (int i = 0; i < 1 << n; i++) {
            ans.push_back(i ^ i >> 1);
        }

        return ans;
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
    vector<int> res = s.grayCode(0);
    std::cout << res << std::endl;
    return 0;
}

