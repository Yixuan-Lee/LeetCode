// references:
//      https://leetcode.com/submissions/detail/197847919/ (sample 28ms submission)


#include <iostream>
#include <unordered_map>

using std::unordered_map;

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
        if (head == nullptr) {
            return nullptr;
        }

        RandomListNode newHeadHolder(0);
        RandomListNode *itNewList = &newHeadHolder;
        RandomListNode *itOldList = head;
        unordered_map<RandomListNode *, RandomListNode *> hash;

        while (itOldList) {
            // create the corresponding new node
            auto node = new RandomListNode(itOldList->label);
            itNewList->next = node;

            node->random = itOldList->random;
            // store the mapping between old node and the corresponding new node
            hash[itOldList] = node;

            itNewList = itNewList->next;
            itOldList = itOldList->next;
        }

        // until now, the random pointers are tweaking, meaning that
        // random pointers of new nodes are pointing to the old nodes
        // so we need to update the random pointer by means of the hash table
        itOldList = newHeadHolder.next;
        while (itOldList) {
            if (itOldList->random != nullptr) {
                itOldList->random = hash[itOldList->random];
            }
            itOldList = itOldList->next;
        }

        return newHeadHolder.next;
    }

};


int main() {
    Solution s;
    RandomListNode a1(1), a2(2), a3(3);
    a1.next = &a2;
    a1.random = &a3;
    a2.next = &a3;
    a2.random = nullptr;
    a3.next = nullptr;
    a3.random = &a2;
    RandomListNode *newHead = s.copyRandomList(&a1);
    return 0;
}
