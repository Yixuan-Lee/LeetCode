//
// Created by  liyixuan on 2018-12-01.
//
// references:
//      https://leetcode.com/problems/multiply-strings/discuss/17605/Easiest-JAVA-Solution-with-Graph-Explanation
//

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string multiply (string num1, string num2) {
        int m = static_cast<int>(num1.length());
        int n = static_cast<int>(num2.length());
        int *pos = new int[m + n];
        memset(pos, 0, (m + n) * sizeof(int));

        // num1 loop
        for (int i = m - 1; i >= 0; i--) {
            // num2 loop
            for (int j = n - 1; j >= 0; j--) {
                int res_mul = (num1[i] - '0') * (num2[j] - '0');
                int position1 =
                        i + j;      // first position for tens(十位数) digit
                int position2 =
                        i + j + 1;  // second position for units(个位数) digit
                int sum = res_mul + pos[position2]; //
                pos[position1] += sum / 10;
                pos[position2] = sum % 10;
            }
        }

        string res;
        for (int i = 0; i < m + n; i++) {
            if (*(pos + i) == 0 && res.length() == 0) {
                continue;
            }
            res += std::to_string(*(pos + i));
        }

        delete (pos);
        pos = nullptr;

        return res.length() == 0 ? "0" : res;
    }
};


int main () {
    Solution s;
    string s1 = "123", s2 = "45";
    std::cout << s.multiply(s1, s2) << std::endl;
    return 0;
}