"""
Time complexity: O(N)
Space complexity: O(1)

"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        # store the current longest path length
        self.longest = 0

        self.dfs(root)

        return self.longest

    def dfs(self, curr: TreeNode) -> int:
        # base case
        if curr is None:
            # the height of None node is 0
            return 0

        height_left = self.dfs(curr.left)
        height_right = self.dfs(curr.right)

        # update the diameter of binary tree
        self.longest = max(self.longest, height_left + height_right)

        # return the height of current node
        return max(height_left, height_right) + 1

