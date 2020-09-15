# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        pass


def get_test_case_1() -> TreeNode:
    node_9 = TreeNode(9)
    node_15 = TreeNode(15)
    node_7 = TreeNode(7)
    node_20 = TreeNode(20, node_15, node_7)
    root = TreeNode(-10, node_9, node_20)

    return root


if __name__ == "__main__":
    solu = Solution()
    print(solu.maxPathSum(get_test_case_1()))

