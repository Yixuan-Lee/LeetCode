#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *pioneer = head->next;
        auto *prevHead = new ListNode(0);
        prevHead->next = head;
        head->next = nullptr;
        while (pioneer) {
            auto *it = prevHead;
            while (it->next != nullptr && it->next->val <= pioneer->val) {
                it = it->next;
            }

            if (it->next == pioneer) {
                pioneer = pioneer->next;
            } else {
                ListNode *temp = pioneer;
                pioneer = pioneer->next;
                temp->next = it->next;
                it->next = temp;
            }
        }

        return prevHead->next;
    }
};


int main() {
    Solution s;
    ListNode a1(4), a2(2), a3(1), a4(3);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    ListNode *res = s.insertionSortList(&a1);
    for (ListNode *it = res; it; it = it->next) {
        std::cout << it->val << "->";
    }
    std::cout << std::endl;

    ListNode b1(-1), b2(5), b3(3), b4(4), b5(0);
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &b4;
    b4.next = &b5;
    res = s.insertionSortList(&b1);
    for (ListNode *it = res; it; it = it->next) {
        std::cout << it->val << "->";
    }
    std::cout << std::endl;

    ListNode c1(1), c2(-1);
    c1.next = &c2;
    res = s.insertionSortList(&c1);
    for (ListNode *it = res; it; it = it->next) {
        std::cout << it->val << "->";
    }
    std::cout << std::endl;

    return 0;
}
