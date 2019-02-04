#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        auto size = static_cast<int> (nums.size());
        if (size == 0 || size == 1) {
            return;
        }

        vector<int> sorted = nums;
        std::sort(sorted.begin(), sorted.end());

        vector<int> ans;
        auto mid = static_cast<int> (ceil(size / 2.0));
        int lo = mid - 1;
        int hi = size - 1;
        while (lo >= 0) {
            ans.push_back(sorted[lo--]);
            if (hi < mid) {
                break;
            }
            ans.push_back(sorted[hi--]);
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
    vector<int> nums;

    nums = vector<int> {1, 5, 1, 1, 6, 4};
    s.wiggleSort(nums);
    std::cout << nums << std::endl;     // [1, 4, 1, 5, 1, 6]

    nums = vector<int> {1, 3, 2, 2, 3, 1};
    s.wiggleSort(nums);
    std::cout << nums << std::endl;     // [2, 3, 1, 3, 1, 2]

    nums = vector<int> {1, 3, 2, 2, 3, 1, 4};
    s.wiggleSort(nums);
    std::cout << nums << std::endl;     // [2, 3, 1, 3, 1, 4, 2]

    nums = vector<int> {1, 3, 2};
    s.wiggleSort(nums);
    std::cout << nums << std::endl;     // [1, 3, 2]

    nums = vector<int> {1, 3, 2, 4};
    s.wiggleSort(nums);
    std::cout << nums << std::endl;     // [1, 3, 2, 4]

    nums = vector<int> {1};
    s.wiggleSort(nums);
    std::cout << nums << std::endl;     // [1]

    nums = vector<int> {4, 5, 5, 6};
    s.wiggleSort(nums);
    std::cout << nums << std::endl;     // [5, 6, 4, 5]

    return 0;
}
