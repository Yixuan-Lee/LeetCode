#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        auto size = static_cast<int> (nums.size());
        if (size == 0) {
            return;
        }

        int slow = 0;       // slow always points to the zero element
        int prev = 0;       // prev always points to the non-zero element
        int newSlow = 1;    // record the new position for next slow
        int newPrev;        // record the new position for next prev
        // if the first position is 0, then move the first non-zero element
        // to the first position
        if (nums[slow] == 0) {
            bool firstMeetZero = true;
            for (prev = slow + 1; prev < size && nums[prev] == 0; prev++) {
                if (firstMeetZero && nums[prev] == 0) {
                    newSlow = prev;
                    firstMeetZero = false;
                }
            }
            if (prev < size) {
                // swap nums[slow] and nums[prev]
                int temp = nums[slow];
                nums[slow] = nums[prev];
                nums[prev] = temp;
                slow = newSlow;
            }
        } else {
            for (slow = 0; slow < size && nums[slow] != 0; slow++) {
            }
        }

        newPrev = slow + 1;
        prev = newPrev;

        while (prev < size) {
            for (prev = newPrev; prev < size && nums[prev] == 0; prev++) {
            }
            if (prev < size) {
                // swap nums[slow] and nums[prev]
                int temp = nums[slow];
                nums[slow] = nums[prev];
                nums[prev] = temp;
                slow = newSlow;
                newPrev = prev + 1;
            }
            // make slow point to the next zero
            for (; slow < size && nums[slow] != 0; slow++) {
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
    vector<int> nums;

    nums = vector<int> {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [1, 3, 12, 0, 0]

    nums = vector<int> {0, 0, 0, 0, 0};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [0, 0, 0, 0, 0]

    nums = vector<int> {0, 0, 5, 0, 0, 6, 9, 0};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [5, 6, 9, 0, 0, 0, 0]

    nums = vector<int> {2, 1};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [2, 1]

    nums = vector<int> {0, 2};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [2, 1]

    nums = vector<int> {1, 0, 1};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [1, 1, 0]

    nums = vector<int> {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [4, 2, 4, 3, 5, 1, 0, 0, 0, 0]

    return 0;
}
