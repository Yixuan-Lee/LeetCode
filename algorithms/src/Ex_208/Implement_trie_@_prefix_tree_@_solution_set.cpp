#include <iostream>
#include <string>
#include <set>

using std::string;
using std::set;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() = default;

    /** Inserts a word into the trie. */
    void insert(const string &word) {
        words.insert(word);
    }

    /** Returns if the word is in the trie. */
    bool search(const string &word) {
        return words.find(word) != words.end();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix) {
        for (const string &str : words) {
            if (str.substr(0, prefix.size()) == prefix) {
                return true;
            }
        }
        return false;
    }

private:
    set<string> words;
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
