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
        if (k == 0) {
            return head;
        }
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            // size of linked list is 1
            return head;
        }
        if (head->next->next == nullptr) {
            // size of linked list is 2
            if (k % 2 == 0) {
                return head;
            } else {
                // swaps the two nodes and returns
                ListNode *newHead = head;
                head->next->next = head;
                newHead = head->next;
                head->next = nullptr;
                return newHead;
            }
        }


        ListNode *first = head;
        ListNode *secondLast;
        ListNode *last;
        for (int countDown = 0; countDown < k; countDown++) {
            // set last and secondLast
            last = first;
            while (last->next != nullptr) {
                if (last->next->next == nullptr) {
                    secondLast = last;
                }
                last = last->next;
            }
            // rotate once
            rotateOnce(&first, &last, &secondLast);
        }
        return first;
    }

private:
    void rotateOnce(ListNode **head, ListNode **end, ListNode **secondEnd) {
        (*secondEnd)->next = (*end)->next;
        (*end)->next = *head;
        *head = *end;
    }
};


int main() {
    Solution s;
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b;
    b.next = &e;
//    c.next = &d;
//    d.next = &e;
    e.next = nullptr;

    int k = 2000000000;

    ListNode *res = s.rotateRight(&a, k);
    for (ListNode *l = res; l != nullptr; l = l->next) {
        cout << l->val << "->";
    }
    cout << endl;
    return 0;
}
