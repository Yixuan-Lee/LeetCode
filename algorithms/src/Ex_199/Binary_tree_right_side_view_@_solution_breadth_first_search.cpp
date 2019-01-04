// references:
//      https://leetcode.com/articles/binary-tree-right-side-view/  (great article for depth-first search and breadth-first search)


#include <iostream>
#include <vector>
#include <queue>
#include <map>

using std::vector;
using std::queue;
using std::map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        map<int, int> rightMostValueAtEachDepth;
        int maxDepth = -1;

        // store the nodes that we are going to visit
        queue<TreeNode *> nodeQueue;
        // store the depth of nodes that we are going to visit
        queue<int> depthQueue;

        // enqueue the root, since we are going to visit the root first
        nodeQueue.push(root);
        depthQueue.push(0);

        while (!nodeQueue.empty()) {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            int depth = depthQueue.front();
            depthQueue.pop();

            if (node != nullptr) {
                maxDepth = (depth > maxDepth ? depth : maxDepth);

                // we remove the containment check here
                // this will be overwritten by every node except for the first
                // node in level N, and finally, the right most node will,
                // for sure, overwrite this value, so the correct value is
                // never overwritten
                rightMostValueAtEachDepth[depth] = node->val;

                // here we have to enqueue the left node before the right,
                // so next time, we will visit the left node first
                // if we change the order, we can get list of left most nodes
                nodeQueue.push(node->left);
                nodeQueue.push(node->right);
                depthQueue.push(depth + 1);
                depthQueue.push(depth + 1);
            }
        }

        vector<int> ans;
        for (int depth = 0; depth <= maxDepth; depth++) {
            ans.push_back(rightMostValueAtEachDepth[depth]);
        }

        return ans;
    }
};


// declare a template for overloading the << operator for vector<T>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<T> &v) {
    std::cout << "[";
    for (auto &i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;
    TreeNode a1(1), a2(2), a3(3), a4(5), a5(4);
    a1.left = &a2;
    a1.right = &a3;
    a2.right = &a4;
    a3.right = &a5;
    vector<int> res = s.rightSideView(&a1);
    std::cout << res << std::endl;      // [1, 3, 4]

    TreeNode b1(1), b2(2), b3(3), b4(4), b5(5), b6(6), b7(7), b8(8), b9(9);
    b1.left = &b2;
    b1.right = &b3;
    b2.left = &b4;
    b2.right = &b5;
    b3.left = &b9;
    b4.right = &b7;
    b5.right = &b6;
    b7.left = &b8;
    res = s.rightSideView(&b1);
    std::cout << res << std::endl;      // [1, 3, 9, 6, 8]

    return 0;
}
