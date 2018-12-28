#include <iostream>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    explicit TreeLinkNode(int x) : val(x),
                                   left(nullptr),
                                   right(nullptr),
                                   next(nullptr) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }

        root->next = nullptr;
        if (!root->left && !root->right) {
            return;
        }

        connectLeftSubtree(root, root->left);
        connectRightSubtree(root, root->right);
    }

private:
    void connectLeftSubtree(TreeLinkNode *parent, TreeLinkNode *child) {
        child->next = parent->right;
        if (child->left && child->right) {
            connectLeftSubtree(child, child->left);
            connectRightSubtree(child, child->right);
        }
    }

    void connectRightSubtree(TreeLinkNode *parent, TreeLinkNode *child) {
        if (parent->next) {
            child->next = parent->next->left;
        } else {
            child->next = nullptr;
        }
        if (child->left && child->right) {
            connectLeftSubtree(child, child->left);
            connectRightSubtree(child, child->right);
        }
    }
};


int main() {
    Solution s;

    return 0;
}
