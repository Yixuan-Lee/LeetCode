// references:
//      https://leetcode.com/articles/construct-binary-tree-from-preorder-and-inorder-tr/
//      https://en.cppreference.com/w/cpp/utility/pair/pair


#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::pair;
using std::map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        pair<TreeNode *, vector<int>> res = build(preorder, inorder);
        return res.first;
    }

private:
    pair<TreeNode *, vector<int>> build(vector<int> &preorder,
            vector<int> &inorder) {
        if (inorder.empty()) {
            return pair<TreeNode *, vector<int>>(nullptr, preorder);
        }

        auto sizePreorder = static_cast<int> (preorder.size());
        auto sizeInorder = static_cast<int> (inorder.size());

        // root of the (whole/sub)tree
        int rootVal = preorder[0];
        auto *root = new TreeNode(rootVal);

        // find root's index in inorder sequence
        int rootIdx = -1;
        for (rootIdx = 0;
             rootIdx < sizeInorder && inorder[rootIdx] != rootVal; rootIdx++);
        preorder = vector<int>(preorder.begin() + 1, preorder.end());

        // root splits the in-order sequence
        vector<int> leftSubtree(inorder.begin(), inorder.begin() + rootIdx);
        vector<int> rightSubtree(
                inorder.begin() + std::min(rootIdx + 1, sizeInorder),
                inorder.end());

        pair<TreeNode *, vector<int>> p = build(preorder, leftSubtree);
        root->left = p.first;
        preorder = p.second;
        p = build(preorder, rightSubtree);
        root->right = p.first;
        preorder = p.second;

        return pair<TreeNode *, vector<int>>(root, preorder);
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

int height(TreeNode *p) {
    if (!p) {
        return 0;
    }
    int heightL = height(p->left);
    int heightR = height(p->right);
    return heightL > heightR ? heightL + 1 : heightR + 1;
}

void getGivenLevelOrder(TreeNode *p, int level,
        vector<int> &nodes) {
    if (!p) {
        return;
    }
    if (level == 1) {
        nodes.push_back(p->val);
    } else if (level > 1) {
        getGivenLevelOrder(p->left, level - 1, nodes);
        getGivenLevelOrder(p->right, level - 1, nodes);
    }
}

void printLevelOrder(TreeNode *root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        vector<int> givenLevel;
        getGivenLevelOrder(root, i, givenLevel);
        std::cout << givenLevel << std::endl;
    }
}

int main() {
    Solution s;
    vector<int> preorder {3, 9, 20, 15, 7};
    vector<int> inorder {9, 3, 15, 20, 7};
    TreeNode *root = s.buildTree(preorder, inorder);
    printLevelOrder(root);
    return 0;
}
