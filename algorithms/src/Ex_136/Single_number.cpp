#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int size = static_cast<int> (nums.size());
        map<int, int> count;
        int once = 0;
        for (int i = 0; i < size; i++) {
            count[nums[i]]++;
            if (count[nums[i]] == 1) {
                once += nums[i];
            } else {
                once -= nums[i];
            }
        }
        return once;
    }
};


int main() {
    Solution s;
//    vector<int> input {2, 2, 1};
    vector<int> input {4, 1, 2, 1, 2};
    std::cout << s.singleNumber(input) << std::endl;
    return 0;
}

