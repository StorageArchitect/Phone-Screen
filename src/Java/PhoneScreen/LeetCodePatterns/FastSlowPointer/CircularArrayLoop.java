package LeetCodePatterns.FastSlowPointer;

import static PhoneScreen.Utils.*;

/**
 * You are given a circular array nums of positive and negative integers. If a number k at an index is positive, then
 * move forward k steps. Conversely, if it's negative (-k), move backward k steps. Since the array is circular, you may
 * assume that the last element's next element is the first element, and the first element's previous element is the
 * last element.
 *
 * Determine if there is a loop (or a cycle) in nums. A cycle must start and end at the same index and the cycle's
 * length > 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not
 * consist of both forward and backward movements.
 * https://medium.com/@mithlesh.kumar.4257/leetcode-457-circular-array-loop-fdcec9ea5746
 * https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_Tortoise_and_Hare
 *
 * @author aahamad
 * @since 26-Dec-2020
 */
public class CircularArrayLoop {

    private static boolean circularArrayLoop(int[] nums) {

        return false;

    }

    public static void main(String[] args) {
        int[] circularArray = {2, -1, 1,2,2};
        int[] array1 = {-1,2};
        int[] array2 = {-2,1,-1,-2,-2};

        System.out.println(" Check for loop returned " + circularArrayLoop(circularArray) + " for array");
        printArray(circularArray);
        System.out.println(" Check for loop returned " + circularArrayLoop(array1) + " for array");
        printArray(array1);
        System.out.println(" Check for loop returned " + circularArrayLoop(array2) + " for array");
        printArray(array2);

    }
}
