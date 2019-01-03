#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        // record the appearance times of each number
        //      first: number
        //      second: appearance times
        unordered_map<int, int> hash;

        for (const int &i : nums) {
            if (hash.find(i) != hash.end()) {
                hash[i]++;
            } else {
                hash[i] = 1;
            }
        }

        for (unordered_map<int, int>::iterator it = hash.begin();
             it != hash.end(); it++) {
            if (it->second > nums.size() / 2) {
                return it->first;
            }
        }

        return -1;
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {3, 2, 3};
    std::cout << s.majorityElement(input) << std::endl;

    input = vector<int> {2, 2, 1, 1, 1, 2, 2};
    std::cout << s.majorityElement(input) << std::endl;

    return 0;
}
