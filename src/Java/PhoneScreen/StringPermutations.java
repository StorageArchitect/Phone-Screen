package PhoneScreen;

public class StringPermutations {
  //-- permutation is not power set, you have to hold one constant and permute the rest
   /**
     * permutation function
     * @param str string to calculate permutation for
     * @param l starting index
     * @param r end index
     */
    public static void printPermutations(String str, int l, int r)
    {
        if (l == r)
            System.out.println(str);
        else
        {
            for (int i = l; i <= r; i++)
            {
                str = swap(str,l, i);
                printPermutations(str, l+1, r);
                //-- backtrack
                str = swap(str,l,i);
            }
        }
    }

    /**
     * Swap Characters at position
     * @param a string value
     * @param i position 1
     * @param j position 2
     * @return swapped string
     */
    public static String swap(String a, int i, int j)
    {
        char temp;
        char[] charArray = a.toCharArray();
        temp = charArray[i] ;
        charArray[i] = charArray[j];
        charArray[j] = temp;
        return String.valueOf(charArray);
    }




    public static void main(String[] args)
    {
        String myString = "abcd";
        System.out.println("Calculate all permutations of string" + myString );
        printPermutations(myString, 0, myString.length()-1);
    }
}
