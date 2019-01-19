// references:
//      https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/66350/1-11-lines-Python-9-lines-C%2B%2B
//      http://www.cplusplus.com/reference/cctype/ispunct/


#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for (int i = 0; i < input.size(); i++) {
            char ch = input[i];
            if (ispunct(ch)) {
                // ch == '+' || '-' || '*', ispunct(ch) returns true
//                std::cout << ch << ",";
                for (int a : diffWaysToCompute(input.substr(0, i))) {
                    // input.substr(0, i): input[0...i-1]
                    for (int b : diffWaysToCompute(input.substr(i + 1))) {
                        // input.substr(i+1): input[i+1...end]
//                        std::cout << a << ch << b << ",";
                        switch (ch) {
                            case '+':
                                ans.push_back(a + b);
                                break;
                            case '-':
                                ans.push_back(a - b);
                                break;
                            case '*':
                                ans.push_back(a * b);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }

        return ans.empty() ? vector<int> {std::stoi(input)} : ans;
    }
};


// declare a template for overloading the << operator for vector<T>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<T> &v) {
    std::cout << "[";
    for (auto &i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;
    string str;

    str = "2-1-1";
    std::cout << s.diffWaysToCompute(str) << std::endl;     // [0, 2]

    str = "2*3-4*5";
    std::cout << s.diffWaysToCompute(str)
              << std::endl;     // [-34, -14, -10, -10, -10]

    str = "2+3*4-5";
    std::cout << s.diffWaysToCompute(str)
              << std::endl;     // [-1, -5, 9, 9, 15]

    str = "6";
    std::cout << s.diffWaysToCompute(str) << std::endl;     // [6]

    str = "10*12-20";
    std::cout << s.diffWaysToCompute(str) << std::endl;     // [100, -80]

    return 0;
}
