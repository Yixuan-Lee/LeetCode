"""
Time Limit Exceeded

Time complexity: O(n^2)
Space complexity: O(n)

"""

from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.valid_path = []

    def pathSum(self, root: TreeNode, sum: int) -> int:
        # boundary checking
        if root is None:
            return 0

        if root.val == sum:
            self.valid_path.append([root.val])

        # number of valid paths in the left subtree excluding the current root
        self.pathSum(root.left, sum)

        # number of valid paths in the right subtree excluding the current root
        self.pathSum(root.right, sum)

        # number of valid paths including the current root and going to left subtree
        self.helper(root.left, sum, root.val, [root.val])

        # number of valid paths including the current root and going to right subtree
        self.helper(root.right, sum, root.val, [root.val])

        return len(self.valid_path)

    def helper(self, root: TreeNode, target: int, curr: int, path: List[int]):
        if root is None:
            return

        if curr + root.val == target:
            path.append(root.val)
            self.valid_path.append(path)

        # include the current root and go to left
        if root.left is not None:
            self.helper(root.left, target, curr + root.val, path + [root.val])

        # include the current root and go to right
        if root.right is not None:
            self.helper(root.right, target, curr + root.val, path + [root.val])


def get_test_case_1() -> TreeNode:
    # convention:
    # 3_1 represent the first TreeNode with value 3
    # n2 represent -2
    node_3_1 = TreeNode(3)
    node_n2 = TreeNode(-2)
    node_3_2 = TreeNode(3, node_3_1, node_n2)
    node_1 = TreeNode(1)
    node_2 = TreeNode(2, None, node_1)
    node_5 = TreeNode(5, node_3_2, node_2)
    node_11 = TreeNode(11)
    node_n3 = TreeNode(-3, None, node_11)
    node_10 = TreeNode(10, node_5, node_n3)

    return node_10

def get_test_case_2() -> TreeNode:
    node_1_1 = TreeNode(1)
    node_1_2 = TreeNode(1)
    node_0 = TreeNode(0, node_1_1, node_1_2)

    return node_0

def get_test_case_3() -> TreeNode:
    node_n1 = TreeNode(-1)
    node_1_1 = TreeNode(1, node_n1)
    node_3 = TreeNode(3)
    node_n2_1 = TreeNode(-2, node_1_1, node_3)
    node_n2_2 = TreeNode(-2)
    node_n3 = TreeNode(-3, node_n2_2)
    node_1_2 = TreeNode(1, node_n2_1, node_n3)

    return node_1_2

def get_test_case_4() -> TreeNode:
    node_7 = TreeNode(7)
    node_2 = TreeNode(2)
    node_11 = TreeNode(11, node_7, node_2)
    node_4_1 = TreeNode(4, node_11)
    node_5 = TreeNode(5)
    node_1 = TreeNode(1)
    node_4_2 = TreeNode(4, node_5, node_1)
    node_13 = TreeNode(13)
    node_8 = TreeNode(8, node_13, node_4_2)
    node_5 = TreeNode(5, node_4_1, node_8)

    return node_5


if __name__ == "__main__":
    solu = Solution()
    print(solu.pathSum(get_test_case_1(), 8)) # expect 3
    print(solu.valid_path)

    # print(solu.pathSum(get_test_case_2(), 0)) # expect 1
    # print(solu.valid_path)

    # print(solu.pathSum(get_test_case_3(), -1))    # expect 4
    # print(solu.valid_path)

    # print(solu.pathSum(get_test_case_4(), 22))  # expect 3
    # print(solu.valid_path)
