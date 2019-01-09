#include <iostream>
#include <map>

using std::map;

class Solution {
public:
    int countPrimes(int n) {
        map<int, bool> hash;
        for (int i = 2; i < n; i++) {
            hash[i] = true;
        }

        hash[2] = true;
        int count = 2;
        int primes = 0;
        while (count < n) {
            if (hash[count]) {
                for (int i = 2; i * count < n; i++) {
                    hash[i * count] = false;
                }
                primes++;
            }
            count++;
        }

        return primes;
    }
};


int main() {
    Solution s;
    std::cout << s.countPrimes(10) << std::endl;        // 4
    return 0;
}
