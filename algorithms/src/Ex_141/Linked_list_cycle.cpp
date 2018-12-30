#include <iostream>
#include <set>

using std::set;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        set<ListNode *> nodes;
        ListNode *it = head;
        nodes.insert(it);
        it = it->next;

        while (it) {
            if (nodes.count(it) == 0) {
                nodes.insert(it);
            } else {
                return true;
            }
            it = it->next;
        }
        return false;
    }
};


int main() {
    Solution s;
    ListNode a1(3), a2(2), a3(0), a4(-4);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a2;
    std::cout << s.hasCycle(&a1) << std::endl;      // true

    ListNode b1(1), b2(2);
    b1.next = &b2;
    b2.next = &b1;
    std::cout << s.hasCycle(&b1) << std::endl;      // true

    ListNode c1(1);
    c1.next = &c1;
    std::cout << s.hasCycle(&c1) << std::endl;      // true

    ListNode d1(1), d2(2);
    d1.next = &d2;
    std::cout << s.hasCycle(&d1) << std::endl;      // false

    ListNode e1(1);
    std::cout << s.hasCycle(&e1) << std::endl;      // false

    std::cout << s.hasCycle(nullptr) << std::endl;  // false
    return 0;
}
