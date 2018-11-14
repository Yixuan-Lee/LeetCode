//
// Created by  liyixuan on 2018-11-14.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return nullptr;
        int counter = 0;
        ListNode* p1 = head;  // lead pointer
        ListNode* p2 = head;  // follower pointer
        while (counter < n) {
            p1 = p1->next;
            counter++;
        }
        if (p1 == nullptr) {
            // meaning that we want to remove the first node
            head = head->next;
        } else {
            // p2 leads p1 for n nodes, meaning that between p1 and p2, there are n-1 nodes (does not count p1 and p2)
            while (p1->next) {
                p1 = p1->next;
                p2 = p2->next;
            }
            // now, p2 is pointing to the previous node of the node that we want to remove
            p2->next = p2->next->next;
        }
        return head;
    }
};

int main() {
    Solution s;
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;
    int n;
    ListNode* p = &a;
    std::cin >> n;
    ListNode* res = s.removeNthFromEnd(p, n);
    while (res != NULL) {
        std::cout << res->val << "->";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}