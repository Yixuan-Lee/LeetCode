/**
 * Idea:
 * flatten the binary tree to an array by in-order traversal.
 *
 * next()
 * Time complexity:
 * Space complexity: O(N)
 *
 * hasNext()
 * Time complexity:
 * Space complexity: O(N)
 *
 * Comment:
 * This solution does not satisfy the requirement since O(N) > O(h)
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

class BSTIterator {
    // store the flattened bst
    List<Integer> flattenedTree;
    // index of current node
    int index;

    public BSTIterator(TreeNode root) {
        this.flattenedTree = new ArrayList<Integer>();
        this.index = -1;
        this.inorderTraversal(root);
    }

    /** @return the next smallest number */
    public int next() {
        this.index++;
        return this.flattenedTree.get(this.index);
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return this.index + 1 < this.flattenedTree.size();
    }

    /** helper function: in-order traversal **/
    public void inorderTraversal(TreeNode curr) {
        if (curr == null) {
            return;
        }

        // do inorder traversal on the left subtree
        if (curr.left != null)
            inorderTraversal(curr.left);

        // push the curr's value
        this.flattenedTree.add(curr.val);

        // do inorder traversal on the right subtree
        if (curr.right != null)
            inorderTraversal(curr.right);
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
