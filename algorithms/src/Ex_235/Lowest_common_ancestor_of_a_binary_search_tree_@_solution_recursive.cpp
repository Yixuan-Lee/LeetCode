#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode *it = root;
        // make sure that p->val < q->val
        if (q->val < p->val) {
            TreeNode *temp = q;
            q = p;
            p = temp;
        }

        TreeNode *ans = root;
        while (it) {
            if (it->val >= p->val && it->val <= q->val) {
                if (it->val < ans->val) {
                    ans = it;
                }
                break;
            } else if (it->val > p->val && it->val > q->val) {
                ans = lowestCommonAncestor(it->left, p, q);
                it = it->left;
            } else if (it->val < p->val && it->val < q->val) {
                ans = lowestCommonAncestor(it->right, p, q);
                it = it->right;
            }
        }

        return ans;
    }
};


int main() {
    Solution s;

    TreeNode a1(6), a2(2), a3(8), a4(0), a5(4), a6(7), a7(9), a8(3), a9(5);
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a2.right = &a5;
    a3.left = &a6;
    a3.right = &a7;
    a5.left = &a8;
    a5.right = &a9;

    std::cout << s.lowestCommonAncestor(&a1, &a2, &a3)->val << std::endl; // 6

    std::cout << s.lowestCommonAncestor(&a1, &a2, &a5)->val << std::endl; // 2

    std::cout << s.lowestCommonAncestor(&a1, &a5, &a9)->val << std::endl; // 4

    std::cout << s.lowestCommonAncestor(&a1, &a8, &a9)->val << std::endl; // 4

    std::cout << s.lowestCommonAncestor(&a1, &a4, &a9)->val << std::endl; // 2

    std::cout << s.lowestCommonAncestor(&a1, &a7, &a9)->val << std::endl; // 6

    return 0;
}
