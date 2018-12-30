// references:
//      https://leetcode.com/problems/word-ladder/discuss/40707/Easy-76ms-C%2B%2B-Solution-using-BFS


#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <queue>

using std::vector;
using std::string;
using std::queue;
using std::unordered_set;

class Solution {
public:
    int ladderLength(const string &beginWord, const string &endWord,
            vector<string> &wordList) {
        if (!(
                std::find(wordList.begin(), wordList.end(), endWord)
                != wordList.end())) {
            // if wordList does not contain endWord
            return 0;
        }

        unordered_set<string> wordDict;
        for (const string &s : wordList) {
            wordDict.insert(s);
        }
        wordDict.insert(endWord);
        queue<string> toVisit;
        addNextWords(beginWord, wordDict, toVisit);

        int distance = 2;
        while (!toVisit.empty()) {
            auto num = static_cast<int> (toVisit.size());
            for (int i = 0; i < num; i++) {
                string word = toVisit.front();
                toVisit.pop();
//                std::cout << word << "->";
                if (word == endWord) {
                    return distance;    // only reachable conditions return through here
                }
                addNextWords(word, wordDict, toVisit);
            }
            distance++;
        }

        return 0;   // only unreachable conditions return through here
    }

private:
    void addNextWords(string word, unordered_set<string> &wordDict,
            queue<string> &toVisit) {
        wordDict.erase(word);
        for (int i = 0; i < word.length(); i++) {
            char letter = word[i];
            for (int j = 0; j < 26; j++) {
                word[i] = static_cast<char> ('a' + j);
                if (wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);     // push the next visited word
                    wordDict.erase(word);   // erase the word in the dict
                }
            }
            word[i] = letter;   // backtracking (reset the letter)
        }
    }
};


int main() {
    Solution s;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList {
            "hot", "dot", "dog", "lot", "log", "cog"
    };
    std::cout << s.ladderLength(beginWord, endWord, wordList)
              << std::endl;     // 5

    beginWord = "hit";
    endWord = "cog";
    wordList = vector<string> {
            "hot", "dot", "dog", "lot", "log"
    };
    std::cout << s.ladderLength(beginWord, endWord, wordList)
              << std::endl;     // 0

    beginWord = "hot";
    endWord = "dog";
    wordList = vector<string> {
            "hot", "dog"
    };
    std::cout << s.ladderLength(beginWord, endWord, wordList)
              << std::endl;     // 0

    beginWord = "talk";
    endWord = "tail";
    wordList = vector<string> {
            "talk", "tons", "fall", "tail", "gale", "hall", "negs"
    };
    std::cout << s.ladderLength(beginWord, endWord, wordList)
              << std::endl;     // 0

    return 0;
}
