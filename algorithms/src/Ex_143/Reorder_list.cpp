#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head) {
            return;
        }
        map<int, ListNode *> nodes;
        int idx = 0;
        for (ListNode *it = head; it; it = it->next, idx++) {
            nodes.insert(std::make_pair(idx, it));
        }

        for (int i = 0, j = idx - 1; i <= j; i++, j--) {
            nodes[i]->next = nodes[j];
            if (i + 1 >= j) {
                nodes[j]->next = nullptr;
            } else if (i + 1 < j) {
                nodes[j]->next = nodes[i + 1];
            }
        }
    }
};


int main() {
    Solution s;
    ListNode a1(1), a2(2), a3(3), a4(4);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    s.reorderList(&a1);
    ListNode *it;
    it = &a1;
    while (it) {
        std::cout << it->val << "->";
        it = it->next;
    }
    std::cout << std::endl;

    ListNode b1(1), b2(2), b3(3), b4(4), b5(5);
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &b4;
    b4.next = &b5;
    s.reorderList(&b1);
    it = &b1;
    while (it) {
        std::cout << it->val << "->";
        it = it->next;
    }
    return 0;
}