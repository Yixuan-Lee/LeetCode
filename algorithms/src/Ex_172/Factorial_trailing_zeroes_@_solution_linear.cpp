#include <iostream>
#include <unordered_map>

using std::unordered_map;

class Solution {
public:
    int trailingZeroes(int n) {
        // trailing zeroes are generated by '2'-'5' pairs
        // 1 pair generates 1 trailing 0
        // but trailing 0s are usually decided by amount of number '5'
        // since amount of number '2' is always greater than '5'

        int fives = 0;
        for (int i = 1; i <= n; i++) {
            int j = i;
            while (j % 5 == 0) {
                fives++;
                j /= 5;
            }
        }
        return fives;
    }
};


int main() {
    Solution s;

    std::cout << s.trailingZeroes(3) << std::endl;      // 0

    std::cout << s.trailingZeroes(5) << std::endl;      // 1

    std::cout << s.trailingZeroes(10) << std::endl;     // 2

    std::cout << s.trailingZeroes(30) << std::endl;     // 7

    std::cout << s.trailingZeroes(50) << std::endl;     // 12

    std::cout << s.trailingZeroes(1808548329) << std::endl;     // 7

    return 0;
}
