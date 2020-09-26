#include <iostream>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    explicit RandomListNode(int x) :
            label(x),
            next(nullptr),
            random(nullptr) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newHead = nullptr;
        if (head == nullptr) {
            return newHead;
        }

        newHead = new RandomListNode(head->label);
        RandomListNode *itOldList = head->next;
        RandomListNode *itNewList = newHead;

        // set the label and next pointer
        while (itOldList) {
            auto temp = new RandomListNode(itOldList->label);
            itNewList->next = temp;
            itNewList = itNewList->next;
            itOldList = itOldList->next;
        }

        // set the random pointer
        itOldList = head;
        itNewList = newHead;
        while (itOldList) {
            if (itOldList->random == nullptr) {
                itNewList->random == nullptr;
            } else {
                // find the node pointed by the random pointer
                RandomListNode *p = head;
                RandomListNode *q = newHead;
                while (p != itOldList->random) {
                    p = p->next;
                    q = q->next;
                }
                itNewList->random = q;
            }

            itOldList = itOldList->next;
            itNewList = itNewList->next;
        }

        return newHead;
    }
};


int main() {
    Solution s;

    return 0;
}
