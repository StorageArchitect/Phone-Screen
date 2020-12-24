package LeetCode.misc;

import static LeetCode.misc.MergeTwoSortedArrays.printArray;

/**
 * Given an array, find the sum of subarrays of size ‘K’ in it.
 * Given an array, find the sum of all contiguous subarrays of size ‘K’ in it.
 * This problem demonstrates the sliding window algorithm.
 *  As with arrays always pay attention to the index to avoid overflow exceptions.
 *
 * @author aahamad
 * @since 21-Dec-2020
 */
public class CalcNSumOfSubArray {

    /**
     * Calculate the sum of the subarray.
     * @param array
     * @param window
     * @return
     */
    public static int[] calculateSubArraySum(int[] array, int window) {
        int size = array.length;
        int[] result = new int[size / window + 1];
        if (size < window) {
            throw new IllegalArgumentException("No two sum solution");
        }
        for (int i =0, j=0; i < size; i++) {
            if (i != 0 & i % window == 0) {
                result[++j] += array[i];
            } else {
                result[j] += array[i];
            }

        }
            return result;
    }



    /**
     * Calculate the sum of  all contiguous subarrays brute force.
     *
     * @param array
     * @param window
     * @return
     */
    public static int[] calculateContiguousSubArraySumBrute(int[] array, int window) {
        int size = array.length;
        int[] result = new int[size - window + 1];
        if (size < window) {
            throw new IllegalArgumentException("No two sum solution");
        }
        for (int i =0, r = 0; i <= size - window; i++) {
            for (int j = i; j < i + window; j++) {
                result[r] += array[j];
            }
            r++;
        }
        return result;
    }

    /**
     * Calculate the sum of  all contiguous subarrays optimized.
     *
     * @param array
     * @param window
     * @return
     */
    public static int[] calculateContiguousSubArraySum(int[] array, int window) {
        int size = array.length;
        int[] result = new int[size - window + 1];
        if (size < window) {
            throw new IllegalArgumentException("No two sum solution");
        }
        int windowSum = 0;
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < array.length; windowEnd++) {
            windowSum += array[windowEnd]; // add the next element
            // slide the window, we don't need to slide if we've not hit the required window size
            if (windowEnd >= window - 1) {
                result[windowStart] = windowSum;  // calculate the average
                windowSum -= array[windowStart]; // subtract the element going out
                windowStart++; // slide the window ahead
            }
        }
        return result;
    }

    /**
     * Calculate the average of all contiguous subarrays optimized.
     * The average will be an double
     *
     * @param array
     * @param window
     * @return
     */
    public static double [] calculateContiguousSubArrayAvg(int[] array, int window) {
        int size = array.length;
        //-- better to be double
        double[] result = new double[size - window + 1];
        if (size < window) {
            throw new IllegalArgumentException("No two sum solution");
        }
        double windowSum = 0;
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < array.length; windowEnd++) {
            windowSum += array[windowEnd]; // add the next element
            // slide the window, we don't need to slide if we've not hit the required window size
            if (windowEnd >= window - 1) {
                result[windowStart] = windowSum/(double) window;  // calculate the average
                windowSum -= array[windowStart]; // subtract the element going out
                windowStart++; // slide the window ahead
            }
        }
        return result;
    }



    public static void main(String[] args) {
        int[] array = {2,7,11,15,1,-3,15,5,3,9,8,20};
        int subSize = 3;
        int[] result = calculateSubArraySum(array, subSize);
        printArray(array);
        System.out.println(" The sum of sub array of size " + subSize + " is ");
        printArray(result);
        result = calculateContiguousSubArraySumBrute(array,subSize);
        System.out.println(" The sum of Contiguous sub array of size brute " + subSize + " is ");
        printArray(result);
        result = calculateContiguousSubArraySum(array,subSize);
        System.out.println(" The sum of Contiguous sub array of size optimized " + subSize + " is ");
        printArray(result);
        double[] avg = calculateContiguousSubArrayAvg(array,subSize);
        System.out.println(" The average of Contiguous sub array of size optimized " + subSize + " is ");
        printArray(avg);


    }
}
