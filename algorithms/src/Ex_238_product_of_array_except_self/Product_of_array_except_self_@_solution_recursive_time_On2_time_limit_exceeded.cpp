#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        auto size = static_cast<int> (nums.size());
        if (size == 0 || size == 1) {
            return nums;
        }

        vector<int> ans;
        ans.reserve(static_cast<unsigned long>(size));
        for (int i = 0; i < size; i++) {
            ans.push_back(getProduct(nums, 0, i - 1)
                          * getProduct(nums, i + 1, size - 1));
        }

        return ans;
    }

private:
    int getProduct(const vector<int> &nums, int left, int right) {
        if (left > right) {
            return 1;
        } else if (left == right) {
            return nums[left];
        } else if (left == right - 1) {
            return nums[left] * nums[right];
        }

        int mid = (left + right) / 2;
        return nums[mid] * getProduct(nums, left, mid - 1)
               * getProduct(nums, mid + 1, right);
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

    nums = vector<int> {1, 2, 3, 4};
    std::cout << s.productExceptSelf(nums) << std::endl;

    nums = vector<int> {5, 8};
    std::cout << s.productExceptSelf(nums) << std::endl;

    return 0;
}
