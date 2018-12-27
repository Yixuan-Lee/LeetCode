// references:
//      https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/discuss/35220/My-Accepted-Java-Solution


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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }
        return buildBST(nums, 0, static_cast<int> (nums.size() - 1));
    }

private:
    TreeNode *buildBST(vector<int> &nums, int startIdx, int endIdx) {
        if (startIdx > endIdx) {
            return nullptr;
        }
        // every time, we choose the middle value as a tree's root value,
        // because the array is already sorted (ascending), so that guarantees
        // the tree is height-balanced
        int mid = (startIdx + endIdx) / 2;
        auto q = new TreeNode(nums[mid]);
        q->left = buildBST(nums, startIdx, mid - 1);
        q->right = buildBST(nums, mid + 1, endIdx);
        return q;
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

int height(TreeNode *p) {
    if (!p) {
        return 0;
    }
    int heightL = height(p->left);
    int heightR = height(p->right);
    return heightL > heightR ? heightL + 1 : heightR + 1;
}

void getGivenLevelOrder(TreeNode *p, int level,
        vector<int> &nodes) {
    if (!p) {
        return;
    }
    if (level == 1) {
        nodes.push_back(p->val);
    } else if (level > 1) {
        getGivenLevelOrder(p->left, level - 1, nodes);
        getGivenLevelOrder(p->right, level - 1, nodes);
    }
}

void printLevelOrder(TreeNode *root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        vector<int> givenLevel;
        getGivenLevelOrder(root, i, givenLevel);
        std::cout << givenLevel << std::endl;
    }
}

int main() {
    Solution s;
//    vector<int> nums {-10, -3, 0, 5, 9};
    vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8};
    TreeNode *root = s.sortedArrayToBST(nums);
    printLevelOrder(root);
    return 0;
}

