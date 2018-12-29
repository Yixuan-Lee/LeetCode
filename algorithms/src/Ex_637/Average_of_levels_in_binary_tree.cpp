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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ans;
        if (!root) {
            return ans;
        }
        calculateAvg(root, ans);
        return ans;
    }

private:
    void calculateAvg(const TreeNode *root, vector<double> &ans) {
        int h = height(root);
        for (int i = 1; i <= h; i++) {
            vector<int> per;
            calculateGivenLevelAvg(root, i, per);
            double sum = 0.0;
            for (auto j : per) {
                sum += j;
            }
            ans.push_back(sum / per.size());
        }
    }

    int height(const TreeNode *p) {
        if (!p) {
            return 0;
        }
        int heightL = height(p->left);
        int heightR = height(p->right);
        return heightL > heightR ? heightL + 1 : heightR + 1;
    }

    void calculateGivenLevelAvg(const TreeNode *p, int level,
            vector<int> &per) {
        if (!p) {
            return;
        }
        if (level == 1) {
            per.push_back(p->val);
        } else if (level > 1) {
            calculateGivenLevelAvg(p->left, level - 1, per);
            calculateGivenLevelAvg(p->right, level - 1, per);
        }
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
    TreeNode a1(3), a2(9), a3(20), a4(15), a5(7);
    a1.left = &a2;
    a1.right = &a3;
    a3.left = &a4;
    a3.right = &a5;
    vector<double> res = s.averageOfLevels(&a1);
    std::cout << res << std::endl;

    TreeNode b1(2147483647), b2(2147483647), b3(2147483647);
    b1.left = &b2;
    b1.right = &b3;
    res = s.averageOfLevels(&b1);
    std::cout << res << std::endl;
    return 0;
}
