package Misc;

/**
 * Given two integers A and B, return any string S such that:
 *
 * <p>S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
 * The substring 'aaa' does not occur in S;
 * The substring 'bbb' does not occur in S.
 *
 * <p>Example 1: Input: A = 1, B = 2 Output: "abb" Explanation: "abb", "bab" and "bba" are all correct answers.
 *
 * <p>Example 2: Input: A = 4, B = 1 Output: "aabaa"
 *
 * <p>Note: 1. 0 <= A <= 100
 * 2. 0 <= B <= 100
 * 3. It is guaranteed such an S exists for the given A and B.
 *
 * @author aahamad
 * @since 12-Dec-2020
 */
public class CharSequence {
    private static String strWithout3a3b(int A, int B) {

        StringBuilder res = new StringBuilder();
        // a 代表字母个数较多的字母； b 代表字母个数较少的字母；
        char a = 'a', b = 'b';
        // countA 代表字母数较多的元素的个数； countB 代表字字母数较少的元素的个数
        int countA = A, countB = B;
        if (B > A) {
            countA = B;
            countB = A;
            a = 'b';
            b = 'a';
        }
        //-- guaranteed that countA >= countB

        if ( (countA / 2.0 ) - 1 > countB ) {
            return null;
        }

        while (countA > 0 || countB > 0) {
            if (countA > 0) {
                res.append(a);
                countA--;
            }
            if (countA > countB) {
                res.append(a);
                countA--;
            }
            if (countB > 0) {
                res.append(b);
                countB--;
            }
        }

        return res.toString();
    }

  public static void main(String[] args) {
        int a = 2, b = 7;
      String result = strWithout3a3b(a,b);
      if (result != null) {
          System.out.println( " solution for A = " + a  + " B = " + b + " is " + result);
      } else {
          System.out.println( " solution for A = " + a  + " B = " + b + " is invalid input");
      }
    }
}
