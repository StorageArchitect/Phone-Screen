package PhoneScreen;

public class MaxArraySumSubset {
    //-- https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

    static long maxSumSubset(int[] arr){
        int size = arr.length;
        int max_so_far = Integer.MIN_VALUE, max_ending_here = 0;

        for (int i = 0; i < size; i++)
        {
            max_ending_here = max_ending_here + arr[i];
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return max_so_far;
    }

    public static void main(String[] args) {
        int[] array = new int[]  {60, -3, -100, 0, 2, 30,40};

        System.out.println("Max product of sub array elements " + maxSumSubset(array));
    }
}
