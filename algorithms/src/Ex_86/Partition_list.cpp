#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) {
            return head;
        }

        ListNode *newHead = nullptr;
        ListNode *last = nullptr;

        // puts the smaller nodes
        for (ListNode *it = head; it != nullptr; it = it->next) {
            if (it->val < x) {
                auto temp = new ListNode(it->val);
                if (!newHead) {
                    newHead = temp;
                    last = newHead;
                } else {
                    last->next = temp;
                    last = last->next;
                }
            }
        }

        // puts the bigger nodes
        for (ListNode *it = head; it != nullptr; it = it->next) {
            if (it->val >= x) {
                auto temp = new ListNode(it->val);
                if (!newHead) {
                    newHead = temp;
                    last = newHead;
                } else {
                    last->next = temp;
                    last = last->next;
                }
            }
        }

        return newHead;
    }
};


int main() {
    Solution s;
    ListNode a(1), b(4), c(3), d(2), e(5), f(2);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    ListNode *res = s.partition(&a, 4);

    for (ListNode *n = res; n != nullptr; n = n->next) {
        std::cout << n->val << "->";
    }
    std::cout << std::endl;

    return 0;
}