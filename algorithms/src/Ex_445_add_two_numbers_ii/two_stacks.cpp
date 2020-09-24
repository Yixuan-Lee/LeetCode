
#include <stack>

using std::cout;
using std::endl;
using std::stack;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2) {
        stack<int> s1;
        stack<int> s2;

        // push all digits in l1 and l2 to s1 and s2 respectively
        const ListNode *it1 = l1;
        while (it1 != nullptr) {
            s1.push(it1->val);
            it1 = it1->next;
        }
        const ListNode *it2 = l2;
        while (it2 != nullptr) {
            s2.push(it2->val);
            it2 = it2->next;
        }

        int sum = 0;
        ListNode *list = new ListNode(-1);
        ListNode *head = nullptr;
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            list->val = sum % 10;
            head = new ListNode(sum / 10, list);
            list = head;
            sum /= 10;
        }

        return list;
    }
};


int main() {
    Solution solu;
    ListNode *l1 = new ListNode(7, new ListNode(2, new ListNode(4, new ListNode(3))));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode *res = solu.addTwoNumbers(l1, l2);
    // display res
//    for (ListNode *it = res; it != nullptr; it = it->next) {
//        cout << it->val << " -> ";
//    }
    // delete l1, l2, res
    for (ListNode *it = l1; it != nullptr; ) {
        ListNode *temp = it;
        it = it->next;
        temp->next = nullptr;
        delete temp;
    }
    for (ListNode *it = l2; it != nullptr; ) {
        ListNode *temp = it;
        it = it->next;
        temp->next = nullptr;
        delete temp;
    }
    for (ListNode *it = res; it != nullptr; ) {
        ListNode *temp = it;
        it = it->next;
        temp->next = nullptr;
        delete temp;
    }

    return 0;
}

