package PhoneScreen;
/**
 * A  class that can be used for various utility methods.
 *
 * @author aahamad
 * @since 24-Dec-2020
 */
public class Utils {

    public static class ListNode {
        public int val;
        public ListNode next;

        ListNode() {}

        public ListNode(int val) {
            this.val = val;
        }

        public ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public static void printArray(int[] a) {
        for (int i=0; i < a.length; i++) {
            System.out.print(a[i] + ", ");
        }
        System.out.println(" " );

    }

    public static void printArray(double[] a) {
        for (int i=0; i < a.length; i++) {
            System.out.print(a[i] + ", ");
        }
        System.out.println(" " );

    }

    public static void printArray(int[][] a) {
        for (int i=0; i < a.length; i++) {
            System.out.print( " { " + a[i][0] + ", " + a[i][1] + " } " );
        }
        System.out.println(" " );

    }
    public static void printList(ListNode node) {
        if (node == null) {
            return;
        }
        System.out.print(node.val + ", ");
        printList(node.next);
    }

    public static void printList(ListNode node, int count) {
        if (node == null || count <=0) {
            return;
        }
        System.out.print(node.val + ", ");
        printList(node.next, --count);
    }

    /**
     * utility method to populate a suitable list.
     * @param array
     * @return
     */

    public static ListNode populateList(int[] array) {
        if (array.length == 0 ) {
            return null;
        }
        ListNode list = new ListNode(array[0]);
        ListNode worker = list;

        for (int i = 1; i < array.length; i++) {
            ListNode node = new ListNode(array[i], null);
            worker.next = node;
            worker = node;
        }
        return list;
    }
}
