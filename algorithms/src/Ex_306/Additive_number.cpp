// references:
//      https://leetcode.com/problems/additive-number/discuss/216334/C%2B%2B-backtracking
//      http://www.cplusplus.com/reference/string/stol/


#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool isAdditiveNumber(const string &num) {
        return isAdditive(num, "", "", false);
    }

private:
    bool isAdditive(const string &num, const string &first,
            const string &second, bool added) {
        if (num.empty()) {
            return added;
        }

        auto upperbound = static_cast<int> (num.size());
        if (first.empty()) {
            upperbound -= 2;
        } else if (second.empty()) {
            upperbound--;
        }

        for (int i = 0; i < upperbound; i++) {
            string str = num.substr(0, i + 1);

            // the additive sequence cannot have leading zeros
            if (str.size() > 1 && str[0] == '0') {
                break;
            }

            if (first.empty()) {
                if (isAdditive(num.substr(i + 1), str, second, added)) {
                    return true;
                }
            } else if (second.empty()) {
                if (isAdditive(num.substr(i + 1), first, str, added)) {
                    return true;
                }
            } else {
                if (first.length() + second.length() < str.length() - 1) {
                    break;
                }
                long int n1 = std::stol(first);
                long int n2 = std::stol(second);
                long int n3 = std::stol(str);

                if (n1 + n2 == n3) {
                    if (isAdditive(num.substr(i + 1), second, str, true)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    Solution s;

    std::cout << s.isAdditiveNumber("12012122436") << std::endl;     // 1

    std::cout << s.isAdditiveNumber("199100199") << std::endl;     // 1

    std::cout << s.isAdditiveNumber("112358") << std::endl;     // 1

    std::cout << s.isAdditiveNumber("114358") << std::endl;     // 0

    std::cout << s.isAdditiveNumber("114") << std::endl;     // 0

    std::cout << s.isAdditiveNumber("112") << std::endl;     // 1

    std::cout << s.isAdditiveNumber("121474836472147483648") << std::endl;// 1

    return 0;
}
