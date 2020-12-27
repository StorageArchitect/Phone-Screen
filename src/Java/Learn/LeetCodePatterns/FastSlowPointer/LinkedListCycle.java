package LeetCodePatterns.FastSlowPointer;

import PhoneScreen.Utils;
import sun.jvm.hotspot.memory.LinearAllocBlock;

import java.util.HashSet;

import static PhoneScreen.Utils.populateList;

/**
 * Two pointer pointer to see if the linked list has a loop.
 *
 * @author aahamad
 * @since 26-Dec-2020
 */
public class LinkedListCycle {

    /**
     * Takes a sorted array, if there is a duplicate value at the end (lower than the previous value)
     * it returns a list that has a loop.
     * @param listNode
     * @return
     */

    private static Utils.ListNode createLoop(Utils.ListNode listNode) {
        if (listNode.next == null){
            return listNode;
        }
        Utils.ListNode last = createLoop(listNode.next);
        if (listNode.val == last.val) {
            last.next = listNode;
        }
        return last;
    }

    private static boolean detectLoopWithTable(Utils.ListNode listNode) {
        HashSet<Utils.ListNode> set = new HashSet <Utils.ListNode>();

        while(listNode != null) {
            if (set.contains(listNode)) {
              return true;
            }
            set.add(listNode);
            listNode = listNode.next;

        }

        return false;
    }

    private static boolean detectLoop(Utils.ListNode listNode) {
        Utils.ListNode fast = listNode.next;
        Utils.ListNode slow = listNode;
        while(listNode != null) {
            if (fast == slow) {
                return true;
            }
            fast = fast.next.next;
            slow = slow.next;
        }

        return  false;
    }



    public static void main(String[] args) {
        int[] array1 = new int[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 6};
        Utils.ListNode list1 = populateList(array1);
        int size = array1.length;

        System.out.print(" Check for loops returned " + detectLoopWithTable(list1) + " for the list ");
        Utils.printList(list1);
        System.out.println("");
        createLoop(list1);
        System.out.print(" Check for loops returned " + detectLoopWithTable(list1) + " for the list ");
        Utils.printList(list1, size);
        System.out.println("");

        System.out.print(" Check for loops returned " + detectLoop(list1) + " for the list ");
        Utils.printList(list1, size);

    }

}
