// references:
//      https://leetcode.com/articles/implement-trie-prefix-tree/  (great article)


#include <iostream>
#include <string>

using std::string;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(const string &word) {
        TrieNode *node = root;
        for (char currentChar : word) {
            if (!node->containKey(currentChar)) {
                node->put(currentChar, new TrieNode());
                node = node->get(currentChar);
            } else {
                node = node->get(currentChar);
            }
        }
        // set current position as an end position for a word that has been inserted
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(const string &word) {
        TrieNode *node = root;
        for (char currentChar : word) {
            if (node->containKey(currentChar)) {
                node = node->get(currentChar);
            } else {
                return false;
            }
        }
        return node->getEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix) {
        TrieNode *node = root;
        for (char currentChar : prefix) {
            if (node->containKey(currentChar)) {
                node = node->get(currentChar);
            } else {
                return false;
            }
        }

        return true;
    }

private:
    class TrieNode {
    public:
        TrieNode() {
            isEnd = false;
            links = new TrieNode *[R];
            // initializes to null
            for (int i = 0; i < R; i++) {
                links[i] = nullptr;
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
        // R links to node children
        TrieNode **links;   // points to an array of type of TrieNode*
        // 26 latin letters
        const int R = 26;
        // specifies if current character is the end for a word
        bool isEnd;
    };

    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */


int main() {
    Trie obj;
    obj.insert("apple");
    std::cout << obj.search("apple") << std::endl;      // 1
    std::cout << obj.search("app") << std::endl;        // 0
    std::cout << obj.startsWith("app") << std::endl;    // 1
    obj.insert("app");
    std::cout << obj.search("app") << std::endl;        // 1

    return 0;
}
