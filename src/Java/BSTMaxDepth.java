package PhoneScreen;

public class BSTMaxDepth {
    // in order traversal
    public static int recurseTraverse(Node node) {
        int lCount = 0;
        int rCount = 0;
        if(node.left != null){
            lCount = 1 +   recurseTraverse(node.left);
        }

        if(node.right != null) {
            rCount = 1 +  recurseTraverse(node.right);
        }
        return lCount >= rCount ? lCount: rCount;
    }

    public static int height(Node root) {
        // Write your code here.
        return recurseTraverse(root);
    }


    public static void main(String[] args) {
        int[] arr = new int[] {3, 5, 2, 1, 4, 6, 7};
        BinaryTree tree = new BinaryTree(arr);
        int height = height(tree.getRoot());
        System.out.println(height);
    }
}
