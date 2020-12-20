package LeetCode;

import java.util.List;

/**
 * Given two sorted linked lists, merge them so that the resulting linked list is also sorted.
 * Things to watch out for
 * Lookout for the case where one of the input array is null or has only one entry.
 *
 * @author aahamad
 * @since 20-Dec-2020
 */
public class MergeTwoSortedLists {

    private static class ListNode {
        int val;
        ListNode next;

        ListNode() {}

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode current = null;
        ListNode resultList = null;
        while (l1 != null && l2 != null) {

            if (l1.val < l2.val) {
                if (resultList == null) {
                    resultList = new ListNode(l1.val, null);
                    current = resultList;
                } else {
                    ListNode list = new ListNode(l1.val, null);
                    current.next = list;
                    current = list;
                }
                l1 = l1.next;
            } else {
                if (resultList == null) {
                    resultList = new ListNode(l2.val, null);
                    current = resultList;
                } else {
                    ListNode list = new ListNode(l2.val, null);
                    current.next = list;
                    current = list;
                }
                l2 = l2.next;
            }
        }

        while (l1 != null) {

            if (resultList == null) {
                resultList = new ListNode(l1.val, null);
                current = resultList;
            } else {
                ListNode list = new ListNode(l1.val, null);
                current.next = list;
                current = list;
            }

            l1 = l1.next;
        }

        while (l2 != null) {

            if (resultList == null) {
                resultList = new ListNode(l2.val, null);
                current = resultList;
            } else {
                ListNode list = new ListNode(l2.val, null);
                current.next = list;
                current = list;
            }
            l2 = l2.next;
        }

        return resultList;
    }


    /**
     * Populate node does not work, do not use without debugging.
     * @param input
     * @param resultList
     * @param current
     * @return
     */
    private static ListNode populateNode(ListNode input, ListNode resultList, ListNode current) {

        if (resultList == null) {
            resultList = new ListNode(input.val, null);
            current = resultList;
        } else {
            ListNode list = new ListNode(input.val, null);
            current.next = list;
            current = list;
        }

        return current;
    }

    private static ListNode populateList(int[] array) {
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



    public static void printArray(int[] a) {
        for (int i=0; i < a.length; i++) {
            System.out.print(a[i] + ", ");
        }
        System.out.println(" " );

    }

    public static void printList(ListNode node) {
        if (node == null) {
            return;
        }
        System.out.print(node.val + ", ");
        if ( node.next == null) {
           return;
        }
        printList(node.next);
    }

    public static void main(String[] args) {
        int[] array1 = new int[] {1, 3, 5, 6};
        int[] array2 = new int[] {2, 4, 6, 20, 34};

        ListNode list1 = populateList(array1);
        ListNode list2 = populateList(array2);
        System.out.println("The list of: ");
        printArray(array1);
        System.out.println("is : ");
        printList(list1);
        System.out.println("The list of: ");
        printArray(array2);
        System.out.println("is : ");
        printList(list2);
        System.out.println(" Result: ");
        printList(mergeTwoLists(list1, list2));
        System.out.println(" null list result: ");
        printList(mergeTwoLists(null, list2));

   }

}
