#include <iostream>
#include <stack>
#include <string>

using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0)
            return true;

        // stores each parenthese
        stack<char> st;
        int i = 0;
        int length = s.length();
        while (i < length) {
            switch (s[i]) {
                case '(':
                    st.push(s[i]);
                    break;
                case '[':
                    st.push(s[i]);
                    break;
                case '{':
                    st.push(s[i]);
                    break;
                case ')':
                    if (st.empty() || '(' != st.top())
                        return false;
                    st.pop();
                    break;
                case ']':
                    if (st.empty() || '[' != st.top())
                        return false;
                    st.pop();
                    break;
                case '}':
                    if (st.empty() || '{' != st.top())
                        return false;
                    st.pop();
                    break;
            }
            i++;
        }
        if (st.empty())
            return true;
        return false;
    }
};

int main() {
    Solution s;
    string str;
    std::cin >> str;
    std::cout << s.isValid(str) << std::endl;
    return 0;
}
