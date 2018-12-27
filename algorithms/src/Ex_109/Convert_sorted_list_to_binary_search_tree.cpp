// references:
//      https://leetcode.com/articles/convert-sorted-list-to-binary-search-tree/


#include <iostream>
#include <vector>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        return buildBST(head);
    }

private:
    TreeNode *buildBST(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        ListNode *mid = findMiddleNode(head);
        auto *root = new TreeNode(mid->val);
        if (head == mid) {
            return root;
        }

        root->left = buildBST(head);        // nodes of left subtree
        root->right = buildBST(mid->next);  // nodes of right subtree
        return root;
    }

    ListNode *findMiddleNode(ListNode *head) {
        ListNode *prevPtr = nullptr;
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;

        while (fastPtr && fastPtr->next) {
            prevPtr = slowPtr;      // follows the slowPtr
            slowPtr = slowPtr->next;        // moves one
            fastPtr = fastPtr->next->next;  // moves two
        }

        if (prevPtr != nullptr) {
            prevPtr->next = nullptr;    // splits the linked list
        }

        // slowPtr reaches the middle element when fastPtr reaches the end of the linked list
        return slowPtr;
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
    ListNode a(1), b(2), c(3), d(4), e(5), f(6), g(7), h(8);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &h;
    TreeNode *root = s.sortedListToBST(&a);
    printLevelOrder(root);
    return 0;
}
