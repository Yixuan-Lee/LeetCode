// references:
//      https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return static_cast<int>(nums.size());
    }
};

int main() {
    Solution s;
    vector<int> a {3, 2, 2, 3};
    int end = s.removeElement(a, 2);
    std::cout << end << std::endl;
    for (int i = 0; i < end; i++) {
        std::cout << a[i] << " ";
    }
    return 0;
}
