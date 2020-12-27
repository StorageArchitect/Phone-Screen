package Coursera.DivideConqure;


import static PhoneScreen.Utils.*;

/**
 * Binary search works only for a sorted array. If the array is not sorted you'd have to simply use a linear search.
 *
 * Input: A sorted array K = [k0 ,...,kn−1 ] of distinct integers (i.e., k0 < k1 < ··· < kn−1 ) and an integer q.
 * Output: Check whether q occurs in K
 *
 * @author aahamad
 * @since 24-Dec-2020
 */
public class BinarySearch {

    private static int findPositionRec(int[] array, int left, int right, int value) {

        if (right >= left) {
            int mid =  left + (right - left) / 2;
            // If the element is present at the middle
            if (array[mid] == value) {
                return mid;
            }
            // If element is smaller than mid, then it can only be present in left subarray
            if (array[mid] > value) {
                return findPositionRec(array, left, mid - 1, value);
            }
            // Else the element can only be present in right subarray
            return findPositionRec(array, mid + 1, right, value);
        }

        // We reach here when element is not present
        // in array
        return -1;
    }

    private static int findPositionIt(int[] array, int value) {
        int left = 0;
        int right = array.length - 1;
        int mid = 0;
        while(right >= left) {
            mid = left + (right - left) / 2;
            if (array[mid] == value) {
                return mid;
            }
            if (array[mid] > value ) {
               right = mid - 1;
            } else if ( array[mid] < value){
                left = mid + 1;
            }
        }

        return -1;

    }

    public static void main(String[] args) {
        int[] inputArray = {1,3,5,7,13,21,27,31,35,42,47,53};
        int value = 31;
        printArray(inputArray);
        System.out.println( "recurse found value " + value + " at position " + findPositionRec(inputArray, 0, inputArray.length -1, value));
        System.out.println( "iterate found value " + value + " at position " + findPositionIt(inputArray, value));
        inputArray = new int[] {1,3,7,8,9,12,15};
        printArray(inputArray);
        value = 9;
        System.out.println( "recurse found value " + value + " at position " + findPositionRec(inputArray, 0, inputArray.length -1, value));
        System.out.println( "iterate found value " + value + " at position " + findPositionIt(inputArray, value));
        inputArray = new int[] {1,3,7,8,9,12,15};
        printArray(inputArray);
        value = 7;
        System.out.println( "recurse found value " + value + " at position " + findPositionRec(inputArray, 0, inputArray.length - 1, value));
        System.out.println( "iterate found value " + value + " at position " + findPositionIt(inputArray, value));



    }
}
