#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        // if the size of linked list is 1, then return directly
        if (q == nullptr) {
            return head;
        }

        ListNode *t;    // pointing to q->next
        ListNode *prep; // pointing to previous p
        // swap the first two nodes
        head = q;
        t = q->next;
        prep = p;
        q->next = p;
        p->next = t;
        p = t;
        if (!t) {
            return head;
        }
        q = t->next;

        while (p != nullptr && q != nullptr) {
            t = q->next;
            q->next = p;
            p->next = t;
            prep->next = q;
            prep = p;
            p = t;
            if (t == nullptr) {
                break;
            }
            q = t->next;
        }
        return head;
    }
};

int main() {
    Solution s;
    ListNode a(1), b(2), c(3), d(4), e(5), f(6), g(7);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;

    ListNode x(1), y(2);
    x.next = &y;

    ListNode *res = s.swapPairs(&x);
    for (ListNode *p = res; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    return 0;
}
