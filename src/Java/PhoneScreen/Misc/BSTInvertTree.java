package Misc;
import java.util.LinkedList;
import java.util.Queue;

//-- inverting a tree is a breadth first search, sorts the items in descending order
public class BSTInvertTree {

    public static void invertTree(Node root){
        Node currNode  = root;
        Queue<Node> q = new LinkedList<Node>();
        q.add(currNode);
        while(q.isEmpty() == false){
            currNode = q.remove();
            if(currNode != null){
               q.add(currNode.left);
               q.add(currNode.right);
               //-- swap the nodes ..
               Node tmp;
               tmp = currNode.left;
               currNode.left = currNode.right;
               currNode.right = tmp;
            }
        }

    }



    public static void main(String[] args) {
        int[] arr = new int[] {30, 50, 20, 1, 40, 60, 70, 900, 1200, 13, 15, 27};
        BinaryTree tree = new BinaryTree(arr);
        System.out.println(" Pre invertion Ascending order");
        tree.inOrderTraversal(tree.getRoot());
        System.out.println();

        invertTree(tree.getRoot());

        System.out.println(" Post invertion Descending order");
        tree.inOrderTraversal(tree.getRoot());
        System.out.println();
    }
}
