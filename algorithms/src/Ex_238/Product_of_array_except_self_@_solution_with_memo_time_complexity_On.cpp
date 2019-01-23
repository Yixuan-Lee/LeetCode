#include <iostream>
#include <vector>

using std::vector;

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

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        auto size = static_cast<int> (nums.size());
        if (size == 0 || size == 1) {
            return nums;
        }

        // dp_productFromLeft[5]: product of nums[0...4]
        // dp_productFromLeft[0] = 1
        vector<int> dp_productFromLeft;
        // dp_productFromRight[0]: product of nums[1...size-1]
        // dp_productFromRight[size-1] = 1
        vector<int> dp_productFromRight;

        int product = 1;
        dp_productFromLeft.push_back(1);    // first element
        for (int i = 0; i < size - 1; i++) {
            product *= nums[i];
            dp_productFromLeft.push_back(product);
        }

        product = 1;
        dp_productFromRight = vector<int>(size, 0);
        for (int i = size - 1; i >= 1; i--) {
            product *= nums[i];
            dp_productFromRight[i - 1] = product;
        }
        dp_productFromRight[size - 1] = 1;

        // for debugging
//        std::cout << dp_productFromLeft << std::endl;
//        std::cout << dp_productFromRight << std::endl;
//        std::cout << std::endl;

        vector<int> ans;
        ans.reserve(static_cast<unsigned long>(size));
        for (int i = 0; i < size; i++) {
            ans.push_back(dp_productFromLeft[i]
                          * dp_productFromRight[i]);
        }

        return ans;
    }
};


int main() {
    Solution s;
    vector<int> nums;

    nums = vector<int> {1, 2, 3, 4};
    std::cout << s.productExceptSelf(nums) << std::endl;    // [24, 12, 8, 6]

    nums = vector<int> {5, 8};
    std::cout << s.productExceptSelf(nums) << std::endl;    // [8, 5]

    return 0;
}
