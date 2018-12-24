// references:
//      https://leetcode.com/problems/validate-binary-search-tree/discuss/32109/My-simple-Java-solution-in-3-lines


#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) {
            return true;
        }

        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode *p, long minVal, long maxVal) {
        if (!p) {
            return true;
        }
        if (p->val >= maxVal || p->val <= minVal) {
            return false;
        }
        return isValidBST(p->left, minVal, p->val)
               && isValidBST(p->right, p->val, maxVal);
    }
};


int main() {
    Solution s;
    TreeNode a1(1), a2(2), a3(3);
    a2.left = &a1;
    a2.right = &a3;
    std::cout << s.isValidBST(&a2) << std::endl;

    TreeNode b1(1), b2(5), b3(4), b4(3), b5(6);
    b2.left = &b1;
    b2.right = &b3;
    b3.left = &b4;
    b3.right = &b5;
    std::cout << s.isValidBST(&b2) << std::endl;

    TreeNode c1(5), c2(10), c3(15), c4(6), c5(20);
    c2.left = &c1;
    c2.right = &c3;
    c3.left = &c4;
    c3.right = &c5;
    std::cout << s.isValidBST(&c2) << std::endl;

    return 0;
}
