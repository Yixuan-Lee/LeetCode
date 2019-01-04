#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        string ans;
        if (nums.empty()) {
            return ans;
        }

        // deal with all 0s scenario
        bool allZeroes = true;
        for (const int &i : nums) {
            if (i != 0) {
                allZeroes = false;
                break;
            }
        }
        if (allZeroes) {
            return "0";
        }

        // declare the custom comparable rules
        struct {
            bool operator()(int n1, int n2) const {
                string s1 = std::to_string(n1);
                string s2 = std::to_string(n2);
                auto bitsN1 = static_cast<int> (s1.size());
                auto bitsN2 = static_cast<int> (s2.size());
                auto feedN1 = static_cast<long> (pow(10, bitsN1));
                auto feedN2 = static_cast<long> (pow(10, bitsN2));

                return n1 * feedN2 + n2 >= n2 * feedN1 + n1;
            }
        } customGreaterThan;
        std::sort(nums.begin(), nums.end(), customGreaterThan);

        for (const int &i : nums) {
            ans += std::to_string(i);
        }

        return ans;
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {10, 2};
    std::cout << s.largestNumber(input) << std::endl;       // 210

    input = vector<int> {3, 30, 34, 5, 9};
    std::cout << s.largestNumber(input) << std::endl;       // 9534330

    input = vector<int> {12, 120};
    std::cout << s.largestNumber(input) << std::endl;       // 12120

    input = vector<int> {128, 12};
    std::cout << s.largestNumber(input) << std::endl;       // 12812

    input = vector<int> {0, 0};
    std::cout << s.largestNumber(input) << std::endl;       // 0

    input = vector<int> {824, 938, 1399, 5607, 6973, 5703, 9609, 4398, 8247};
    std::cout << s.largestNumber(input)
              << std::endl;                                 // 9609938824824769735703560743981399

    input = vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << s.largestNumber(input) << std::endl;       // 9876543210

    input = vector<int> {121, 12};
    std::cout << s.largestNumber(input) << std::endl;       // 12121

    return 0;
}
