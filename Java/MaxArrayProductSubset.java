package PhoneScreen;

public class MaxArrayProductSubset {
    //https://www.geeksforgeeks.org/maximum-product-subarray-set-3/
    //-- the idea is that these numbers must be consequetive ..
    static long maxProductSubset(int[] arr){

        // Variables to store maximum and minimum
        // product till ith index.
        int minVal = arr[0];
        int maxVal = arr[0];
        int n = arr.length;

        int maxProduct = arr[0];

        for (int i = 1; i < n; i++)
        {

            // When multiplied by -ve number,
            // maxVal becomes minVal
            // and minVal becomes maxVal.
            if (arr[i] < 0)
            {
                int temp = maxVal;
                maxVal = minVal;
                minVal =temp;

            }

            // maxVal and minVal stores the
            // product of subarray ending at arr[i].
            maxVal = Math.max(arr[i], maxVal * arr[i]);
            minVal = Math.min(arr[i], minVal * arr[i]);

            // Max Product of array.
            maxProduct = Math.max(maxProduct, maxVal);
        }

        // Return maximum product found in array.
        return maxProduct;
    }

    public static void main(String[] args) {
        int[] array = new int[]  {60, -3, -100, 0, 2, 30,40};

        System.out.println("Max product of sub array elements " + maxProductSubset(array));
    }
}
