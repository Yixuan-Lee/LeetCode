#include <iostream>
#include <string>
#include <deque>

using std::string;
using std::deque;

class Solution {
public:
    int calculate(string s) {
        if (s.empty()) {
            return 0;
        }

        deque<int> nums;
        deque<char> ops;
        bool calc = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (isdigit(s[i])) {
                string numStr;
                int j;
                for (j = i; j < s.size() && isdigit(s[j]); j++) {
                    numStr += s[j];
                }
                nums.push_back(std::stoi(numStr));
                i = j - 1;

                if (calc) {
                    int num1 = nums.back();
                    nums.pop_back();
                    int num2 = nums.back();
                    nums.pop_back();
                    char op = ops.back();
                    ops.pop_back();
                    switch (op) {
                        case '*':
                            nums.push_back(num2 * num1);
                            break;
                        case '/':
                            nums.push_back(num2 / num1);
                            break;
                        default:
                            break;
                    }
                    calc = false;
                }
            } else {
                // operators
                if (s[i] == '*' || s[i] == '/') {
                    calc = true;
                }
                ops.push_back(s[i]);
            }
        }

        // scan the resting nums and ops in the deque from left to right
        while (!ops.empty()) {
            int num1 = nums.front();
            nums.pop_front();
            int num2 = nums.front();
            nums.pop_front();
            char op = ops.front();
            ops.pop_front();
            switch (op) {
                case '+':
                    nums.push_front(num1 + num2);
                    break;
                case '-':
                    nums.push_front(num1 - num2);
                    break;
                default:
                    break;
            }
        }

        return nums.front();
    }
};


int main() {
    Solution s;
    string expressions;

    expressions = "3+2*2";
    std::cout << s.calculate(expressions) << std::endl;     // 7

    expressions = " 3/2";
    std::cout << s.calculate(expressions) << std::endl;     // 1

    expressions = " 3+5 / 2 ";
    std::cout << s.calculate(expressions) << std::endl;     // 5

    expressions = "42";
    std::cout << s.calculate(expressions) << std::endl;     // 42

    expressions = " 12+24 * 5 /  3  ";
    std::cout << s.calculate(expressions) << std::endl;     // 52

    expressions = "1-1+1";
    std::cout << s.calculate(expressions) << std::endl;     // 1

    expressions = "1-2*3-4+10 / 5";
    std::cout << s.calculate(expressions) << std::endl;     // -7

    return 0;
}
