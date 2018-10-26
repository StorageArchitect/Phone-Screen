package PhoneScreen;

public class BSTCommonAncestor {

    /*************************************************************************************
     * We can solve this problem using BST properties. We can recursively traverse the BST from root.
     * The main idea of the solution is, while traversing from top to bottom, the first node n we encounter
     * with value between n1 and n2, i.e., n1 < n < n2 or same as one of the n1 or n2, is LCA of n1 and n2
     * (assuming that n1 < n2). So just recursively traverse the BST in, if nodes value is greater than both n1 and n2
     * then our LCA lies in left side of the node, if its is smaller than both n1 and n2, then LCA lies on right side.
     * Otherwise root is LCA (assuming that both n1 and n2 are present in BST)


     * @param root
     * @param key1
     * @param key2
     * @return
     */
    static public Node lowestCommonAncestorBinaryTree(Node root, int key1, int key2){
        if(root == null){
            return null;
        }


        // If both n1 and n2 are smaller than root, then LCA lies in left
        if (root.data > key1 && root.data > key2)
            return lowestCommonAncestorBinaryTree(root.left, key1, key2);

        // If both n1 and n2 are greater than root, then LCA lies in right
        if (root.data < key1 && root.data < key2)
            return lowestCommonAncestorBinaryTree(root.right, key1, key2);

        return root;

    }


    static public Node lowestCommonAncestorTree(Node root, int key1, int key2){
        if(root == null){
          return null;
        }

        if(root.data == key1 || root.data == key2){
            return root;
        }

        Node lNode = lowestCommonAncestorTree(root.left, key1, key2);
        Node rNode = lowestCommonAncestorTree(root.right, key1, key2);
        if(lNode != null && rNode != null){
            //-- discard and return myself
            System.out.println("Found a LCA " + root.data + " of key: " + key1 + " and key: " + key2);
            return root;
        }

        if(lNode == null && rNode == null){
            return null;
        }

        return lNode != null ? lNode:rNode;
    }

    public static void main(String[] args) {
        //int[] arr = new int[] {30, 50, 20, 1, 40, 60, 70, 900, 1200, 13, 15, 27};
        int[] arr = new int[] {30, 20, 1200};
        BinaryTree tree = new BinaryTree(arr);
        Node t = lowestCommonAncestorTree(tree.getRoot(),1200, 20);
        System.out.println("Found a LCA of tree " + t.data + " of key: " + 1200 + " and key: " + 20);
        t = lowestCommonAncestorBinaryTree(tree.getRoot(),1200, 20);
        System.out.println("Found a LCA of BST " + t.data + " of key: " + 1200 + " and key: " + 20);

    }

}
