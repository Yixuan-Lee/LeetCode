#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return root->val;
        }
        int sum = 0;
        int per = root->val;
        calculateSum(root->left, per, sum);
        calculateSum(root->right, per, sum);
        return sum;
    }

private:
    void calculateSum(TreeNode *p, int per, int &sum) {
        if (!p) {
            return;
        }
        per = per * 10 + p->val;
        if (!p->left && !p->right) {
            sum += per;
            return;
        }
        calculateSum(p->left, per, sum);
        calculateSum(p->right, per, sum);
    }
};


int main() {
    Solution s;
    TreeNode a1(1), a2(2), a3(3);
    a1.left = &a2;
    a1.right = &a3;
    std::cout << s.sumNumbers(&a1) << std::endl;

    TreeNode b1(4), b2(9), b3(0), b4(5), b5(1);
    b1.left = &b2;
    b1.right = &b3;
    b2.left = &b4;
    b2.right = &b5;
    std::cout << s.sumNumbers(&b1) << std::endl;

    TreeNode c1(9);
    std::cout << s.sumNumbers(&c1) << std::endl;

    TreeNode d1(9), d2(2);
    d1.left = &d2;
    std::cout << s.sumNumbers(&d1) << std::endl;

    std::cout << s.sumNumbers(nullptr) << std::endl;
    
    return 0;
}
