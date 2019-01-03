// references:
//      https://leetcode.com/problems/fraction-to-recurring-decimal/discuss/51160/0ms-C%2B%2B-Solution-with-Detailed-Explanations  (great article)
//      http://www.cplusplus.com/reference/string/string/insert/


#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        string ans;
        // decide the sign of the result
        if ((numerator < 0) ^ (denominator < 0)) {
            ans += "-";
        }
        // make numerator and denominator be positive
        long realNumerator = (numerator < 0)
                             ? static_cast<long> (numerator) * -1
                             : static_cast<long> (numerator);
        long realDenominator = (denominator < 0)
                               ? static_cast<long> (denominator) * -1
                               : static_cast<long> (denominator);
        // calculate the integral part
        long integer = realNumerator / realDenominator;
        ans += std::to_string(integer);

        // calculate the remainder
        long remainder = realNumerator % realDenominator;
        if (remainder == 0) {
            return ans;
        } else {
            // deal with remainder
            ans += ".";
            remainder *= 10;
            // record
            //      first:  remainders that have been appeared
            //      second: remainders' position where they appear
            map<long, long> rmds;

            while (remainder) {
                long quotient = remainder / realDenominator;
                if (rmds.find(remainder) != rmds.end()) {
                    // if the remainder recurs, then deal with '(' and ')'

                    // string& insert (size_t pos, size_t n, char c);
                    //      insert n consecutive copies of character c
                    //      at the position pos
                    // insert 1 '(' at the position where remainder first appeared
                    ans.insert(rmds[remainder], 1, '(');
                    // append a ')' at the end
                    ans += ')';
                    break;
                } else {
                    rmds[remainder] = ans.size();
                    ans += std::to_string(quotient);
                    remainder = (remainder % realDenominator) * 10;
                }
            }

            return ans;
        }
    }
};


int main() {
    Solution s;
    std::cout << s.fractionToDecimal(1, 2) << std::endl;        // 0.5

    std::cout << s.fractionToDecimal(2, 1) << std::endl;        // 2

    std::cout << s.fractionToDecimal(2, 3) << std::endl;        // 0.(6)

    std::cout << s.fractionToDecimal(4, 333) << std::endl;      // 0.(012)

    std::cout << s.fractionToDecimal(1, 7) << std::endl;        // 0.(142857)

    std::cout << s.fractionToDecimal(0, 333) << std::endl;      // 0

    std::cout << s.fractionToDecimal(-4, 9) << std::endl;       // -0.(4)

    return 0;
}
