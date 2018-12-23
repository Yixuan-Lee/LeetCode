// references:
//      https://leetcode.com/articles/unique-binary-search-trees/

/**
 * solution description:
 *      G(n): the numbre of unique BST for a sequence of length n
 *      F(i,n): the number of unique BST, where the number i is served as the root of BST (1<=i<=n)
 *
 *      G(n) = F(1,n) + F(2,n) + ... + F(n-1,n) + F(n,n)
 *
 * bottom cases:
 *      G(0) = 1 (empty tree)
 *      G(1) = 1 (only a root)
 *
 * cartesian product:
 *      F(i,n) = combinations of i's left subtree and i's right subtree, which is
 *               i's left subtree contains 1, 2, ..., i - 1
 *               i's right subtree contains i + 1, i + 2, ..., n
 *          e.g. F(3, 7) = combinations of left subtree [1,2] and right subtree [4,5,6,7]
 *               F(3, 7) = G(2) * G(4)
 *               it means the result does not matter the content of the sequence, but the length of the sequence
 *          so,
 *      F(i,n) = G(i - 1) * G(n - i)
 *          then,
 *      G(n) = ∑ {G(i - 1) * G(n - i)}  (1<=i<=n)
 *
 */


#include <iostream>

class Solution {
public:
    int numTrees(int n) {
        G = new int[n + 1];

        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; i++) {
            G[i] = 0;
            for (int j = 1; j <= i; j++) {
                G[i] += G[j - 1] * G[i - j];
            }
        }

        return G[n];
    }

    ~Solution() {
        delete G;
    }

private:
    int *G;
};


int main() {
    Solution s;
    std::cout << s.numTrees(3) << std::endl;
    return 0;
}
