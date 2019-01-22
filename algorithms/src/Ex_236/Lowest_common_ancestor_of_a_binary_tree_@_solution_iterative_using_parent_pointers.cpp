// references:
//      https://leetcode.com/articles/lowest-common-ancestor-of-a-binary-tree/


#include <iostream>
#include <map>
#include <set>
#include <stack>

using std::map;
using std::set;
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * return the lowest common ancestor of node p and node q
     * p and q are different and both values will exist in the binary tree
     * all of the nodes' values will be unique
     *
     * @param root root
     * @param p node p
     * @param q node q
     * @return the lowest common ancestor of node p and node q
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return nullptr;
        }

        stack<TreeNode *> traversal;
        map<TreeNode *, TreeNode *> parent;
        parent[root] = nullptr;
        traversal.push(root);

        // iterate until we find both p and q
        while (!(parent.find(p) != parent.end())
               || !(parent.find(q) != parent.end())) {
            TreeNode *n = traversal.top();
            traversal.pop();

            if (n->left != nullptr) {
                parent[n->left] = n;
                traversal.push(n->left);
            }
            if (n->right != nullptr) {
                parent[n->right] = n;
                traversal.push(n->right);
            }

        }

        set<TreeNode *> ancestors4P;
        while (p != nullptr) {
            ancestors4P.insert(p);
            p = parent[p];
        }

        // move q to q's parent new_q until new_q exists in ancestors4P
        while (!(ancestors4P.find(q) != ancestors4P.end())) {
            q = parent[q];
        }

        return q;
    }
};


int main() {
    Solution s;
    TreeNode a1(3), a2(5), a3(1), a4(6), a5(2), a6(0), a7(8), a8(7), a9(4);
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a2.right = &a5;
    a3.left = &a6;
    a3.right = &a7;
    a5.left = &a8;
    a5.right = &a9;

    std::cout << s.lowestCommonAncestor(&a1, &a2, &a3)->val
              << std::endl;   // 3

    std::cout << s.lowestCommonAncestor(&a1, &a2, &a9)->val
              << std::endl;    // 5

    std::cout << s.lowestCommonAncestor(&a1, &a4, &a6)->val
              << std::endl;    // 3

    return 0;
}
