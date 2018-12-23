// references:
//      https://www.geeksforgeeks.org/level-order-tree-traversal/
//      https://leetcode.com/articles/unique-binary-search-trees-ii/


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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> ans;
        if (n == 0) {
            return ans;
        }
        if (n == 1) {
            ans.push_back(new TreeNode(1));
            return ans;
        }

        return generateTrees(1, n);
    }

private:
    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode *> ans;
        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }

        for (int i = start; i <= end; i++) {
            // all possible left subtrees if i is served as the root
            vector<TreeNode *> leftTrees = generateTrees(start, i - 1);
            // all possible right subtrees if i is served as the rot
            vector<TreeNode *> rightTrees = generateTrees(i + 1, end);

            // combine all possible the left subtrees and right subtrees
            // with the root i
            for (TreeNode *l : leftTrees) {
                for (TreeNode *r : rightTrees) {
                    auto *curr = new TreeNode(i);   // root
                    curr->left = l;
                    curr->right = r;
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
};

/**
 * return the height of the tree
 *
 * @param root root pointer
 * @return height of the tree
 */
int height(const TreeNode *root) {
    if (root == nullptr) {
        return 0;
    } else {
        // calculate the height of its left subtree and right subtree
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
}

/**
 * print the nodes at the given level
 *
 * @param root
 * @param level
 */
void printGivenLevel(const TreeNode *root, const int level) {
    if (root == nullptr) {
        return;
    }
    if (level == 1) {
        std::cout << root->val << ",";
    } else if (level > 1) {
        // print the nodes of left subtree at the next level
        printGivenLevel(root->left, level - 1);
        // print the nodes of right subtree at the next level
        printGivenLevel(root->right, level - 1);
    }
}

/**
 * print level order traversal
 *
 * @param root pointers to the root
 */
void printLevelOrder(const TreeNode *root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
    }
}

int main() {
    Solution s;

    vector<TreeNode *> res = s.generateTrees(3);
    std::cout << "[" << std::endl;
    while (!res.empty()) {
        TreeNode *root = res.back();
        std::cout << "\t" << "[";
        printLevelOrder(root);
        std::cout << "]" << std::endl;
        res.pop_back();
    }

    return 0;
}
