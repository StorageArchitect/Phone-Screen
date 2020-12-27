package LeetCode.Misc;
import static PhoneScreen.Utils.*;

/**
 * Given an array of positive numbers and a positive number ‘k,’ find the maximum sum of any contiguous subarray of size ‘k’.
 *
 * @author aahamad
 * @since 21-Dec-2020
 */
public class MaxSubArraySum {

    public static int[] subArrayWithMaxSum (int[] array, int window) {
        int maxSum = 0;
        int sum = 0;
        int[] result = new int[window];
        for(int i = 0, j = 0; i < array.length; i++) {
            sum += array[i];
            if ( i - (j + window - 1) == 0 ) {
                if (sum > maxSum) {
                    maxSum = sum;
                    for (int k = 0; k < window; k++) {
                        result[k] = array[j+k];
                    }
                }
                //-- remove the previous element in the window
               sum -= array[j++];

            }

        }

        return result;
    }

    public static int[] subArrayWithMaxSumLeetCode (int[] array, int window) {
        int maxSum = 0;
        int sum = 0;
        int[] result = new int[window];
        for(int i = 0, j = 0; i < array.length; i++) {
            sum += array[i];
            if ( i > window - 1) {
                if (sum > maxSum) {
                    maxSum = sum;
                    for (int k = 0; k < window; k++) {
                        result[k] = array[j+k];
                    }
                }
                //-- remove the previous element in the window
                sum -= array[j++];

            }

        }

        return result;
    }


    public static void main(String[] args) {
        int[] array1 = {2,7,11,15,1,15,5,3,9,8,20};
        int[] array2 = {2, 1, 5, 1, 3, 2};
        int subArraySize = 3;
        int[] result = subArrayWithMaxSum(array1, subArraySize);
        printArray(array1);
        System.out.println(" The sum of sub array of size " + subArraySize + " is ");
        printArray(result);
        result = subArrayWithMaxSum(array2, subArraySize);
        printArray(array2);
        System.out.println(" The sum of sub array of size " + subArraySize + " is ");
        printArray(result);

        //-- leet code solution
        result = subArrayWithMaxSumLeetCode(array1, subArraySize);
        printArray(array1);
        System.out.println(" The LeetCode sum of sub array of size " + subArraySize + " is ");
        printArray(result);
        result = subArrayWithMaxSumLeetCode(array2, subArraySize);
        printArray(array2);
        System.out.println(" The LeetCode sum of sub array of size " + subArraySize + " is ");
        printArray(result);


    }
}
