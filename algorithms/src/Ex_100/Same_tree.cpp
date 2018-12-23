#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && q) {
            return false;
        }
        if (p && !q) {
            return false;
        }
        if (p && q) {
            if (p->val != q->val) {
                isIdentical = false;
                return false;
            }
            isIdentical = isSameTree(p->left, q->left);
            isIdentical = isSameTree(p->right, q->right);
        }
        return isIdentical;
    }

private:
    bool isIdentical = true;
};

int main() {
    Solution s;
    TreeNode a1(1), a2(2), a3(3), b1(1), b2(2), b3(3);
    a1.left = &a2;
    a1.right = &a3;
    b1.left = &b2;
    b1.right = &b3;
    std::cout << s.isSameTree(&a1, &b1) << std::endl;

    TreeNode c1(1), c2(2), d1(1), d2(2);
    c1.left = &c2;
    d1.right = &d2;
    std::cout << s.isSameTree(&c1, &d1) << std::endl;
    return 0;
}
