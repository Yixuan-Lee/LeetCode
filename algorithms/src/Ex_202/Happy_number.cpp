#include <iostream>
#include <unordered_map>

using std::unordered_map;

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) {
            return false;
        }

        unordered_map<int, bool> hash;

        while (!hash[n]) {
            hash[n] = true;
            int temp = 0;
            while (n > 0) {
                int t = n % 10;
                n /= 10;
                temp += t * t;
            }
            n = temp;
            if (n == 1) {
                return true;
            }
            if (hash[n]) {
                // it will loops endlessly in a cycle which does not include 1
                return false;
            }
        }

        return false;
    }
};


int main() {
    Solution s;
    std::cout << s.isHappy(19) << std::endl;        // true
    
    return 0;
}
