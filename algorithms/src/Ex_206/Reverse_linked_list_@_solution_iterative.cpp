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
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        map<int, ListNode *> hash;
        int count = 0;
        for (ListNode *it = head; it; it = it->next) {
            if (count > 0) {
                // don't move if it is the first loop
                head = head->next;
            }
            hash[count++] = it;
        }

        int i;
        for (i = count - 1; i >= 1; i--) {
            hash[i]->next = hash[i - 1];
        }
        hash[i]->next = nullptr;

        return head;
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
