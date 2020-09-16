/**
 * Recursive solution
 *
 * Time complexity:
 * Space complexity:
 *
 */

/**
 * Definition for a binary tree node.
 */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();

        helper(result, root);

        return result;
    }

    public void helper(List<Integer> result, TreeNode root) {
        if (root == null) {
            return;
        }

        helper(result, root.left);
        result.add(root.val);
        helper(result, root.right);
    }
}
