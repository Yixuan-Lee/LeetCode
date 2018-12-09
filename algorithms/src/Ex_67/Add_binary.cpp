//
// Created by  liyixuan on 2018-12-07.
//
// references:
//      https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c


#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::vector;
using std::string;
using std::stack;

class Solution {
public:
    string addBinary (string a, string b) {
        if (a.empty() && b.empty()) {
            return "";
        }
        if (a.empty()) {
            return b;
        }
        if (b.empty()) {
            return a;
        }

        stack<char> resVec;
        auto size_a = static_cast<int>(a.size());
        auto size_b = static_cast<int>(b.size());
        int sum;
        int carry = 0;
        int i = size_a - 1;
        int j = size_b - 1;

        // add until reaching to the end of one of two strings
        while (i >= 0 && j >= 0) {
            sum = (a[i--] - '0') + (b[j--] - '0') + carry;
            carry = 0;  // reset carry after adding it
            if (sum >= 2) {
                carry = 1;
                sum -= 2;
            }
            resVec.push(static_cast<char &&>(sum + '0'));
        }

        // if a is not done
        while (i >= 0) {
            sum = (a[i--] - '0') + carry;   // do not forget the carry
            carry = 0;  // reset carry after adding it
            if (sum >= 2) {
                carry = 1;
                sum -= 2;
            }
            resVec.push(static_cast<char &&>(sum + '0'));
        }

        // if b is not done
        while (j >= 0) {
            sum = (b[j--] - '0') + carry;   // do not forget the carry
            carry = 0;  // reset carry after adding it
            if (sum >= 2) {
                carry = 1;
                sum -= 2;
            }
            resVec.push(static_cast<char &&>(sum + '0'));
        }

        // if carry is still 1, then push the carry
        if (carry) {
            resVec.push(static_cast<char &&>(carry + '0'));
        }

        string res;
        while (!resVec.empty()) {
            res += resVec.top();
            resVec.pop();
        }
        return res;
    }
};


int main () {
    Solution s;
    string a = "1111";
    string b = "1111";
    string res = s.addBinary(a, b);
    std::cout << res << std::endl;
    return 0;
}