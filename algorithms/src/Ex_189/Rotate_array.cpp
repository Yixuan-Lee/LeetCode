#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        if (nums.empty() || k <= 0) {
            return;
        }

        auto size = static_cast<int> (nums.size());
        int realK = k % size;

        vector<int> ans;
        int startIdx = size - realK;
        for (int i = startIdx; i < size; i++) {
            ans.push_back(nums[i]);
        }

        if (ans.size() != nums.size()) {
            for (int i = 0; i < startIdx; i++) {
                ans.push_back(nums[i]);
            }
        }

        nums = ans;
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
    vector<int> input;

    input = vector<int> {1, 2, 3, 4, 5, 6, 7};
    s.rotate(input, 3);
    std::cout << input << std::endl;

    input = vector<int> {-1, -100, 3, 99};
    s.rotate(input, 2);
    std::cout << input << std::endl;

    return 0;
}
