#include <iostream>
#include <string>
#include <set>

using std::string;
using std::set;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node("m");
    };

    /** Inserts a word into the trie. */
    void insert(const string &word) {
        Node *it = root;
        while (it) {
            int comp = word.compare(it->value);
            if (comp <= 0) {
                if (it->left) {
                    it = it->left;
                } else {
                    Node *newNode = new Node(word);
                    it->left = newNode;
                    break;
                }
            } else {
                if (it->right) {
                    it = it->right;
                } else {
                    Node *newNode = new Node(word);
                    it->right = newNode;
                    break;
                }
            }
        }
    }

    /** Returns if the word is in the trie. */
    bool search(const string &word) {
        Node *it = root;
        while (it) {
            int comp = word.compare(it->value);
            if (comp == 0) {
                return true;
            } else if (comp < 0) {
                it = it->left;
            } else {
                it = it->right;
            }
        }

        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix) {
        Node *it = root;
        while (it) {
            int comp = prefix.compare(it->value.substr(0, prefix.size()));
            if (comp == 0) {
                return true;
            } else if (comp < 0) {
                it = it->left;
            } else {
                it = it->right;
            }
        }

        return false;
    }

private:
    class Node {
    public:
        string value;
        Node *left;
        Node *right;
        Node *parent;

        explicit Node(string val) : value(std::move(val)),
                                    left(nullptr),
                                    right(nullptr),
                                    parent(nullptr) {
        }
    };

    Node *root;
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
