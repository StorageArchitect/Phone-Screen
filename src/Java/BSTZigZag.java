package PhoneScreen;

//-- breadth first search, but on alternate rows flip .. use two stack and stack


import java.util.Stack;

public class BSTZigZag {

    static void traverseZigZag(Node rootNode){
        // if null then return
        if (rootNode == null) {
            return;
        }

        // declare two stacks
        // ... see the difference between this and Inorder Traversal Q vs Stack
        Stack<Node> currentLevel = new Stack<>();
        Stack<Node> nextLevel = new Stack<>();

        // push the root
        currentLevel.push(rootNode);
        boolean leftToRight = true;
        // check if stack is empty
        while (!currentLevel.isEmpty()) {
            // pop out of stack
            Node node = currentLevel.pop();
            // print the data in it
            System.out.print(node.data + " ");
            // store data according to current order
            if (leftToRight) {
                if (node.left != null) {
                    nextLevel.push(node.left);
                }
                if (node.right != null) {
                    nextLevel.push(node.right);
                }
            }
            else {
                if (node.right != null) {
                    nextLevel.push(node.right);
                }
                if (node.left != null) {
                    nextLevel.push(node.left);
                }
            }

            if (currentLevel.isEmpty()) {
                leftToRight = !leftToRight;
                Stack<Node> temp = currentLevel;
                currentLevel = nextLevel;
                nextLevel = temp;
            }
        }

    }

    public static void main(String[] args) {
        int[] arr = new int[] {30, 50, 20, 1, 40, 60, 70, 900, 1200, 13, 15, 27};
        //30 50 20 1 27 40 60 70 13 15 900 1200
        BinaryTree tree = new BinaryTree(arr);
        traverseZigZag(tree.getRoot());
        System.out.println();
    }

}
