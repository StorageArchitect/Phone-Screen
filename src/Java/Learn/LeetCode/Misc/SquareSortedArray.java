package LeetCode.Misc;

import java.util.Arrays;
import static PhoneScreen.Utils.*;

/**
 * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in
 * non-decreasing order.
 *
 * This problem can be solved by using the two pointer method.
 *
 * Input: nums = [-4,-1,0,3,10] Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 *
 * @author aahamad
 * @since 22-Dec-2020
 */
public class SquareSortedArray {

    public static int[] sortArrayBrute(int[] inputArray) {
        int[] result = new int[inputArray.length];
        for (int i = 0; i< inputArray.length; i++) {
            result[i] = inputArray[i] * inputArray[i];
        }

        Arrays.sort(result);
        return result;
    }

    public static int[] sortArrayTwoPointer(int[] inputArray) {
        int[] result = new int[inputArray.length];
        int p1 = 0;
        int p2 = inputArray.length - 1;
        int indx = p2;
        //-- the last value is the max, first value is the min.
        // if the value at the max is < than the new value
        while(p1<=p2) {
            //-- note the abs method results in -4 being greater than 3
            if(Math.abs(inputArray[p1]) > inputArray[p2])
            {
                // in case there are negative values, the square of values are placed in the postion
                result[indx--] = inputArray[p1] * inputArray[p1];
                p1++;
            }
            else
            {
                //-- this is the default in a sorted array with positive values.
                result[indx--] = inputArray[p2] * inputArray[p2];
                p2--;
            }
        }
       return result;
    }

    public static void main(String[] args) {

        int[] inputArray =  new int[] { -4,-1,0,3,10};
        //-- this input has some input values that are negative, but in absolute sense they are greater than the positive values.
        //-- the square of a negative number is a positive number.
        System.out.println("sorted squared array brute :" );
        printArray(sortArrayBrute(inputArray));
        System.out.println("sorted squared array two pointer :" );
        printArray(sortArrayTwoPointer(inputArray));

    }
}
