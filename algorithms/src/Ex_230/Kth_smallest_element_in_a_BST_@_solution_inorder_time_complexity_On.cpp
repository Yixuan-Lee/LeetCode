#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        if (root == nullptr) {
            return 0;
        }

        inOrderTraversal(root);
        // for debugging
//        std::cout << values;
        return values[k - 1];
    }

private:
    vector<int> values;

    void inOrderTraversal(TreeNode *p) {
        if (p == nullptr) {
            return;
        }

        inOrderTraversal(p->left);
        values.push_back(p->val);
        inOrderTraversal(p->right);
    }
};


int main() {
    Solution s;

    TreeNode a1(3), a2(1), a3(4), a4(2);
    a1.left = &a2;
    a1.right = &a3;
    a2.right = &a4;
    std::cout << s.kthSmallest(&a1, 1) << std::endl;    // 1

    TreeNode b1(5), b2(3), b3(6), b4(2), b5(4), b6(1);
    b1.left = &b2;
    b1.right = &b3;
    b2.left = &b4;
    b2.right = &b5;
    b4.left = &b6;
    std::cout << s.kthSmallest(&b1, 3) << std::endl;    // 3
    return 0;
}
