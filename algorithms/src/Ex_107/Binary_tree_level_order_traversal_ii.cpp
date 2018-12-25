#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        if (!root) {
            return vector<vector<int>> {};
        }
        vector<vector<int>> ans;
        int h = height(root);
        for (int i = h; i >= 1; i--) {
            vector<int> givenLevelNodes;
            getGivenLevelNodes(root, i, givenLevelNodes);
            ans.push_back(givenLevelNodes);
        }
        return ans;
    }

private:
    int height(TreeNode *p) {
        if (!p) {
            return 0;
        }
        int heightL = height(p->left);
        int heightR = height(p->right);
        return heightL > heightR ? heightL + 1 : heightR + 1;
    }

    void getGivenLevelNodes(TreeNode *p, int level,
            vector<int> &givenLevelNodes) {
        if (!p) {
            return;
        }
        if (level == 1) {
            givenLevelNodes.push_back(p->val);
        } else if (level > 1) {
            getGivenLevelNodes(p->left, level - 1, givenLevelNodes);
            getGivenLevelNodes(p->right, level - 1, givenLevelNodes);
        }
    }
};


// declare a template for overloading the << operator for vector<vector<<T>>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<T> &vec) {
    std::cout << "[" << std::endl;
    for (const vector<int> &v : vec) {
        std::cout << "\t[";
        for (const auto &i : v) {
            std::cout << i << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;
    TreeNode a1(3), a2(9), a3(20), a4(15), a5(7);
    a1.left = &a2;
    a1.right = &a3;
    a3.left = &a4;
    a3.right = &a5;
    std::cout << s.levelOrderBottom(&a1) << std::endl;
    return 0;
}
