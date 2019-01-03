// references:
//      https://leetcode.com/submissions/detail/198785611/ (sample 12ms submission)


#include <iostream>
#include <stack>

using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
    explicit BSTIterator(TreeNode *root) {
        TreeNode *curr = root;
        // move curr to the most left node, and push the intermediate parent nodes
        while (curr != nullptr) {
            parents.push(curr);
            curr = curr->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        if (hasNext()) {
            TreeNode *curr = parents.top();
            parents.pop();
            int value = curr->val;
            curr = curr->right;
            while (curr != nullptr) {
                parents.push(curr);
                curr = curr->left;
            }
            return value;
        }
        return -1;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !parents.empty();
    }

private:
    stack<TreeNode *> parents;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    auto *root = new TreeNode(7);
    TreeNode n1(3), n2(15), n3(9), n4(20);
    root->left = &n1;
    root->right = &n2;
    n2.left = &n3;
    n2.right = &n4;
    auto *iterator = new BSTIterator(root);
    std::cout << iterator->next() << std::endl;             // 3
    std::cout << iterator->next() << std::endl;             // 7
    std::cout << (iterator->hasNext() ? "true" : "fasle")
              << std::endl;                                 // true
    std::cout << iterator->next() << std::endl;             // 9
    std::cout << (iterator->hasNext() ? "true" : "fasle")
              << std::endl;                                 // true
    std::cout << iterator->next() << std::endl;             // 15
    std::cout << (iterator->hasNext() ? "true" : "fasle")
              << std::endl;                                 // true
    std::cout << iterator->next() << std::endl;             // 20
    std::cout << (iterator->hasNext() ? "true" : "fasle")
              << std::endl;                                 // false;

    return 0;
}
