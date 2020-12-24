package Misc;



public class BSTBalanced {
    /**
     * Determines whether a binary tree is balanced.
     *
     * @param {BinaryTreeNode} root The root of the tree.
     * @returns Whether the tree is balanced.
     */
    public static boolean isBinaryTreeBalanced(Node root) {
        if (root == null) {
            throw new IllegalArgumentException(
                    "The tree root must be non null");
        }
        System.out.println("max Depth is " +  maxDepth(root));
        System.out.println("min Depth is " +  minDepth(root));
        return maxDepth(root) - minDepth(root) <= 1;
    }

    /**
     * Determines the minimum depth of a binary tree node.
     *
     * @param node The node to check.
     * @return The minimum depth of a binary tree node.
     */
    private static int minDepth(Node node) {
        if (node == null) {
            return 0;
        }
        return 1 + Math.min(minDepth(node.left), minDepth(node.right));
    }

    /**
     * Determines the maximum depth of a binary tree node.
     *
     * @param node The node to check.
     * @return The maximum depth of a binary tree node.
     */
    private static int maxDepth(Node node) {
        if (node == null) {
            return 0;
        }
        return 1 + Math.max(maxDepth(node.left), maxDepth(node.right));
    }

    public static void main(String[] args) {
        //int[] arr = new int[] {3, 5, 2, 1, 4, 6, 7};
        int[] arr = new int[] {3, 5, 2};
        BinaryTree tree = new BinaryTree(arr);
        System.out.println("The binary tree is balanced is: " + isBinaryTreeBalanced(tree.getRoot()));

    }
}





