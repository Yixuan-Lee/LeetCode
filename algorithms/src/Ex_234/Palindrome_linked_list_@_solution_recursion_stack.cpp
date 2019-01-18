// references:
//      https://leetcode.com/problems/palindrome-linked-list/discuss/64490/My-easy-understand-C%2B%2B-solution


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        temp = head;
        return check(head);
    }

private:
    ListNode *temp;

    bool check(ListNode *p) {
        if (p == nullptr) {
            return true;
        }

        bool isPal = check(p->next) && (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};


int main() {
    Solution s;

    ListNode a1(1), a2(2);
    a1.next = &a2;
    std::cout << s.isPalindrome(&a1) << std::endl;      // 0

    ListNode b1(1), b2(2), b3(2), b4(1);
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &b4;
    std::cout << s.isPalindrome(&b1) << std::endl;      // 1

    return 0;
}
