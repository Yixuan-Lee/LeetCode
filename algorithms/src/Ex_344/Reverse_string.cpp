#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void reverseString(vector<char> &s) {
        if (s.empty()) {
            return;
        }
        auto l = 0;
        auto r = s.size() - 1;
        while (l < r) {
            char ch = s[l];
            s[l++] = s[r];
            s[r--] = ch;
        }
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
    vector<char> input;

    input = vector<char> {'h', 'e', 'l', 'l', 'o'};
    s.reverseString(input);
    std::cout << input << std::endl;

    input = vector<char> {};
    s.reverseString(input);
    std::cout << input << std::endl;

    return 0;
}
