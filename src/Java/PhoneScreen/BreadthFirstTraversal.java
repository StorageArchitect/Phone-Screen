package PhoneScreen;

import java.util.LinkedList;
import java.util.Queue;

//-- shortest path to a node
public class BreadthFirstTraversal{

    public static void traverse(Node root) {
        Queue<Node> q = new LinkedList<>();
        Node currNode = root;
        q.add(currNode);
        while(q.isEmpty() == false){
            currNode = q.remove();
            System.out.print(currNode.data + " ");
            if(currNode.left != null)
               q.add(currNode.left);
            if(currNode.right != null)
               q.add(currNode.right);
       }
        System.out.println();
    }


    public static void main(String[] args) {
        int[] arr = new int[] {30, 50, 20, 1, 40, 60, 70, 900, 1200, 13, 15, 27};
        /**
         * 30 50 20  27 1 60 40   70 13   15 900  1200
         */
        BinaryTree tree = new BinaryTree(arr);
        traverse(tree.getRoot());
    }
}
