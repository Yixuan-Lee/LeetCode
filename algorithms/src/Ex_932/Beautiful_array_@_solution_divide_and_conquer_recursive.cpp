/**
 * references:
 *      sample 4ms submission
 */


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> ans;
        if (N == 1) {
            return vector<int> {1};
        }

        vector<int> left = beautifulArray((N + 1) / 2);
        for (int i : left) {
            ans.push_back(i * 2 - 1);
        }
        vector<int> right = beautifulArray(N / 2);
        for (int i : right) {
            ans.push_back(i * 2);
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
