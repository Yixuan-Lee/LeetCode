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

        connectRightSubtree(root, root->right);
        connectLeftSubtree(root, root->left);

    }

private:
    void connectLeftSubtree(TreeLinkNode *parent, TreeLinkNode *child) {
        if (child == nullptr) {
            return;
        }
        if (parent->right) {
            child->next = parent->right;
        } else if (parent->next) {
            TreeLinkNode *pnext = parent->next;
            while (pnext) {
                if (pnext->left) {
                    child->next = pnext->left;
                    break;
                } else if (pnext->right) {
                    child->next = pnext->right;
                    break;
                }
                pnext = pnext->next;
            }
            if (pnext == nullptr) {
                // all parent's next right nodes have no kids
                child->next = nullptr;
            }
        } else {
            // parent has no next right node
            child->next = nullptr;
        }

        connectRightSubtree(child, child->right);
        connectLeftSubtree(child, child->left);
    }

    void connectRightSubtree(TreeLinkNode *parent, TreeLinkNode *child) {
        if (child == nullptr) {
            return;
        }

        if (parent->next) {
            TreeLinkNode *pnext = parent->next;
            while (pnext) {
                if (pnext->left) {
                    child->next = pnext->left;
                    break;
                } else if (pnext->right) {
                    child->next = pnext->right;
                    break;
                }
                pnext = pnext->next;
            }
            if (pnext == nullptr) {
                // all parent's next right nodes have no kids
                child->next = nullptr;
            }
        } else {
            // parent has no next right node
            child->next = nullptr;
        }

        connectRightSubtree(child, child->right);
        connectLeftSubtree(child, child->left);
    }
};


int main() {
    Solution s;

    return 0;
}
