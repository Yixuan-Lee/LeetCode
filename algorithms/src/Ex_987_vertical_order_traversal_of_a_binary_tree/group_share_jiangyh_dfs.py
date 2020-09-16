"""
DFS method

Time complexity:
Space complexity: O(N)

"""

import collections

# Definition for a binary tree node.

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def verticalTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        # define a map where
        # the key is x coordinate
        # the value is a tuple of two element (y coordinate, value)
        group = collections.defaultdict(list)

        def dfs(node, x, y):
            # key is x coordinate
            # value is a tuple (y coordinate, node value)
            group[x].append((y, node.val))

            if node.left is not None:
                # go to left
                # for sorting purpose, it changes to y+1 instead of y-1
                dfs(node.left, x-1, y+1)
            if node.right is not None:
                # go to right
                # for sorting purpose, it changes to y+1 instead of y-1
                dfs(node.right, x+1, y+1)

        dfs(root, 0, 0)

        return [[t[1] for t in sorted(group[x])] for x in sorted(group)]

