// references:
//      https://leetcode.com/problems/rotate-list/discuss/206519/C%2B%2B-O(n)Time-O(1)-Space-beats-98.61

#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }

        int length = 1;
        ListNode *temp = head;
        // calculates the length of the linked list
        while (temp->next != nullptr) {
            length++;
            temp = temp->next;
        }

        // makes the linked list circular
        temp->next = head;
        // calculate the true rotation times
        int trueK = k % length;

        // finds the new head and the new end
        for (int i = trueK; i < length; i++) {
            temp = temp->next;
        }
        ListNode *newHead = temp->next;
        temp->next = nullptr;

        return newHead;
    }
};


int main() {
    Solution s;
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = nullptr;
    int k = 2000000001;

    ListNode *res = s.rotateRight(&a, k);
    for (ListNode *l = res; l != nullptr; l = l->next) {
        cout << l->val << "->";
    }
    cout << endl;

    return 0;
}

