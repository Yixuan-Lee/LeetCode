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
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        set<ListNode *> nodes;
        ListNode *it = head;
        while (it) {
            if (nodes.find(it) != nodes.end()) {
                return it;
            } else {
                nodes.insert(it);
            }
            it = it->next;
        }
        return nullptr;
    }
};


int main() {
    Solution s;

    return 0;
}