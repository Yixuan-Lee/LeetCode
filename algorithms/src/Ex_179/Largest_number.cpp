#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::vector;
using std::string;
using std::stack;

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
        if (allZeroes == true) {
            return "0";
        }

        // declare the comparable rules
        struct {
            bool operator()(int n1, int n2) const {
                stack<int> s1;
                stack<int> s2;
                int t1 = n1;
                int t2 = n2;
                int firstDigitOfN1 = 0;     // 0 by default
                int firstDigitOfN2 = 0;     // 0 by default
                while (t1 > 0) {
                    s1.push(t1 % 10);
                    t1 /= 10;
                }
                if (s1.empty()) {
                    // avoid 0 condition
                    s1.push(0);
                } else {
                    firstDigitOfN1 = s1.top();
                }
                while (t2 > 0) {
                    s2.push(t2 % 10);
                    t2 /= 10;
                }
                if (s2.empty()) {
                    // avoid 0 condition
                    s2.push(0);
                } else {
                    firstDigitOfN2 = s2.top();
                }

                while (!s1.empty() && !s2.empty()) {
                    t1 = s1.top();
                    t2 = s2.top();
                    s1.pop();
                    s2.pop();
                    if (t1 > t2) {
                        return true;
                    } else if (t1 < t2) {
                        return false;
                    }
                }
                if (!s1.empty()) {
                    // if n1 has more digits than n2, and the first digits
                    // equal to each bit of n2
                    //
                    // so we should put n2 before n1
                    // if the first digit of left digits of s1 is smaller than the first digit of s1
                    // e.g. 332, 33
                    // because 2 < 3 (this 3 is first 3 of 332), so (33)(332) > (332)(33)
                    //
                    // we should put n2 after n1
                    // if the first digit of left digits of s1 is greater than the first digit of s1
                    // e.g. 334, 33
                    // because 4 > 3 (this 3 is first 3 of 334), so (334)(33) > (33)(334)
                    t1 = s1.top();
                    if (t1 <= firstDigitOfN1) {
                        // there should include '=', because of the test case [121, 12]
                        return false;
                    } else {
                        return true;
                    }
                }
                if (!s2.empty()) {
                    // same with the !s1.empty() branch
                    t2 = s2.top();
                    if (t2 <= firstDigitOfN2) {
                        // there should include '=', because of the test case [12, 121]
                        return true;
                    } else {
                        return false;
                    }
                }

                // normally, function should not return through this clause
                return false;
            }
        } customGreaterThan;
        std::sort(nums.begin(), nums.end(), customGreaterThan);

        for (const int &i : nums) {
            // for debugging
            std::cout << i << ",";
            ans += std::to_string(i);
        }
        std::cout << std::endl;

        return ans;
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {10, 2};
    std::cout << s.largestNumber(input) << std::endl;

    input = vector<int> {3, 30, 34, 5, 9};
    std::cout << s.largestNumber(input) << std::endl;

    input = vector<int> {12, 120};
    std::cout << s.largestNumber(input) << std::endl;

    input = vector<int> {128, 12};
    std::cout << s.largestNumber(input) << std::endl;

    input = vector<int> {0, 0};
    std::cout << s.largestNumber(input) << std::endl;

    input = vector<int> {824, 938, 1399, 5607, 6973, 5703, 9609, 4398, 8247};
    std::cout << s.largestNumber(input) << std::endl;

    input = vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << s.largestNumber(input) << std::endl;

    input = vector<int> {121, 12};
    std::cout << s.largestNumber(input) << std::endl;

    input = vector<int> {
            4704, 6306, 9385, 7536, 3462, 4798, 5422, 5529, 8070, 6241, 9094,
            7846, 663, 6221, 216, 6758, 8353, 3650, 3836, 8183, 3516, 5909,
            6744, 1548, 5712, 2281, 3664, 7100, 6698, 7321, 4980, 8937, 3163,
            5784, 3298, 9890, 1090, 7605, 1380, 1147, 1495, 3699, 9448, 5208,
            9456, 3846, 3567, 6856, 2000, 3575, 7205, 2697, 5972, 7471, 1763,
            1143, 1417, 6038, 2313, 6554, 9026, 8107, 9827, 7982, 9685, 3905,
            8939, 1048, 282, 7423, 6327, 2970, 4453, 5460, 3399, 9533, 914,
            3932, 192, 3084, 6806, 273, 4283, 2060, 5682, 2, 2362, 4812, 7032,
            810, 2465, 6511, 213, 2362, 3021, 2745, 3636, 6265, 1518, 8398
    };
    std::cout << s.largestNumber(input) << std::endl;


    string s1 = "70282274527326972465236223622313222812162132060200019217631";
    string s2 = "70282274527326972465236223622313228122162132060200019217631";

    std::cout << (s1 == s2) << std::endl;

    return 0;
}
