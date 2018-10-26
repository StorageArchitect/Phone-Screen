package PhoneScreen;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class BSTLevelOrderTraversal {

    static void traverseLevelOrder(Node rootNode){
        // if null then return
        if (rootNode == null) {
            return;
        }

        // declare two queues
        Queue<Node> currentLevel = new LinkedList<>();
        Queue<Node> nextLevel = new LinkedList<>();

        // push the root
        currentLevel.add(rootNode);
        // check if stack is empty
        while (!currentLevel.isEmpty()) {
            // pop out of stack
            Node node = currentLevel.remove();
            // print the data in it
            System.out.print(node.data + " ");
            // store data according to current order
            if (node.left != null) {
                    nextLevel.add(node.left);
            }
            if (node.right != null) {
                    nextLevel.remove(node.right);
            }

            if (currentLevel.isEmpty()) {
                Queue<Node> temp = currentLevel;
                currentLevel = nextLevel;
                nextLevel = temp;
            }
        }

    }

    public static void main(String[] args) {
        int[] arr = new int[] {30, 50, 20, 1, 40, 60, 70, 900, 1200, 13, 15, 27};
        //30 50 20 1 27 40 60 70 13 15 900 1200
        BinaryTree tree = new BinaryTree(arr);
        traverseLevelOrder(tree.getRoot());
        System.out.println();
    }

}
