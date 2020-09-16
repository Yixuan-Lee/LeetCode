"""
Reference:
https://leetcode.com/problems/path-sum-iii/discuss/91877/C%2B%2B-5-Line-Body-Code-DFS-Solution

Time complexity: O(N^2)
Space complexity: O(1)
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        # check boundary
        if root is None:
            return 0

        return self.pathSum(root.left, sum) + self.pathSum(root.right, sum) + self.include_curr(root, sum)

    def include_curr(self, curr: TreeNode, target: int, curr_sum: int = 0) -> int:
        if curr is None:
            return 0

        return (curr_sum + curr.val == target) + self.include_curr(curr.left, target, curr_sum + curr.val) + self.include_curr(curr.right, target, curr_sum + curr.val)


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
    print(solu.pathSum(get_test_case_1(), 8))       # expect 3
    print(solu.pathSum(get_test_case_2(), 0))       # expect 1
    print(solu.pathSum(get_test_case_3(), -1))      # expect 4
    print(solu.pathSum(get_test_case_4(), 22))      # expect 3

