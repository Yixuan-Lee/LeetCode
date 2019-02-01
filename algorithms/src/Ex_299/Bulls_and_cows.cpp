#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    string getHint(const string &secret, const string &guess) {
        // first: character
        // second: number or occurrence of character in guess
        unordered_map<char, int> hashCharacter2NumInGuess;
        // first: character
        // second: number of occurrence of character in secret
        unordered_map<char, int> hashCharacter2NumInSecret;
        // initialize
        for (int i = 0; i < 10; i++) {
            hashCharacter2NumInGuess['0' + i] = 0;
            hashCharacter2NumInSecret['0' + i] = 0;
        }

        int numOfRightDigits = 0;
        int numOfRightPositionAndDigit = 0;

        // as mentioned in question, lengthS always equals to lengthG
        auto lengthS = static_cast<int>(secret.length());
        auto lengthG = static_cast<int>(guess.length());

        for (int i = 0; i < lengthG; i++) {
            if (secret[i] == guess[i]) {
                numOfRightPositionAndDigit++;
            }
            hashCharacter2NumInGuess[guess[i]]++;
            hashCharacter2NumInSecret[secret[i]]++;
        }

        // calculate number of correct digits but not right position
        for (char c = '0'; c <= '9'; c++) {
            if (hashCharacter2NumInSecret[c] == 0
                || hashCharacter2NumInGuess[c] == 0) {
                continue;
            }
            numOfRightDigits += std::min(hashCharacter2NumInGuess[c],
                    hashCharacter2NumInSecret[c]);
        }
        numOfRightDigits -= numOfRightPositionAndDigit;

        return std::to_string(numOfRightPositionAndDigit) + "A"
               + std::to_string(numOfRightDigits) + "B";
    }
};


int main() {
    Solution s;

    std::cout << s.getHint("1807", "7810") << std::endl;    // "1A3B"

    std::cout << s.getHint("1123", "0111") << std::endl;    // "1A1B"

    return 0;
}
