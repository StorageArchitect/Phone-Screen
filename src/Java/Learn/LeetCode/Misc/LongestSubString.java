package LeetCode.Misc;

import java.util.HashSet;
import java.util.Set;

/**
 * Given a string s, find the length of the longest substring without repeating characters.
 * Input: s = "abcabcbb"
 * Output: 3 Explanation: The answer is "abc", with the length of 3.
 *
 * Input: s = "pwwkew" Output: 3 Explanation: The
 * answer is "wke", with the length of 3. Notice that the answer must be a substring,
 * "pwke" is a subsequence and not a substring.
 *
 * @author aahamad
 * @since 19-Dec-2020
 */
public class LongestSubString {
    /**
     * The idea here is to have a sliding widow.
     * Gobble up the characters at the position and put them in a set.
     * If the character shows up in the map, then break and start again.
     *
     * Below is a O(n^2) solution
     * @param s
     * @return
     */


    public static int lengthOfLongestSubstringBrute(String s) {
        int count = 0;
        int max = 0;
        int length = s.length() -1;
        Set <Character> characterSet = new HashSet <Character>();
        for (int j = 0; j < length; j++) {
            for(int i = j; i < s.length() -1; i++) {
                if(!characterSet.contains(s.charAt(i))) {
                    count++;
                    characterSet.add(s.charAt(i));
                } else {
                    if (count > max ) {
                        max = count;
                    }
                    count = 0;
                    characterSet.clear();
                }
            }
        }

        return max;
    }

    /**
     * The idea here is to use a sliding window
     * We use HashSet to store the characters in current window [i,j)[i,j)[i,j) (j=ij = ij=i initially).
     * Then we slide the index j to the right. If it is not in the HashSet, we slide j further
     * Doing so until s[j] is already in the HashSet. At this point, we found the maximum size of
     * substrings without duplicate characters start with index i.
     * If we do this for all i, we get our answer.
     *
     * @param s
     * @return
     */
    public static int lengthOfLongestSubString(String s) {
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range [i, j]
            if (!set.contains(s.charAt(j))){
                set.add(s.charAt(j++));
                ans = Math.max(ans, j - i);
            }
            else {
                set.remove(s.charAt(i++));
            }
        }
        return ans;
    }


    public static void main(String[] args) {
     String testStr1 = "abcabcbb";
     String testStr2 = "pwwkew";
     System.out.println(testStr1 + " Bruteforce substring length " +  lengthOfLongestSubstringBrute(testStr1));
     System.out.println(testStr2 + " Bruteforce substring length " +  lengthOfLongestSubString(testStr2));

    }
}
