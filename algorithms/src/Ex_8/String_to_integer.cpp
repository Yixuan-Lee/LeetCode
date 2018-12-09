//
// Created by  liyixuan on 2018-11-10.
//

#include <iostream>
#include <string>
#include <cstdlib>

using std::string;

class Solution {
public:
    int myAtoi(string str) {
        char sign = '+';    // '+' by default
        char num[1024];
        long value = 0;
        int i, j = 0;
        const int MAX = (1 << 31) - 1;
        const int MIN = (1 << 31) * (-1);
        // find the first non-whitespace character
        for (i = 0; i < str.length() && str[i] == ' '; i++);
        if (str[i] == '+' || str[i] == '-') {
            sign = str[i];
            i++;
        }
        // invalid conversion
        if (!isdigit(str[i]))
            return 0;
        // store the numerical characters until meeting a non-numerical character
        for ( ; i < str.length() && isdigit(str[i]); i++, j++) {
            num[j] = str[i];
        }
        // calculate
        value = value * 10 + (num[0] - '0');
        int m = 1;  // indicates (sign=='+' ~ m = +1) or (sign=='-' ~ m = -1)
        if (sign == '-') {
            value = -value;
            m = -1;
        }
        for (int k = 1; k < j; k++) {
            value = value * 10 + (num[k] - '0') * m;
            if (value > MAX)
                return MAX;
            else if (value < MIN)
                return MIN;
        }
        return value;
    }
};

int main() {
    Solution s;
    string str;
    std::cin >> str;
    std::cout << s.myAtoi(str) << std::endl;
    return 0;
}
