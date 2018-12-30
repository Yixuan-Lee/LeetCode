// references:
//      https://leetcode.com/articles/zigzag-conversion/
//      https://stackoverflow.com/questions/20461424/error-variable-length-array-of-non-pod-element-type-string


#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length() == 1 || s.length() == 0) {
            return s;
        }
        if (numRows == 1) {
            return s;
        }

        string *rows = new string[numRows];   // stores each row's string
        // initialize the rows
        for (int i = 0; i < numRows; i++) {
            rows[i] = "";
        }

        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown; // change the direction
            }
            currRow += goingDown ? 1 : -1;
        }

        string result;
        for (int i = 0; i < numRows; i++) {
            for (const char &row : rows[i]) {
                result += row;
            }
        }

        // free the heap resources
        delete[] rows;

        return result;
    }
};

int main() {
    Solution s;
    std::cout << s.convert("PAYPALISHIRING", 3) << std::endl;
    return 0;
}
