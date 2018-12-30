// references:
//      https://leetcode.com/articles/symmetric-tree/


#include <iostream>
#include <queue>

using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }

        queue<TreeNode *> que;
        que.push(root->left);
        que.push(root->right);

        while (!que.empty()) {
            TreeNode *p = que.front();
            que.pop();
            TreeNode *q = que.front();
            que.pop();
            if (!p && !q) {
                continue;
            }
            if (!p || !q) {
                return false;
            }
            if (p->val != q->val) {
                return false;
            }
            // insert left and right nodes in opposite order
            que.push(p->left);
            que.push(q->right);

            que.push(p->right);
            que.push(q->left);
        }
        return true;
    }
};


int main() {
    Solution s;
    TreeNode a1(1), a2(2), a3(2), a4(3), a5(4), a6(4), a7(3);
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a2.right = &a5;
    a3.left = &a6;
    a3.right = &a7;
    std::cout << s.isSymmetric(&a1) << std::endl;

    TreeNode b1(1), b2(2), b3(2), b4(3), b5(3);
    b1.left = &b2;
    b1.right = &b3;
    b2.right = &b4;
    b3.right = &b5;
    std::cout << s.isSymmetric(&b1) << std::endl;

    TreeNode c1(1), c2(2), c3(3), c4(3), c5(2);
    c1.left = &c2;
    c1.right = &c3;
    c2.left = &c4;
    c3.left = &c5;
    std::cout << s.isSymmetric(&c1) << std::endl;

    return 0;
}
