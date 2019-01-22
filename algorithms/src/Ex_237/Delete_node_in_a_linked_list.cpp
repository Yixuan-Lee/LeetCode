// references:
//      https://leetcode.com/articles/delete-node-linked-list/


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * delete the node in the linked list, and do not return anything
     *
     * the linked list will have at least two elements
     * all of the nodes' values will be unique
     * the given node will not be the tail and it will always be a valid node of the linked list
     *
     * @param node the node to be deleted
     */
    void deleteNode(ListNode *node) {
        ListNode *del = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete del;     // free the resource
    }
};


int main() {
    Solution s;

    return 0;
}
