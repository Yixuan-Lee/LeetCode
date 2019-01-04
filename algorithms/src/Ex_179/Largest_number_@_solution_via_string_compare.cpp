// references:
//      https://leetcode.com/articles/largest-number/


#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        string ans;
        if (nums.empty()) {
            return ans;
        }

        // convert all numbers to strings
        vector<string> asStrs;
        asStrs.reserve(nums.size());
        for (const int &i : nums) {
            asStrs.push_back(std::to_string(i));
        }

        // declare the custom comparable rules
        struct {
            bool operator()(const string &a, const string &b) {
                string order1 = a + b;
                string order2 = b + a;
                int result = order1.compare(order2);
                return result > 0;
            }
        } customGreaterThan;
        std::sort(asStrs.begin(), asStrs.end(), customGreaterThan);

        // for debugging
//        for (const string &str : asStrs) {
//            std::cout << str << ", ";
//        }

        if (asStrs[0] == "0") {
            // if the largest number is 0, then return "0" directly
            return "0";
        }

        // build largest number from sorted string array
        for (const string &numAsStr : asStrs) {
            ans += numAsStr;
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
