#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        // pointing to the result list's head
        ListNode *n = new ListNode(-1);
        // iterate in the result list
        ListNode *temp = n;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ListNode *ln = new ListNode(l1->val);
                temp->next = ln;
                temp = ln;
                l1 = l1->next;
            } else {
                ListNode *ln = new ListNode(l2->val);
                temp->next = ln;
                temp = ln;
                l2 = l2->next;
            }
        }
        while (l1) {
            ListNode *ln = new ListNode(l1->val);
            temp->next = ln;
            temp = ln;
            l1 = l1->next;
        }
        while (l2) {
            ListNode *ln = new ListNode(l2->val);
            temp->next = ln;
            temp = ln;
            l2 = l2->next;
        }
        return n->next;
    }
};

int main() {

    return 0;
}