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
    int max_path_sum = Integer.MIN_VALUE;
    
    public int maxPathSum(TreeNode root) {
        dfs(root);    
        
        return max_path_sum;
    }
    
    private int dfs(TreeNode curr) {
        /**
         * return the current max path sum
         */
        if (curr == null) {
            return 0;
        }
        
        int left = dfs(curr.left);
        int right = dfs(curr.right);
        
        // case 1: only the root node itself
        int case_1 = curr.val;
        // case 2: current node + path from curr's left subtree
        int case_2 = curr.val + left;
        // case 3: current node + path from curr's right subtree
        int case_3 = curr.val + right;
        // case 4: current node + path from curr's left subtree + path from curr's right subtree
        int case_4 = curr.val + left + right;
        
        // in all possible path sums rooted by the curr node, if one is bigger than the current global max path sum, then update the global max path sum
        this.max_path_sum = Math.max(this.max_path_sum, Math.max(case_1, Math.max(case_2, Math.max(case_3, case_4))));
        
        // return the max path sum which is not rooted by the curr node to parent node (previous recursion)
        return Math.max(curr.val, Math.max(curr.val + left, curr.val + right));
    }
}