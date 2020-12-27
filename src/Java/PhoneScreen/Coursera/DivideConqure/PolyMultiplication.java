package Coursera.DivideConqure;

import java.math.BigInteger;

import static PhoneScreen.Utils.*;

/**
 * implement an algorithm to multiply coefficients.
 * The naive algorithm is straight forward works out to be n^2
 * The most efficient algorithms is the Karatsuba algorithmworks out to be n ^log3 or n^1.58
 *
 * @author aahamad
 * @since 25-Dec-2020
 */
public class PolyMultiplication {

    private static int[] polyMultiplyIt(int[][] inputArray) {
        int[] a = inputArray[0];
        int[] b = inputArray[1];
        int[] result = new int[  a.length + b.length - 1];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b.length; j++) {
                result[i+j] += a[i] * b[j]  ;
            }
        }

        return result;
    }

    private static int[] polyMultiplyRec(int[][] inputArray) {
        int[] a = inputArray[0];
        int[] b = inputArray[1];
        int[] result = new int[  a.length + b.length - 1];

        return result;
    }



    private static int getSize(BigInteger num) {
        return String.valueOf(num).length();
    }

    /**
     * Let x and y be represented as n digit strings in some base B. For any positive integer m less than n one can
     * write the two given numbers as
     *
     * x = x1*B^m + x0 , y = y1*B^m + y0
     *
     * where x0 and y0 are less than B^m. The product is then
     *
     * x*y = ( x1*B^m + x0 ) ( y1B^m + y0 )
     * = z2*B^2m + z1*Bm + z0
     * where
     * z2 = x1*y1;
     * z1 = x1*y0 + x0*y1;
     * z0 = x0*y0
     *
     * These formulae require four multiplications and were known to Charles Babbage.[4]
     *
     * Karatsuba observed that x*y can be computed in only three multiplications, at the cost of a few extra additions.
     * With z0 and z2 as before
     *
     * z1 = ( x1 + x0 ) ( y1 + y0 ) − z2 − z0
     *
     * An issue that occurs, however, when computing z1 is that the above computation of ( x1 + x0 ) and ( y1 + y0 )*
     * may result in overflow (will produce a result in the range B^m ≤ result < 2*B^m , which require a multiplier
     * having one extra bit. This can be avoided by noting that
     *
     * z1 = ( x0 − x1 ) ( y1 − y0 ) + z2 + z0.
     *
     * This computation of ( x0 − x1 ) and ( y1 − y0) will produce a result in the range of −B^m < result < B^m This
     * method may produce negative numbers, which require one extra bit to encode signedness, and would still require
     * one extra bit for the multiplier.
     *
     * However, one way to avoid this is to record the sign and then use the absolute value of ( x0 − x1 ) and ( y1 −
     * y0) to perform an unsigned multiplication, after which the result may be negated when both signs originally
     * differed.
     *
     * Another advantage is that even though ( x0 − x1) ( y1 − y0 ) may be negative, the final computation of z1 only
     * involves additions.
     *
     * Example:
     *
     * To compute the product of 12345 and 6789, where B = 10, choose m = 3. We use m right shifts for decomposing
     * the input operands using the resulting base (B^m = 1000), as:
     *
     * 12345 = 12 * 1000 + 345;
     * 6789 = 6 * 1000 + 789
     *
     * Only three multiplications, which operate on smaller integers, are used to compute three partial results:
     *
     * z2 = 12 × 6 = 72;
     * z0 = 345 × 789 = 272205;
     * z1 = (12 + 345) × (6 + 789) − z2 − z0 = 357 × 795 − 72 − 272205  = 283815 − 72 − 272205 = 11538;
     *
     * We get the result by just adding these three partial results, shifted accordingly (and then taking carries
     * into account by decomposing these three inputs in base 1000 like for the input operands):
     *
     * putting all this together in the form result = z2 · (B^m)^2 + z1*(B^m)^1 + z0 * (B^m)^0, we get the result
     *
     * result = 72 * 1000^2 + 11538 * 1000 + 272205 = 83810205.
     *
     * Note that the intermediate third multiplication operates on an input domain which is less than two times
     * larger than for the two first multiplications, its output domain is less than four times larger, and base-1000
     * carries computed from the first two multiplications must be taken into account when computing these two
     * subtractions.
     *
     * @param num1
     * @param num2
     * @return
     */
    public static BigInteger karatsuba1(BigInteger num1, BigInteger num2) {

        int m = Math.max(
                getSize(num1), getSize(num2));

        if (m < 2) {
            return num1.multiply(num2);
        }
        // -- number of bits rounded up
        m = (m / 2) + (m % 2);
        BigInteger b = num1.shiftRight(m);
        BigInteger d = num2.shiftRight(m);
        BigInteger a = num1.subtract(b.shiftLeft(m));
        BigInteger c = num2.subtract(d.shiftLeft(m));

        BigInteger ac = karatsuba(a, c);
        BigInteger bd = karatsuba(b, d);
        BigInteger abcd = karatsuba(a.add(b), c.add(d));

        return ac.add(abcd.subtract(ac).subtract(bd).shiftLeft(m)).add(bd.shiftLeft(2*m));
    }


    public static BigInteger karatsuba(BigInteger x, BigInteger y) {

        // cutoff to brute force
        int N = Math.max(
                getSize(x), getSize(y));
        if (N < 2) return x.multiply(y);        // optimize N

        // number of bits divided by 2, rounded up
        N = (N / 2) + (N % 2);

        // x = a + 2^N b,   y = c + 2^N d
        BigInteger b = x.shiftRight(N);
        BigInteger d = y.shiftRight(N);
        BigInteger a = x.subtract(b.shiftLeft(N));
        BigInteger c = y.subtract(d.shiftLeft(N));

        // compute sub-expressions
        BigInteger ac    = karatsuba(a, c);
        BigInteger bd    = karatsuba(b, d);
        // compute (a+b) (c+d)
        BigInteger abcd  = karatsuba(a.add(b), c.add(d));
        // result is of the form z2 * (B^m)^2 + z1*(B^m)^1 + z0 * (B^m)^0,
        // where
        // z2*(B^m)^2 is ac
        // z0 = bd
        // z1 = abcd - z2 - z0(B^N)

        // ac + abcd - ac - bd*B^N + bd * B^2N
        return ac.add(abcd.subtract(ac).subtract(bd).shiftLeft(N)).add(bd.shiftLeft(2*N));
    }


    public static void main(String[] args) {
      int[][] inputArray ={{1, 3}, {5,7}};
      System.out.println(" Polynimial multiplication results " );
      printArray(polyMultiplyIt(inputArray));
      long a = 1234567890l;
      long b = 9876543210l;
      System.out.println(" The product of " + a + " * " + b  + " is  " + BigInteger.valueOf(a).multiply(BigInteger.valueOf(b)));

      System.out.println(" Karustaba recursive algorithm " +  a + "x" + b + " is " + karatsuba1(BigInteger.valueOf(a), BigInteger.valueOf(b)));

        System.out.println(" Karustaba recursive algorithm " +  a + "x" + b + " is " + karatsuba(BigInteger.valueOf(a), BigInteger.valueOf(b)));
    }

}
