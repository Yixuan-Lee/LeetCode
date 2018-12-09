//
// Created by  liyixuan on 2018-11-12.
//

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        int length = s.length();
        for (int i = 0; i < length; i++) {
            switch(s[i]) {
                case 'I':
                    if ((i < length - 1 && s[i+1] != 'V')
                        && (i < length - 1 && s[i+1] != 'X')) {
                        value += 1;
                    } else if (i < length - 1) {
                        value -= 1;
                    } else {
                        value += 1;
                    }
                    break;
                case 'V':
                    value += 5;
                    break;
                case 'X':
                    if ((i < length - 1 && s[i+1] != 'L')
                        && (i < length - 1 && s[i+1] != 'C')) {
                        value += 10;
                    } else if (i < length - 1) {
                        value -= 10;
                    } else {
                        value += 10;
                    }
                    break;
                case 'L':
                    value += 50;
                    break;
                case 'C':
                    if ((i < length - 1 && s[i+1] != 'D')
                        && (i < length - 1 && s[i+1] != 'M')) {
                        value += 100;
                    } else if (i < length - 1) {
                        value -= 100;
                    } else {
                        value += 100;
                    }
                    break;
                case 'D':
                    value += 500;
                    break;
                case 'M':
                    value += 1000;
                    break;
                default:
                    break;
            }
        }
        return value;
    }
};

int main() {
    Solution s;
    string str;
    std::cin >> str;
    std::cout << s.romanToInt(str) << std::endl;
    return 0;
}