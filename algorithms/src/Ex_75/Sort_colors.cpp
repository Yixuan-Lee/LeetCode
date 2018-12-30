// references:
//      sample 0ms submission


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    // two-pass solution
//    void sortColors(vector<int> &nums) {
//        if (nums.empty() || nums.size() == 1) {
//            return;
//        }
//
//        vector<int> count (3, 0);
//        int i = 0;
//        for (auto a : nums) {
//            count[a]++;
//        }
//        while (count[0]) {
//            nums[i++] = 0;
//            count[0]--;
//        }
//        while (count[1]) {
//            nums[i++] = 1;
//            count[1]--;
//        }
//        while (count[2]) {
//            nums[i++] = 2;
//            count[2]--;
//        }
//    }

    // one-pass solution
    void sortColors(vector<int> &nums) {
        int n0, n1, n2;
        n0 = n1 = n2 = -1;
        for (auto &num : nums) {
            if (num == 2) {
                nums[++n2] = 2;
            } else if (num == 1) {
                nums[++n2] = 2;
                nums[++n1] = 1;
            } else if (num == 0) {
                nums[++n2] = 2;
                nums[++n1] = 1;
                nums[++n0] = 0;
            }
        }
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
    vector<int> nums {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    std::cout << nums << std::endl;
    return 0;
}
