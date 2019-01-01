#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // defines an iterator
        TreeNode *it = root;

        // stores the final result
        vector<int> traversal;

        // stores the nodes that we are currently visiting its left tree nodes
        stack<TreeNode *> st;

        while (it != nullptr) {
            // put the current value to the result vector
            traversal.push_back(it->val);

            if (it->left != nullptr) {
                // if its left child is not empty, then temporarily push the
                // current node into the stack, and then visit its left node
                st.push(it);
                it = it->left;
            } else {
                // if left child is empty, and its right node is not empty,
                // then traverse its right sub-tree
                if (it->right != nullptr) {
                    it = it->right;
                } else {
                    // if its left child and right child are empty, then
                    // return to its parent node which right child is not empty
                    while (it->right == nullptr && !st.empty()) {
                        it = st.top();
                        st.pop();
                    }

                    // if st has already been empty, and it->right is still
                    // empty, it means that we have reached the end, then break
                    if (it->right == nullptr) {
                        break;
                    }

                    // visit to its right node
                    it = it->right;
                }
            }
        }

        return traversal;
    }
};


// declare a template for overloading the << operator for vector<T>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<T> &v) {
    std::cout << "[";
    for (auto &i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;
    TreeNode a1(1), a2(2), a3(3);
    a1.right = &a2;
    a2.left = &a3;
    vector<int> res = s.preorderTraversal(&a1);
    std::cout << res << std::endl;

    TreeNode b1(1), b2(2), b3(3), b4(4), b5(5), b6(6), b7(7), b8(8);
    b1.left = &b2;
    b1.right = &b3;
    b2.left = &b4;
    b3.left = &b6;
    b3.right = &b7;
    b4.left = &b5;
    b6.right = &b8;
    res = s.preorderTraversal(&b1);
    std::cout << res << std::endl;

    TreeNode c1(1);
    res = s.preorderTraversal(&c1);
    std::cout << res << std::endl;

    res = s.preorderTraversal(nullptr);
    std::cout << res << std::endl;

    return 0;
}
