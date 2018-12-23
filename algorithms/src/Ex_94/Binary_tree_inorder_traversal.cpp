// references:
//      https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/201705/Java-code-100-fastest-without-recurson


#include <iostream>
#include <vector>
#include <list>
#include <stack>

using std::vector;
using std::list;
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *head = root;

        // stores the final-result values
        vector<int> traversal;

        // stores the nodes that we are currently visiting its left tree nodes
        stack<TreeNode *> st;

        while (head != nullptr) {
            if (head->left != nullptr) {
                // if left child is not empty, then temporarily push current
                // node into stack, then visit its left node
                st.push(head);
                head = head->left;
            } else {
                // if left child is empty and right node is not empty, then
                // put current node to the final-result vector, then move
                // head to its right node
                if (head->right != nullptr) {
                    traversal.push_back(head->val);
                    head = head->right;
                } else {
                    // if left child and right child are empty, then put
                    // current node to the final-result vector,
                    traversal.push_back(head->val);

                    // if the stack is empty, then break the traversal loop
                    if (st.empty()) {
                        break;
                    }

                    // if the stack is not empty, then take the latest inserted
                    // node, and make head point to it, then put its value
                    // to the final-result vector, and visit its right node
                    while (head->right == nullptr && !st.empty()) {
                        head = st.top();
                        st.pop();
                        traversal.push_back(head->val);
                    }

                    // since we have visited its left-tree nodes, so if its
                    // right tree is empty, then break the traversal loop
                    if (head->right == nullptr) {
                        break;
                    }

                    // if not, then move head to its right node
                    head = head->right;
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
    TreeNode a(1), b(2), c(3);
    a.right = &b;
    a.left = &c;
    vector<int> res = s.inorderTraversal(&a);
    std::cout << res << std::endl;
    return 0;
}
