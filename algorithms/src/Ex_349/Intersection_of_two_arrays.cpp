#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.empty()) {
            return vector<int> {};
        }
        if (nums2.empty()) {
            return vector<int> {};
        }

        vector<int> ans;
        unordered_map<int, bool> hash1;
        for (auto &i : nums1) {
            hash1[i] = true;
        }
        for (auto &i : nums2) {
            if (hash1[i]) {
                ans.push_back(i);
                hash1[i] = false;
            }
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
    vector<int> num1;
    vector<int> num2;

    num1 = vector<int> {1, 2, 2, 1};
    num2 = vector<int> {2, 2};
    std::cout << s.intersection(num1, num2) << std::endl;

    return 0;
}
