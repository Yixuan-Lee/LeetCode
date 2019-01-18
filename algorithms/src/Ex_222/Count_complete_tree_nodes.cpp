#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int nodes = 1;
        TreeNode *it = root;

        while (it) {
            int heightLeft = height(it->left);
            int heightRight = height(it->right);
            if (heightLeft == 0 && heightRight == 0) {
                break;
            }
            if (heightLeft > heightRight) {
                it = it->left;
                nodes *= 2;
            } else {
                it = it->right;
                nodes = nodes * 2 + 1;
            }
        }

        return nodes;
    }

private:
    int height(TreeNode *p) {
        if (p == nullptr) {
            return 0;
        }

        int heightL = height(p->left);
        int heightR = height(p->right);

        return heightL > heightR ? heightL + 1 : heightR + 1;
    }
};


int main() {
    Solution s;

    TreeNode a1(1), a2(2), a3(3), a4(4), a5(5), a6(6);
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a2.right = &a5;
    a3.left = &a6;
    std::cout << s.countNodes(&a1) << std::endl;        // 6

    TreeNode b1(1), b2(2), b3(3), b4(4), b5(5), b6(6), b7(7);
    b1.left = &b2;
    b1.right = &b3;
    b2.left = &b4;
    b2.right = &b5;
    b3.left = &b6;
    b3.right = &b7;
    std::cout << s.countNodes(&b1) << std::endl;        // 7

    return 0;
}
