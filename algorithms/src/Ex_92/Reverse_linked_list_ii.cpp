#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) {
            return head;
        }

        auto *newHead = new ListNode(LONG_MIN);
        ListNode *it = head;
        ListNode *newIt = newHead;
        int counter = 1;
        // constitutes the nodes [1,m)
        while (counter < m) {
            auto *temp = new ListNode(it->val);
            newIt->next = temp;
            it = it->next;
            newIt = newIt->next;
            counter++;
        }

        // constitutes the nodes [m,n]
        while (counter <= n) {
            auto *temp = new ListNode(it->val);
            temp->next = newIt->next;
            it = it->next;
            newIt->next = temp;
            counter++;
        }

        // moves newIt to the current end
        while (newIt->next) {
            newIt = newIt->next;
        }

        // constitute the nodes (n,end]
        while (it) {
            auto *temp = new ListNode(it->val);
            newIt->next = temp;
            it = it->next;
            newIt = newIt->next;
        }

        return newHead->next;
    }
};


int main() {
    Solution s;
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    ListNode *res = s.reverseBetween(&a, 1, 5);
    for (ListNode *it = res; it != nullptr; it = it->next) {
        std::cout << it->val << "->";
    }
    std::cout << std::endl;
    return 0;
}
