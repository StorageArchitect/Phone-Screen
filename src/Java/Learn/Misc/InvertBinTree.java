package Misc;

import java.util.LinkedList;
import java.util.List;

/**
 * A binary tree is a data structure in which each element has at most two
 * children, which are referred to as the left child and the right child.
 * The top element of the tree is the root node, whereas the children are the interior nodes.
 *
 *
 * <p>However, if a node has no child, it's called a leaf.
 *
 * @author aahamad
 * @since 12-Dec-2020
 */
public class InvertBinTree {

    static void invertTree(Node root) {
        if (root == null) {
            return ;
        }
        Node temp = root.left;
        root.left = root.right;
        root.right = temp;
        invertTree(root.left);
        invertTree(root.right);
    }

    public void reverseRecursive(Node treeNode) {
        if(treeNode == null) {
            return;
        }
        Node temp = treeNode.left;
        treeNode.left = treeNode.right;
        treeNode.right = temp;

        reverseRecursive(treeNode.left);
        reverseRecursive(treeNode.right);
    }

    public void reverseIterative(Node treeNode) {
        List <Node> queue = new LinkedList <>();

        if(treeNode != null) {
            queue.add(treeNode);
        }

        while(!queue.isEmpty()) {
            Node node = ((LinkedList<Node>) queue).poll();
            if(node.left != null){
                queue.add(node.left);
            }
            if(node.right != null){
                queue.add(node.right);
            }

            Node temp = node.left;
            node.left  = node.right;
            node.right = temp;
        }
    }


    public static void main(String[] args) {
        int[] arr = new int[] {30, 50, 20, 1, 40, 60, 70, 900, 1200, 13, 15, 27};
        BinaryTree tree = new BinaryTree(arr);
        System.out.println("Initial tree values");
        BreadthFirstTraversal.traverse(tree.getRoot());
        System.out.println("reversed tree values");
        invertTree(tree.getRoot());
        BreadthFirstTraversal.traverse(tree.getRoot());
    }

}
