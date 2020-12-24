package Misc;
/**
 * Euclids algrithm for find the GCD.
 *
 * @author aahamad
 * @since 22-Dec-2020
 */
public class GCDFinder {



    /**
     * Step 1. Make an euclidean division of the largest of the 2 numbers A by the other one B, to find a dividend D and
     * a remainder R. Keep the numbers B and R.
     *
     * Step 2. Repeat step 1 (with numbers kept, B becomes the new A and R becomes the new B) until the remainder is
     * zero.
     *
     * Step 3. GCD of A and B is equal to the last non zero remainder.
     *
     * @param a, b
     *
     *
     *
     */

    private static long euclidsCalculation(long a, long b) {
        if (a == 0) {
            return b;
        }
        return euclidsCalculation(b%a, a);
    }

    /**
     *
     * @param a
     * @param b
     * @param x
     * @param y
     * @return
     */

    public static int gcdExtended(int a, int b, int x, int y)
    {
        // Base Case
        if (a == 0)
        {
            x = 0;
            y = 1;
            return b;
        }

        int x1=1, y1=1; // To store results of recursive call
        int gcd = gcdExtended(b%a, a, x1, y1);

        // Update x and y using results of recursive
        // call
        x = y1 - (b/a) * x1;
        y = x1;

        return gcd;
    }

    public static void main(String[] args) {
        long b = 1024l;
        long a = 8192l;
        //- correct algorithm should return 3
        System.out.println("find the GCD of " + a + " and " + b);
        long result = euclidsCalculation(a, b);
        System.out.println("Euclids calculator results " + result);
        }
}
