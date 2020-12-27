package Misc;

//-- this is a binary search tree ..
//-- binary search tree
//-- left is less (rule of thumb) for binary search tree
// -- the left node is smaller than the root node
// -- the root node itself is smaller than the right node
//-- ask if the problem is for binary search tree vs just binary tree
//-- clarify if the tree is balanced or not

public class BinaryTree {

    private Node root = null;

    public BinaryTree(int[] arr){
        buildTree(arr);
    }

    public Node getRoot() {
        return root;
    }

    private  Node insert(Node root, int data) {
        if(root == null) {
            return new Node(data);
        } else {
            Node cur;
            if(data <= root.data) {
                cur = insert(root.left, data);
                root.left = cur;
            } else {
                cur = insert(root.right, data);
                root.right = cur;
            }
            return root;
        }
    }

    private void buildTree(int[] arr) {
        for(int i = 0; i < arr.length; i++){
            int data = arr[i];
            root = insert(root, data);
        }
    }

    public boolean isPresent(int key){
        if(search(root, key) == null)
            return false;

        return true;

    }

    private Node search(Node root, int key)    {
        // Base Cases: root is null or key is present at root
        if (root==null || root.data ==key)
            return root;
        // key is less than root's data go left
        if (root.data > key)
            return search(root.left, key);
        // key is greater than root's data go right
        return search(root.right, key);
    }


    public void inOrderTraversal(Node root){
        if(root == null){
            return;
        }
        inOrderTraversal(root.left);
        System.out.print( " " + root.data);
        inOrderTraversal(root.right);

    }

    boolean isValidBST(Node root, int l, int r)
    {
        // Base condition
        if (root == null)
            return true;

        // if left node exist then check it has
        // correct data or not i.e. left node's data
        // should be less than root's data
        // if right node exist then check it has
        // correct data or not i.e. right node's data
        // should be greater than root's data
        if (root.data < l ||root.data > r )
            return false;


        // check recursively for every node.
        return isValidBST(root.left, l, root.data) &&
                isValidBST(root.right, root.data, r);
    }

    public void preOrderTraversal(Node root){
        if(root == null){
            return;
        }
        System.out.print( " " + root.data);
        preOrderTraversal(root.left);
        preOrderTraversal(root.right);

    }

    public void postOrderTraversal(Node root){
        if(root == null){
            return;
        }
        postOrderTraversal(root.left);
        postOrderTraversal(root.right);
        System.out.print( " " + root.data);

    }
}
