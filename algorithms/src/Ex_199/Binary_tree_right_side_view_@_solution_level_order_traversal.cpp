// references:
//      Ex_102: Binary_tree_level_order_traversal.cpp


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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }

        int h = height(root);
        for (int i = 1; i <= h; i++) {
            vector<int> per;
            pushMostRightNodeAtGivenLevel(root, i, per);
            ans.push_back(per[0]);
        }

        return ans;
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

    void pushMostRightNodeAtGivenLevel(TreeNode *p, int level,
            vector<int> &per) {
        if (p == nullptr) {
            return;
        }
        if (level == 1) {
            per.push_back(p->val);
        } else if (level > 1) {
            pushMostRightNodeAtGivenLevel(p->right, level - 1, per);
            pushMostRightNodeAtGivenLevel(p->left, level - 1, per);
        }
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
    TreeNode a1(1), a2(2), a3(3), a4(5), a5(4);
    a1.left = &a2;
    a1.right = &a3;
    a2.right = &a4;
    a3.right = &a5;
    vector<int> res = s.rightSideView(&a1);
    std::cout << res << std::endl;      // [1, 3, 4]

    TreeNode b1(1), b2(2), b3(3), b4(4), b5(5), b6(6), b7(7), b8(8), b9(9);
    b1.left = &b2;
    b1.right = &b3;
    b2.left = &b4;
    b2.right = &b5;
    b3.left = &b9;
    b4.right = &b7;
    b5.right = &b6;
    b7.left = &b8;
    res = s.rightSideView(&b1);
    std::cout << res << std::endl;      // [1, 3, 9, 6, 8]

    return 0;
}
