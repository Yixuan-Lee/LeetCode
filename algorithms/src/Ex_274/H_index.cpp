#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        auto size = static_cast<int> (citations.size());
        if (size == 0) {
            return 0;
        }

        std::sort(citations.begin(), citations.end());  // ascending order
        for (int h = size; h >= 1; h--) {
            bool found = true;
            for (int j = size - 1; j >= (size - 1) + 1 - h; j--) {
                // h of size papers have at least (>=) h citations each
                if (citations[j] < h) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return h;
            }
        }

        return 0;
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {3, 0, 6, 1, 5};
    std::cout << s.hIndex(input) << std::endl;      // 3

    input = vector<int> {0};
    std::cout << s.hIndex(input) << std::endl;      // 0

    return 0;
}
