package LeetCode;

/**
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid palindrome.
 *
 * Things to watch out for, there are some tricky items that need to be careful about.
 * Read the problem correctly, take a look at the input and proceed. In this case the
 * use of a regex helped clean up the string.
 * A-Za-z0-9 are considered as alpha numeric
 *
 * @author aahamad
 * @since 20-Dec-2020
 */
public class ValidPalindrome {

    public static boolean isPalindrome(String s) {
        String sanatized = s.replaceAll("[^A-Za-z0-9]", "");

        StringBuilder input = new StringBuilder(sanatized);
        String reversed = input.reverse().toString();
        if (reversed.equalsIgnoreCase(sanatized)) {
            return true;
        }
        return false;
    }





    public static void main(String[] args) {
        String str1 = "A man, a plan, a canal: Panama";
        String str2 = "aaa";
        String str3 = "ccabb";
        String str4 = "malayalam";
        System.out.println( str1 + ( isPalindrome(str1) == true ?  " is a valid palindrome" :  " is not a valid palindrome ")) ;
        System.out.println( str2 + ( isPalindrome(str2) == true ?  " is a valid palindrome" :  " is not a valid palindrome ")) ;
        System.out.println( str3 + ( isPalindrome(str3) == true ?  " is a valid palindrome" :  " is not a valid palindrome ")) ;
        System.out.println( str4 + ( isPalindrome(str4) == true ?  " is a valid palindrome" :  " is not a valid palindrome ")) ;



    }
}
