// references:
//      Ex_208: Implement Trie (Prefix Tree)


#include <iostream>
#include <string>

using std::string;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(const string &word) {
        TrieNode *node = root;
        for (const char &currChar : word) {
            if (!node->containKey(currChar)) {
                node->put(currChar, new TrieNode());
                node = node->get(currChar);
            } else {
                node = node->get(currChar);
            }
        }
        node->setEnd();
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string &word) {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == '.') {
                // delegate to function search(Trienode *, const string &word);

                // for debugging
//                std::cout << word.substr(i + 1) << std::endl;

                bool res = false;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (res) {
                        return true;
                    }
                    if (node->containKey(ch)) {
                        res = search(node->get(ch), word.substr(i + 1));
                    }
                }
                if (!res) {
                    return false;
                }
            } else if (node->containKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return false;
            }
        }

        return node->getEnd();
    }

private:
    class TrieNode {
    public:
        TrieNode() {
            isEnd = false;
            links = new TrieNode *[R];
            // initialize as null
            for (int i = 0; i < R; i++) {
                *(links + i) = nullptr;
            }
        }

        bool containKey(char ch) {
            return *(links + ch - 'a') != nullptr;
        }

        TrieNode *get(char ch) {
            return *(links + ch - 'a');
        }

        void put(char ch, TrieNode *node) {
            *(links + ch - 'a') = node;
        }

        void setEnd() {
            isEnd = true;
        }

        bool getEnd() {
            return isEnd;
        }

    private:
        TrieNode **links;
        const int R = 26;
        bool isEnd;
    };

    bool search(TrieNode *node, const string &word) {
        if (word.empty()) {
            return node->getEnd();
        }

        for (int i = 0; i < word.length(); i++) {
            if (word[i] == '.') {
                bool res = false;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (res) {
                        return true;
                    }
                    if (node->containKey(ch)) {
                        res = search(node->get(ch), word.substr(i + 1));
                    }
                }
                if (!res) {
                    return false;
                }
            } else if (node->containKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return false;
            }
        }

        return node->getEnd();
    }

    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */


int main() {
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    std::cout << wd.search("pad") << std::endl;   // 0
    std::cout << wd.search("bad") << std::endl;   // 1
    std::cout << wd.search(".ad") << std::endl;   // 1
    std::cout << wd.search("b..") << std::endl;   // 1
    std::cout << wd.search("...") << std::endl;   // 1
    std::cout << wd.search("..c") << std::endl;   // 0
    std::cout << wd.search("...c") << std::endl;  // 0

    std::cout << "=============================" << std::endl;

    WordDictionary wd2;
    wd2.addWord("at");
    wd2.addWord("and");
    wd2.addWord("an");
    wd2.addWord("add");
    std::cout << wd2.search("a") << std::endl;        // 0
    std::cout << wd2.search(".at") << std::endl;      // 0
    wd2.addWord("bat");
    std::cout << wd2.search(".at") << std::endl;      // 1
    std::cout << wd2.search("an.") << std::endl;      // 1
    std::cout << wd2.search("a.d.") << std::endl;     // 0
    std::cout << wd2.search("b.") << std::endl;       // 0
    std::cout << wd2.search("a.d") << std::endl;      // 1
    std::cout << wd2.search(".") << std::endl;        // 0
    return 0;
}
