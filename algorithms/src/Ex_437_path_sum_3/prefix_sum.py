"""
Reference:
https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method

Time complexity: O(n)
Space complexity: O(n)

"""

from typing import Dict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if root is None:
            return 0

        # store all possible sum from root to the current node
        #   key: possible sum
        #   value: how many paths that can get the possible sum
        prefix_sum = {}

        return self.find_path_sum(root, sum, 0, prefix_sum)

    def find_path_sum(self, curr: TreeNode, target: int, current_sum: int, prefix_sum: Dict) -> int:
        if curr is None:
            return 0

        current_sum += curr.val
        # number of valid path ended by the current node
        num_path_to_curr = prefix_sum.get(current_sum - target, 0) + (current_sum == target)
        # update the prefix sum map so that the children nodes will use the new prefix sum map
        prefix_sum[current_sum] = prefix_sum.get(current_sum, 0) + 1
        # accumulate the 3 possibilities:
        #   1. number of valid paths ended by the current node
        #   2. number of valid paths including the current node and going to left branch
        #   3. number of valid paths including the current node and going to right branch
        result = num_path_to_curr \
                 + self.find_path_sum(curr.left, target, current_sum, prefix_sum) \
                 + self.find_path_sum(curr.right, target, current_sum, prefix_sum)
        # when backtracking (going from children node back to parent node), restore the prefix sum map
        prefix_sum[current_sum] = prefix_sum.get(current_sum) - 1

        return result


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
    # print(solu.pathSum(get_test_case_1(), 8))     # expect 3
    # print(solu.pathSum(get_test_case_2(), 0))     # expect 1
    # print(solu.pathSum(get_test_case_3(), -1))    # expect 4
    print(solu.pathSum(get_test_case_4(), 22))    # expect 3
