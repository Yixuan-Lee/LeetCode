#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == nullptr) {
            // only 1 node
            return head;
        }

        ListNode *pioneer = head->next;
        ListNode *oldPionner = head;
        while (pioneer != nullptr) {
            if (pioneer->val == oldPionner->val) {
                // remove the node pointed by pioneer
                oldPionner->next = pioneer->next;
//                delete pioneer;   // unnecessary to delete the node
                pioneer = oldPionner->next;
            } else {
                oldPionner = pioneer;
                pioneer = pioneer->next;
            }
        }

        return head;
    }
};


int main() {
    Solution s;
    ListNode a(1), b(1), c(2), d(3), e(3);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    ListNode *res = s.deleteDuplicates(&a);

    for (ListNode *n = res; n != nullptr; n = n->next) {
        std::cout << n->val << "->";
    }
    std::cout << std::endl;
    return 0;
}
