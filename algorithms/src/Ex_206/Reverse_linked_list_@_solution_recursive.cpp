// references:
//      https://leetcode.com/articles/reverse-linked-list/


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};


int main() {
    Solution s;
    ListNode a1(1), a2(2), a3(3), a4(4), a5(5);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    ListNode *res = s.reverseList(&a1);
    for (ListNode *it = res; it; it = it->next) {
        std::cout << it->val << "->";
    }
    std::cout << std::endl;

    return 0;
}
