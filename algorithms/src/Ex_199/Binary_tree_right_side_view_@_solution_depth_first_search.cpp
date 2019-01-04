// references:
//      https://leetcode.com/articles/binary-tree-right-side-view/  (great article for depth-first search and breadth-first search)


#include <iostream>
#include <vector>
#include <stack>
#include <map>

using std::vector;
using std::stack;
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
        stack<TreeNode *> nodeStack;
        // store the depth of nodes that we are going to visit
        stack<int> depthStack;

        // push the root, meaning that we are going to visit root first
        nodeStack.push(root);
        depthStack.push(0);

        while (!nodeStack.empty()) {
            // visit the top node in the stack
            TreeNode *node = nodeStack.top();
            nodeStack.pop();
            int depth = depthStack.top();
            depthStack.pop();

            if (node != nullptr) {
                maxDepth = (depth > maxDepth ? depth : maxDepth);

                // if the maxDepth does not exist in the map, it means that
                // we have moved to a newer level of the tree, and
                // once we visit a newer level, the right most node is visited
                // before all other nodes in the same level
                if (rightMostValueAtEachDepth.find(depth)
                    == rightMostValueAtEachDepth.end()) {
                    rightMostValueAtEachDepth.insert(
                            std::make_pair(depth, node->val));
                }

                // push the left and right nodes, since we are going to visit
                // them next time
                // there has to push the right node after the left node, since
                // next time, we can visit right node before the left
                nodeStack.push(node->left);
                nodeStack.push(node->right);
                // push the depth of the left and right nodes
                depthStack.push(depth + 1);
                depthStack.push(depth + 1);
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
