// references:
//      https://leetcode.com/problems/h-index-ii/discuss/71063/Standard-binary-search


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        auto size = static_cast<int> (citations.size());
        int left = 0;
        int right = size - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (citations[mid] == size - mid) {
                return citations[mid];
            } else if (citations[mid] > size - mid) {
                // meaning that returned value should be < citation[mid]
                right = mid - 1;
            } else if (citations[mid] < size - mid) {
                // meaning that returned value should be >= citation[mid]
                left = mid + 1;
            }
        }

        return size - (right + 1);
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {0, 1, 3, 5, 6};
    std::cout << s.hIndex(input) << std::endl;      // 3

    input = vector<int> {0, 4, 5, 5, 6};
    std::cout << s.hIndex(input) << std::endl;      // 4

    input = vector<int> {0, 1, 2, 5, 6};
    std::cout << s.hIndex(input) << std::endl;      // 2

    input = vector<int> {0};
    std::cout << s.hIndex(input) << std::endl;      // 0

    input = vector<int> {0, 1};
    std::cout << s.hIndex(input) << std::endl;      // 1

    input = vector<int> {};
    std::cout << s.hIndex(input) << std::endl;      // 0

    input = vector<int> {1};
    std::cout << s.hIndex(input) << std::endl;      // 1

    return 0;
}
