// reference:
//      http://www.cnblogs.com/grandyang/p/4452220.html


#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> res {""};
        string dict[] {
                "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"
        };
        for (int i = 0; i < digits.length(); i++) {
            vector<string> temp;
            string str = dict[digits[i] - '0' - 2];
            for (int j = 0; j < str.length(); j++) {
                for (string s : res) {
                    temp.push_back(s + str[j]);
                }
            }
            res = temp;
        }
        return res;
    }
};

int main() {
    Solution s;
    string digits = "23";
    vector<string> result = s.letterCombinations(digits);
    for (const string &str : result) {
        std::cout << str << ", " << std::endl;
    }
    return 0;
}



//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//
//using std::string;
//using std::vector;
//using std::pair;
//using std::map;
//
//class Solution {
//public:
//    vector<string> letterCombinations(const string &digits) {
//        if (digits.length() == 0) {
//            return { };
//        }
//
//        vector<string> result {""};
//        const int length = static_cast<const int>(digits.length());
//        // indicate each character position in each digit's array
//        int* position = new int[length];
//        // indicate length of char2digit for each digit
//        int lengthOfCharArray[] {3, 3, 3, 3, 3, 4, 3, 4};
//        // initialize the position array
//        memset(position, 0, length * sizeof(int));
//
//        string str;
//        for (int i = 0; i < digits.length(); i++) {
//            str += char2digits.find(digits[i])->second[*(position + i)];
//        }
//
//        result.push_back(str);
//
//        while (true) {
//            str = "";
//            for (int i = 0; i < digits.length(); i++) {
//                if (++(*(position + i)) == lengthOfCharArray[digits[i] - '0' - 2]) {
//                    *(position + i) = 0;
//                    (*(position + i + 1)) ++;
//                }
//                str += char2digits.find(digits[i])->second[++(*(position + i))];
//            }
//            result.push_back(str);
//        }
////        do {
////            str =
////            for (int i = 0; i < digits.length(); i++) {
////                str += char2digits.find(digits[i])->second[*(position + i)];
////                (*(position + i))++;
////                if (*(position + i) > std::strlen(char2digits.find(digits[i])->second)) {
////                    *(position + i) = 0;
////                    *(position + )
////                }
////            }
////        } while (allCharacterAtEndPosition(digits, position));
//
//        delete(position);
//        return result;
//    }
//
//    Solution() {
//        digit2 = new char[3] {'a', 'b', 'c'};
//        digit3 = new char[3] {'d', 'e', 'f'};
//        digit4 = new char[3] {'g', 'h', 'i'};
//        digit5 = new char[3] {'j', 'k', 'l'};
//        digit6 = new char[3] {'m', 'n', 'o'};
//        digit7 = new char[4] {'p', 'q', 'r', 's'};
//        digit8 = new char[3] {'t', 'u', 'v'};
//        digit9 = new char[4] {'w', 'x', 'y', 'z'};
//        char2digits.insert(pair<char, char*>('2', digit2));
//        char2digits.insert(pair<char, char*>('3', digit3));
//        char2digits.insert(pair<char, char*>('4', digit4));
//        char2digits.insert(pair<char, char*>('5', digit5));
//        char2digits.insert(pair<char, char*>('6', digit6));
//        char2digits.insert(pair<char, char*>('7', digit7));
//        char2digits.insert(pair<char, char*>('8', digit8));
//        char2digits.insert(pair<char, char*>('9', digit9));
//    }
//
//    ~Solution() {
//        delete(digit2);
//        delete(digit3);
//        delete(digit4);
//        delete(digit5);
//        delete(digit6);
//        delete(digit7);
//        delete(digit8);
//        delete(digit9);
//    }
//
//private:
//    map<char, char*> char2digits;
//    char* digit2;
//    char* digit3;
//    char* digit4;
//    char* digit5;
//    char* digit6;
//    char* digit7;
//    char* digit8;
//    char* digit9;
//
//    bool allCharacterAtEndPosition(const string &digits, const int* const position) {
//        for (int i = 0; i < digits.length(); i++) {
//            if (*(position + i) != lengthOfCharArray(char2digits[digits[i]]) - 1) {
//                return false;
//            }
//        }
//        return true;
//    }
//};
//
