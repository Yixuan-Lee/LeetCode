// references:
//      https://leetcode.com/articles/intersection-of-two-linked-lists/


#include <iostream>
#include <map>

using std::map;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode *pa = headA;
        ListNode *pb = headB;

        while (pa != pb) {
            pa == nullptr ? pa = headB : pa = pa->next;
            pb == nullptr ? pb = headA : pb = pb->next;
        }
        return pa;
    }
};


int main() {
    Solution s;
    ListNode a1(4), a2(1);
    ListNode b1(5), b2(0), b3(1);
    ListNode co1(8), co2(4), co3(5);
    co1.next = &co2;
    co2.next = &co3;
    a1.next = &a2;
    a2.next = &co1;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &co1;
    ListNode *res = s.getIntersectionNode(&a1, &b1);
    std::cout << "Reference of the node with value = " << res->val
              << std::endl;
    return 0;
}
