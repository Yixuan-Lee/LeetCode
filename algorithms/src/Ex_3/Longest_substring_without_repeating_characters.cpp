// references:
//      https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/


#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        int prev_index = 0;
        int cur_len = 1;
        int max_len = 1;
        int visited[204800];
        visited[s[0]] = 0;
        int length = s.length();
        for (int i = 0; i < length; i++)
            visited[i] = -1;
        for (int i = 1; i < length; i++) {
            prev_index = visited[s[i]];
            if (prev_index == -1 || i - cur_len > prev_index)
                cur_len++;
            else {
                if (cur_len > max_len)
                    max_len = cur_len;
                cur_len = i - prev_index;
            }
            visited[s[i]] = i;
        }
        if (cur_len > max_len)
            max_len = cur_len;
        return max_len;
    }
};

int main() {
    Solution s;
    string str;
    std::cin >> str;
//    std::cout << str.length();
    std::cout << s.lengthOfLongestSubstring(str) << std::endl;
    return 0;
}
