package LeetCode;

import java.util.HashMap;
import java.util.Map;

import static java.lang.Math.abs;

/**
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * You can return the answer in any order.
 *
 * So we assume positive numbers ?
 *
 * @author aahamad
 * @since 19-Dec-2020
 */
public class TwoSum {

    public static int [] sumTwoPassIndex(int[] nums, int sum) {

        int[] index;

        Map <Integer, Integer> map = new HashMap <>();
        for (int i = 0; i < nums.length; i++) {
            int refVal = abs(nums[i] - sum);
            map.put(refVal,i);
        }
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                return new int[] {map.get(nums[i]), map.get(abs(nums[i] - sum))};
               }
        }

        throw new IllegalArgumentException("No two sum solution");
    }

    public static int [] sumOnePassIndex(int[] nums, int target) {

        Map <Integer, Integer> map = new HashMap <>();
        for (int i = 0; i < nums.length; i++) {
            int val = target - nums[i];
            int complement = val > 0 ? val : val * -1;
            if (map.containsKey(complement)) {
                return new int[] {i, map.get(complement)};
            }
            map.put(nums[i], i);
        }

        throw new IllegalArgumentException("No two sum solution");
    }

    public static int[] sumLeetCode(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }

    public static void main(String[] args) {
        int[] array = {2,7,11,15};
        int sum = 9;
        int[] result = sumTwoPassIndex(array, sum);
        System.out.println("Two pass Result index " + result[0] + " " + result[1]);
        result = sumOnePassIndex(array, sum);
        System.out.println("One Pass Result index " + result[0] + " " + result[1]);
        result = sumLeetCode(array, sum);
        System.out.println("Leet Code Result index " + result[0] + " " + result[1]);

    }
}
