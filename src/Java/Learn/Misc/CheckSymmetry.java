package Misc;

//Check whether a string is symmetric, like abccba, or abcba.
//-- same as palindrome
public class CheckSymmetry {

   public static boolean isSymmetric(String s ) {
       for(int i = 0, j = s.length()-1; i < s.length()/2 && j > 0; i++, j--){
           if(s.charAt(i) != s.charAt(j)){
               return false;
           }
       }
        return true;
    }

    public static void main(String[] args) {
        String s1 = "abccba";
        String s2 = "abcba";
        String s3 = "abia";
        System.out.println("The string " + s1 + " is symmetric " + isSymmetric(s1));
        System.out.println("The string " + s2 + " is symmetric " + isSymmetric(s2));
        System.out.println("The string " + s3 + " is symmetric " + isSymmetric(s3));

    }
}
