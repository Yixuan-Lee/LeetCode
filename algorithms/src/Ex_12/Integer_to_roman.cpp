// references:
//      https://leetcode.com/problems/integer-to-roman/discuss/192698/Solved-(in-Java)
//      https://stackoverflow.com/questions/12731493/2d-array-with-two-different-datatypes
//      http://www.cplusplus.com/reference/utility/pair/pair/


#include <iostream>
#include <string>
#include <utility>
#include <map>

using std::string;
using std::map;
using std::pair;

class Solution {
public:
//    string numToString(int num) {
//
//        string res;
//        switch(num) {
//            case 1000:
//                res = "M";
//                break;
//            case 900:
//                res = "CM";
//                break;
//            case 500:
//                res = "D";
//                break;
//            case 400:
//                res = "CD";
//                break;
//            case 100:
//                res = "C";
//                break;
//            case 90:
//                res = "XC";
//                break;
//            case 50:
//                res = "L";
//                break;
//            case 40:
//                res = "XL";
//                break;
//            case 10:
//                res = "X";
//                break;
//            case 9:
//                res = "IX";
//                break;
//            case 5:
//                res = "V";
//                break;
//            case 4:
//                res = "IV";
//                break;
//            case 1:
//                res = "I";
//                break;
//            default:
//                break;
//        }
//        return res;
//    }

    string intToRoman(int num) {
        string result = "";
        pair<int, string> charToNumMap[] {
                {1000, "M"},
                {900,  "CM"},
                {500,  "D"},
                {400,  "CD"},
                {100,  "C"},
                {90,   "XC"},
                {50,   "L"},
                {40,   "XL"},
                {10,   "X"},
                {9,    "IX"},
                {5,    "V"},
                {4,    "IV"},
                {1,    "I"}
        };
        int currIndex = 0;
        int mapSize = 13;
        while (num > 0 && currIndex < mapSize) {
            int weight = num / charToNumMap[currIndex].first;
            while (weight > 0) {
                result += charToNumMap[currIndex].second;
                weight--;
            }
            num = num % charToNumMap[currIndex].first;
            currIndex++;
        }
        return result;
    }
};


int main() {
    Solution s;
    int num;
    std::cin >> num;
    std::cout << s.intToRoman(num) << std::endl;
    return 0;
}
