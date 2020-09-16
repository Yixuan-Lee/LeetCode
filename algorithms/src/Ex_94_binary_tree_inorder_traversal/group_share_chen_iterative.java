/**
 * Iterative solution
 *
 * Time complexity: O(N)
 * Space complexity: O(N)
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
        Stack<TreeNode> s = new Stack<>();

        List<Integer> result = new ArrayList<Integer>();

        while (root != null || !s.isEmpty()) {
            while (root != null) {
                s.push(root);
                root = root.left;
            }

            root = s.pop();
            result.add(root.val);
            root = root.right;
        }

        return result;
    }
}
