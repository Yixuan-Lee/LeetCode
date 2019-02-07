/**
 * references:
 *      https://leetcode.com/problems/beautiful-array/discuss/186679/C%2B%2BJavaPython-Odd-%2B-Even-Pattern-O(N)
 */


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> ans {1};
        while (ans.size() < N) {
            vector<int> temp;
            for (const int &i : ans) {
                if (i * 2 - 1 <= N) {
                    temp.push_back(i * 2 - 1);
                }
            }
            for (const int &i : ans) {
                if (i * 2 <= N) {
                    temp.push_back(i * 2);
                }
            }
            ans = temp;
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

    std::cout << s.beautifulArray(4) << std::endl;      // [2, 1, 4, 3]

    std::cout << s.beautifulArray(5) << std::endl;      // [3, 1, 2, 5, 4]

    return 0;
}
