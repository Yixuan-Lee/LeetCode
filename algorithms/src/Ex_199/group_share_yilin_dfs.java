/**
 * DFS method
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
    List<Integer> result = new ArrayList<>();

    public List<Integer> rightSideView(TreeNode root) {
        dfs(root, 0);

        return result;
    }

    private void dfs(TreeNode root, int level) {
        if (root == null) {
            return;
        }

        // check if the level is equal to the result.size
        // if yes, it means that this is the first time reaching to this level, then add the current node
        // if no, then just ignore
        if (level == result.size())
            result.add(root.val);

        // first, run dfs on right subtree
        dfs(root.right, level + 1);
        // second, run dfs on left subtree
        dfs(root.left, level + 1);
    }
}
