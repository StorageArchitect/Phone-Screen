package PhoneScreen;

import java.util.HashMap;
import java.util.Map;

/**
 * Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum
 * equals to k.
 *
 * <p>Example 1: Input:nums = [1,1,1], k = 2 Output: 2
 *
 * <p>Note: The length of the array is in range [1, 20,000]. The range of numbers in the array is [-1000, 1000] and the
 * range of the integer k is [-1e7, 1e7].
 *
 * @author aahamad
 * @since 12-Dec-2020
 */
public class ArraySum {

    //-- return the number of continuous sub arrays
    public static int subArraySum(int[] nums, int sum) {
        int result = 0;
        int index = 0;
        int[] subArrays = twosum(nums, sum);
        //-- now walk through the sub array to see which pair is adjacent.
        while(index < subArrays.length -1) {
            if ((subArrays[index] + 1 == subArrays[index + 1]) || (subArrays[index] - 1 == subArrays[index + 1])) {
                result++;
            }
            index +=2;
        }

        return  result;
    }

    //-- return the position of two values that sum up to given number
    public static int[] twosum(int[] nums, int sum) {
        if (nums == null || nums.length == 0) {
            int[] fail = {-1, -1};
            return fail;
        }
        int[] result = new int[2 * nums.length];
        Map <Integer, Integer> map =  new HashMap <>();
        //-- calculate the complement
        for (int i = 0, j = 0; i < nums.length; i++) {
            int complement = sum - nums[i];
            if (map.containsKey(complement)) {
                result[j++] = i;
                result[j++] = map.get(complement);
            }
           map.put(nums[i], i);
        }
        return result;
    }

    //-- this is incorrect
    public static int altSubarraySum(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return -1;
        }

        Map <Integer, Integer> map = new HashMap <>();
        // Initailize the values
        map.put(0, 1);  // very important
        int preSum = 0;
        int count = 0;

        for (int i = 0; i < nums.length; i++) {
            preSum += nums[i];
            if (map.containsKey(preSum - k)) {
                count += map.get(preSum - k);
            }
            map.put(preSum, map.getOrDefault(preSum, 0) + 1);
        }

        return count;
    }

    public static void main(String[] args) {
        int arr[] = {1,0,1,1};
        int sum = 2;
        int[] result = twosum(arr, sum);
        System.out.println(" two sum result: ");
        for (int i = 0; i < result.length; i++) {
            System.out.print( result[i] + " ,");
        }
        System.out.println(" number of sub arrays with desired sum of " + sum + " are " +   subArraySum(arr, sum));
        System.out.println(" *incorrect* Alt number of sub arrays with desired sum of " + sum + " are " +   altSubarraySum(arr, sum));

    }
}
