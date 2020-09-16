/**
 * BFS method
 *
 * Time complexity: O(N)
 * Space complexity: O(N)
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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();

        // boundary checking
        if (root == null) {
            return result;
        }

        // use a Queue to store all the nodes from the right view
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            // keep track of the size of the Queue
            int n = queue.size();

            while (n > 0) {
                root = queue.poll();
                n--;
                if (n == 0)
                    // meaning the root is the rightmost node in the current level
                    result.add(root.val);

                // traverse the left child first
                if (root.left != null)
                    queue.offer(root.left);
                // traverse the right child then
                if (root.right != null)
                    queue.offer(root.right);
            }
        }

        return result;
    }
}