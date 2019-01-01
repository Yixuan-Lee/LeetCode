// references:
//      https://leetcode.com/problems/sort-list/discuss/46714/Java-merge-sort-solution


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // cut the entire list to two halves
        ListNode *prevSlow = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prevSlow) {
            prevSlow->next = nullptr;
        }
        
        // sort two halves respectively
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        // merge l1 and l2;
        return merge(l1, l2);
    }

private:
    ListNode *merge(ListNode *l1, ListNode *l2) {
        auto newHeadHolder = new ListNode(0);
        auto it = newHeadHolder;
        auto itL1 = l1;
        auto itL2 = l2;

        while (itL1 != nullptr && itL2 != nullptr) {
            if (itL1->val < itL2->val) {
                it->next = itL1;
                itL1 = itL1->next;
            } else {
                it->next = itL2;
                itL2 = itL2->next;
            }
            it = it->next;
        }

        // append the rest if itL1 or itL2 does not reach its end
        if (itL1 != nullptr) {
            it->next = itL1;
        }
        if (itL2 != nullptr) {
            it->next = itL2;
        }

        return newHeadHolder->next;
    }
};


int main() {
    Solution s;
    ListNode a1(4), a2(2), a3(1), a4(3);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    ListNode *res = s.sortList(&a1);
    for (ListNode *it = res; it; it = it->next) {
        std::cout << it->val << "->";
    }
    std::cout << std::endl;
    return 0;
}
