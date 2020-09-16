// references:
//      Ex_94_binary_tree_inorder_traversal: Binary_tree_inorder_traversal.cpp


#include <iostream>
#include <stack>
#include <queue>

using std::stack;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
    explicit BSTIterator(TreeNode *root) {
        TreeNode *it = root;
        stack<TreeNode *> st;

        while (it) {
            if (it->left) {
                // left child is not empty
                // push the current node and move it to its left child
                st.push(it);
                it = it->left;
            } else {
                // left child is empty
                // check its right child
                if (it->right != nullptr) {
                    // right child is not empty
                    // push the root node and value
                    values.push(it->val);
                    it = it->right;
                } else {
                    // left and right children are empty

                    values.push(it->val);
                    while (it->right == nullptr && !st.empty()) {
                        it = st.top();
                        st.pop();
                        values.push(it->val);
                    }

                    if (it->right == nullptr) {
                        break;
                    } else {
                        it = it->right;
                    }
                }
            }
        }
    }

    /** @return the next smallest number */
    int next() {
        if (!values.empty()) {
            int returnValue = values.front();
            values.pop();
            return returnValue;
        }
        return -1;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !values.empty();
    }

private:
    queue<int> values;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    auto *root = new TreeNode(3);
    TreeNode n1(2), n2(1), n3(4), n4(5), n5(6);
    root->left = &n1;
    n1.left = &n2;
    root->right = &n4;
    n4.left = &n3;
    n4.right = &n5;
    auto *obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();
    std::cout << param_1 << std::endl;      // 1
    std::cout << param_2 << std::endl;      // 1
    return 0;
}
