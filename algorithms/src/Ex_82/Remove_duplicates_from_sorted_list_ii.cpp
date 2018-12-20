// references:
//      https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/discuss/206322/C%2B%2B-beats-100

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        long value2Delete = LONG_MIN;
        // move the head to the first distinct number
        while (head && head->next && head->val == head->next->val) {
            value2Delete = head->val;
            while (head && head->val == value2Delete) {
                head = head->next;
            }
        }

        // all nodes have 1 same value or only 1 node has distinct value
        if (!head || !head->next) {
            return head;
        }

        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                value2Delete = curr->val;
            }
            if (curr->val == value2Delete) {
                ListNode *follow = curr->next;
                if (prev) {
                    prev->next = follow;
                }
                curr->next = nullptr;
                curr = follow;
                continue;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};


int main() {
    Solution s;
    ListNode a(3), b(3), c(3), d(3), e(4), f(5), g(5), h(6), i(6), j(6),
            k(7), l(7);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &h;
    h.next = &i;
    i.next = &j;
    j.next = &k;
    k.next = &l;
    ListNode *res = s.deleteDuplicates(&a);

    for (ListNode *n = res; n != nullptr; n = n->next) {
        std::cout << n->val << "->";
    }
    std::cout << std::endl;

    return 0;
}