// references:
//      https://leetcode.com/submissions/detail/204033169/  (sample 0ms submission)


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        std::sort(citations.begin(), citations.end(), std::greater<int>());
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] < i + 1) {
                return i;
            }
        }

        return static_cast<int> (citations.size());
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {3, 0, 6, 1, 5};
    std::cout << s.hIndex(input) << std::endl;      // 3

    input = vector<int> {0};
    std::cout << s.hIndex(input) << std::endl;      // 0

    input = vector<int> {5, 5, 5, 5, 5};
    std::cout << s.hIndex(input) << std::endl;      // 5

    return 0;
}
