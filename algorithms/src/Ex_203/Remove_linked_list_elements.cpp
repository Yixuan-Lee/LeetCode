#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr) {
            return head;
        }

        // make sure the value of the first node is not val
        while (head && head->val == val) {
            head = head->next;
        }
        if (head == nullptr) {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = slow->next;
        while (fast) {
            while (fast && fast->val == val) {
                fast = fast->next;
            }
            slow->next = fast;
            slow = fast;
            if (slow != nullptr) {
                fast = slow->next;
            }
        }

        return head;
    }
};


int main() {
    Solution s;
    ListNode a1(1), a2(2), a3(6), a4(3), a5(4), a6(5), a7(6);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = &a6;
    a6.next = &a7;
    ListNode *res = s.removeElements(&a1, 6);
    for (ListNode *it = res; it; it = it->next) {
        std::cout << it->val << "->";
    }
    std::cout << std::endl;

    ListNode b1(1), b2(2), b3(2), b4(1);
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &b4;
    res = s.removeElements(&b1, 2);
    for (ListNode *it = res; it; it = it->next) {
        std::cout << it->val << "->";
    }
    std::cout << std::endl;

    return 0;
}
