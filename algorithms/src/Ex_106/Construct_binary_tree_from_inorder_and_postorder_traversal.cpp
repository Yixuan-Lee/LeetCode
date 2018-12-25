#include <iostream>
#include <vector>
#include <map>
#include <search.h>

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }

        for (int i = 0; i < inorder.size(); i++) {
            index.insert(std::make_pair(inorder[i], i));
        }
        return build(
                postorder, inorder,
                0, static_cast<int> (postorder.size() - 1),
                0, static_cast<int> (inorder.size() - 1));
    }

private:
    // store the indexes of the elements in the inorder array
    map<int, int> index;

    TreeNode *build(vector<int> &postorder, vector<int> &inorder,
            int postorderStartIdx, int postorderEndIdx,
            int inorderStartIdx, int inorderEndIdx) {
        if (inorderStartIdx > inorderEndIdx
            || postorderStartIdx > postorderEndIdx) {
            return nullptr;
        }
        if (inorderStartIdx == inorderEndIdx) {
            return new TreeNode(inorder[inorderStartIdx]);
        }

        int rootVal = postorder[postorderEndIdx];
        int inorderIdx = index[rootVal];

        auto root = new TreeNode(rootVal);
        // get the number of nodes at the right subtree
        int rightCount = inorderEndIdx - inorderIdx;
        // get the number of nodes at the left subtree
        int leftCount = inorderIdx - inorderStartIdx;

        root->right = build(
                postorder, inorder,
                postorderStartIdx + leftCount, postorderEndIdx - 1,
                inorderIdx + 1, inorderEndIdx);
        root->left = build(
                postorder, inorder,
                postorderStartIdx, postorderEndIdx - rightCount - 1,
                inorderStartIdx, inorderIdx - 1);

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
//    vector<int> postorder {9, 15, 7, 20, 3};
//    vector<int> inorder {9, 3, 15, 20, 7};

    vector<int> inorder {1, 2, 3, 4};
    vector<int> postorder {2, 1, 4, 3};
    TreeNode *root = s.buildTree(inorder, postorder);
    printLevelOrder(root);
    return 0;
}
