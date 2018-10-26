package PhoneScreen;


public class BSTIsSorted {

    public static void isSorted(Node root, int prev){
        if(root == null){
            return;
        }
        isSorted(root.left, prev);
        if(prev > root.data){
            System.out.print( "Tree is not sorted " + prev + " > " + root.data);
            return;
        }
        isSorted(root.right, prev);

    }

    public static void main(String[] args) {
        int[] arr = new int[] {30, 50, 20, 1, 40, 60, 70, 900, 1200, 13, 15, 27};
        BinaryTree tree = new BinaryTree(arr);
        isSorted(tree.getRoot(), Integer.MIN_VALUE);
    }
}
