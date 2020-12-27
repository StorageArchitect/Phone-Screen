package LeetCode.Misc;

import static PhoneScreen.Utils.*;

/**
 * Merge two sorted linked lists and return it as a new sorted list.
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 * watch for cut and paste errors
 *
 * @author aahamad
 * @since 20-Dec-2020
 */
public class MergeTwoSortedArrays {

    public static int[] mergeTwoArrays(int[] array1, int[] array2) {
        int size1 = array1.length;
        int size2 = array2.length;
        if (size1 == 0 && size2 == 0 ) {
            throw new IllegalArgumentException("This program does not handle empty arrays");
        }
        int i = 0, j = 0, count = 0;
        int[] result = new int[size1 + size2];
        while(i < size1 && j < size2) {
            if (array1[i] < array2[j]) {
                result[count++] = array1[i++];
            } else {
                result[count++] = array2[j++];
            }
        }
        if (i < size1) {
            while(i < size1) {
                result[count++] = array1[i++];
            }
        }
        if (j < size2) {
            while(j < size2) {
                result[count++] = array1[j++];
            }
        }

        return result;
    }

    public static int[] mergeTwoArraysEnhanced(int[] array1, int[] array2) {
        int size1 = array1.length;
        int size2 = array2.length;
        if (size1 == 0 && size2 == 0 ) {
            throw new IllegalArgumentException("This program does not handle empty arrays");
        }
        int[] result = new int[size1 + size2];
        int idx = result.length -1;
        int p1 = size1 - 1;
        int p2 = size2 - 1;

        while(idx >= 0 && p1 >=0 && p2 >= 0) {
            if (array1[p1] > array2[p2]) {
                result[idx--] = array1[p1--];
            } else {
                result[idx--] = array2[p2--];
            }
        }

        while (p1 >=0) {
            result[idx--] = array1[p1--];
        }

        while (p2 >=0) {
            result[idx--] = array2[p2--];
        }

        return result;
    }



    /**
     * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode() {} ListNode(int
     * val) { this.val = val; } ListNode(int val, ListNode next) { this.val = val; this.next = next; } }
     */
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

    public static void main(String[] args) {
        int[] array1 = {1,2,4};
        int[] array2 = {1,3,4};
        int[] array3 = {2,4};
        int[] array4 = {};
        int[] array5 = {1,2,4};
        int[] array6 = {5,6,7};
        int [] result = mergeTwoArrays(array1,array2);
        System.out.println("The merged Array of: ");
        printArray(array1);
        printArray(array2);
        System.out.println(" Result: ");
        printArray(result);
        result = mergeTwoArrays(array3,array4);
        System.out.println("The merged Array of: ");
        printArray(array3);
        printArray(array4);
        System.out.println(" Result: ");
        printArray(result);
        populateList(result);
        result = mergeTwoArraysEnhanced(array3,array4);
        System.out.println("The Enhanced merged Array of: ");
        printArray(array3);
        printArray(array4);
        System.out.println(" Result: ");
        printArray(result);
        result = mergeTwoArraysEnhanced(array1,array2);
        System.out.println("The Enhanced merged Array of: ");
        printArray(array1);
        printArray(array2);
        System.out.println(" Result: ");
        printArray(result);
        result = mergeTwoArraysEnhanced(array5,array6);
        System.out.println("The Enhanced merged Array of: ");
        printArray(array5);
        printArray(array6);
        System.out.println(" Result: ");
        printArray(result);




    }
}
