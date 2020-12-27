package LeetCode.Misc;

/**
 * Given a string s, return the longest palindromic substring in s.
 * Best approach is the manacher's algorithm.
 * Acceptable solution is O(n^2)  index and find the midpoint
 * Brute force method of walking each substring and checking for palindrome is O(n^3)
 *
 * @author aahamad
 * @since 19-Dec-2020
 */
public class LongestPalindromicSubString {


    /**
     * Use a sliding window to slice the string
     * Check the string in the sliding window to be a palindrome or not.
     * @param s
     * @return
     */
    public static String longestPalindromeBrute(String s) {
        int n = s.length();
        int max = 0;
        String maxString = s;
        //-- handle special cases
        for (int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                String subString = s.substring(i,j+1);
                if (isPali(subString)) {
                    int size = j + 1 - i;
                    if ( max < size) {
                        maxString = subString;
                        max = size;
                    }
                }
            }
        }


        return maxString;

    }

    /**
     *
     * palindrome check
     * @param s
     * @return
     */
    private static Boolean isPali(String s) {
       int n = s.length();
        // special case
       if (n == 1) {
           return true;
       } else if ( n == 2 ) {
          return s.charAt(0) == s.charAt(1);
       }

        for (int i = 0; i < (n/2); ++i) {
            if (s.charAt(i) != s.charAt(n - i - 1)) {
                return false;
            }
        }

        return true;
    }

    /**
     * In fact, we could solve it in O(n2)O(n^2)O(n2) time using only constant space.
     *
     * <p>We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its
     * center, and there are only 2n−1 such centers.
     *
     * <p>You might be asking why there are 2n−1 but not nnn centers? The reason is the center of a palindrome
     * can be in between two letters. Such palindromes have even number of letters (such as "abba") and its center are
     * between the two 'b's.
     *
     * @param s
     * @return
     */
    public static String longestPalindromeLeetCode(String s) {
        if (s == null || s.length() < 1) return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = Math.max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substring(start, end + 1);
    }

    private static int expandAroundCenter(String s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
            L--;
            R++;
        }
        return R - L - 1;
    }


    public static void main(String[] args) {
        String str1 = "abbabaderbab";
        String str2 = "a";
        String str3 = "bb";
        String str4 = "bc";
        String str5 = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"         +
                "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" +
                "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" +
                "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" +
                "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" +
                "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" +
                "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" +
                "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" +
                "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" +
                "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        System.out.println("The longest palindromic substring of " + str1 + " is " + longestPalindromeBrute(str1));
        System.out.println("The longest palindromic substring of " + str2 + " is " + longestPalindromeBrute(str2));
        System.out.println("The longest palindromic substring of " + str3 + " is " + longestPalindromeBrute(str3));
        System.out.println("The longest palindromic substring of " + str4 + " is " + longestPalindromeBrute(str4));
        System.out.println("The longest palindromic substring of " + str5 + " is " + longestPalindromeBrute(str5));
        //-- leet code solution
        System.out.println("The longest palindromic substring of " + str1 + " is " + longestPalindromeLeetCode(str1));
        System.out.println("The longest palindromic substring of " + str2 + " is " + longestPalindromeLeetCode(str2));
        System.out.println("The longest palindromic substring of " + str3 + " is " + longestPalindromeLeetCode(str3));
        System.out.println("The longest palindromic substring of " + str4 + " is " + longestPalindromeLeetCode(str4));
        System.out.println("The longest palindromic substring of " + str5 + " is " + longestPalindromeLeetCode(str5));


    }


    /**
     * Palindrome check with reverse. This gives you an incorrect answer.
     * @param s
     * @return
     */

    private static Boolean palindromeCheck(String s) {
        int n = s.length();
        // special case
        if (n == 1) {
            return true;
        } else if ( n == 2 ) {
            return s.charAt(0) == s.charAt(1);
        }
        StringBuilder reverse = new StringBuilder(s);

        reverse = reverse.reverse();
        if (reverse.equals(s)) {
            return true;
        }
        return false;
    }
}
