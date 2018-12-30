// reference:
//      https://gist.github.com/edwardtsau/5625679
//      http://www.cplusplus.com/forum/beginner/96862/


#include <iostream>
#include <list>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l3 = nullptr;
        ListNode **pnext = &l3;     // pnext is a pointer pointing to result ListNode pointer l3 (*pnext = l3)

        int carry = 0;
        int result = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int value1 = (l1 != nullptr) ? l1->val : 0;
            int value2 = (l2 != nullptr) ? l2->val : 0;
            int sum = value1 + value2 + carry;
            result = sum % 10;
            carry = sum / 10;

            ListNode *&new_node = *pnext;   // new_node is a reference to the pointer (*pnext)
            new_node = new ListNode(result);
            pnext = &(new_node->next);  // pnext is a pointer pointing to the address of (new_node->next)

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        if (carry != 0) {
            // if the highest bits' sum is more than 10, need to create an extra node for the new highest bit
            *pnext = new ListNode(carry);
        }
        return l3;
    }
};

int main() {
    ListNode *l1;
    ListNode *l2;
    /* example 1 */
//    ListNode a(2), b(4), c(3);
//    a.next = &b;
//    b.next = &c;
//    c.next = nullptr;
//
//    ListNode x(5), y(6), z(4);
//    x.next = &y;
//    y.next = &z;
//    z.next = nullptr;

    /* example 2 */
//    ListNode a(5);
//    ListNode x(5);

    /* example 3 */
//    ListNode a(0);
//    ListNode x(7);
//    ListNode y(3);
//    a.next = nullptr;
//    x.next = &y;
//    y.next = nullptr;

    /* example 4 */
//    ListNode a(9);
//    ListNode x(9);
//    ListNode y(9);
//    a.next = nullptr;
//    x.next = &y;
//    y.next = nullptr;

    /* example 5 */
//    ListNode a(0);
//    ListNode x(2);
//    ListNode y(7);
//    ListNode z(8);
//    a.next = nullptr;
//    x.next = &y;
//    y.next = &z;
//    z.next = nullptr;

    /* example 6 */
    ListNode x(1);

    ListNode a(9);
    ListNode b(9);
    ListNode c(9);
    ListNode d(9);
    ListNode e(9);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = nullptr;
    x.next = nullptr;

    l1 = &a;
    l2 = &x;
    Solution s;
    ListNode *result = s.addTwoNumbers(l1, l2);
    for (ListNode *l = result; l != nullptr; l = l->next) {
        if (l->next == nullptr)
            std::cout << l->val;
        else
            std::cout << l->val << "->";
    }
    std::cout << std::endl;
    return 0;
}
