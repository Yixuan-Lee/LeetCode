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

        // use a map to store the indexes of the elements in the inorder array
        for (int i = 0; i < inorder.size(); i++) {
            index.insert(std::make_pair(inorder[i], i));
        }
        return build(
                preorder, inorder, 0, 0,
                static_cast<int> (inorder.size() - 1));
    }

private:
    // store the indexes of the elements in the inorder array
    map<int, int> index;

    TreeNode *build(vector<int> &preorder, vector<int> &inorder,
            int preorderStartIdx, int inorderStartIdx, int inorderEndIdx) {
        // avoid root does not have left/right kid(s)
        if (inorderStartIdx > inorderEndIdx) {
            return nullptr;
        }

        if (inorderStartIdx == inorderEndIdx) {
            return new TreeNode(inorder[inorderStartIdx]);
        }

        int rootVal = preorder[preorderStartIdx];
        int inorderIdx = index[rootVal];

        auto *root = new TreeNode(rootVal);
        // get the number of nodes at the left subtree
        int leftCount = inorderIdx - inorderStartIdx;
        // get the number of nodes at the right subtree
        int rightCount = inorderEndIdx - inorderIdx;

        root->left = build(
                preorder, inorder, preorderStartIdx + 1,
                inorderStartIdx, inorderIdx - 1);
        root->right = build(
                preorder, inorder,
                preorderStartIdx + leftCount + 1,
                inorderIdx + 1, inorderEndIdx);
        
        return root;
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

