package PhoneScreen;

public class BSTSearchTraversal {

    public static void main(String[] args) {
        int[] arr = new int[] {30, 50, 20, 1, 40, 60, 70,900,1200,13,15,27};
        BinaryTree tree = new BinaryTree(arr);
        System.out.println("This tree is a valid BST " + tree.isValidBST(tree.getRoot(),
                                                   Integer.MIN_VALUE, Integer.MAX_VALUE));
        System.out.println("Search for 10 returned: " + tree.isPresent(10));
        System.out.println("Search for 1200 returned: " + tree.isPresent(1200));
        System.out.println("Search for 1 returned: " + tree.isPresent(1));
        //-- in ordered traversal will give you the keys sorted in order.
        System.out.println("In Order Traversal : "  );
        tree.inOrderTraversal(tree.getRoot());
        System.out.println( );

        System.out.println("Pre Order Traversal: "  );
        tree.preOrderTraversal(tree.getRoot());
        System.out.println();
        System.out.println("Post Order Traversal:" );
        tree.postOrderTraversal(tree.getRoot());
        System.out.println(  );

    }
}
