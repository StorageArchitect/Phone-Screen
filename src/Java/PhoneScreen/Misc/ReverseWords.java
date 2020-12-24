package Misc;

public class ReverseWords {
    static char swapMe(char a, char b){
         return a;
    }
    static void reverseStringfn(String s){
        //-- strings are immutable
        StringBuilder s1 = new StringBuilder(s);
        for(int i = 0, j = s.length() -1 ; i < s.length()/2; i++, j--){
            char a = s1.charAt(i);
            char b = s1.charAt(j);
            b = swapMe(a,  a= b );
            s1.setCharAt(i,a);
            s1.setCharAt(j,b);
         }
         System.out.println("Reversed string " + s1.toString());
    }

    static void reverseString(String s){
        //-- strings are immutable
        StringBuilder s1 = new StringBuilder(s);
        for(int i = 0, j = s.length() -1 ; i < s.length()/2; i++, j--){
            char a = s1.charAt(i);
            char b = s1.charAt(j);
            s1.setCharAt(i,b);
            s1.setCharAt(j,a);
        }
        System.out.println("Reversed string " + s1.toString());
    }


    public static void main(String[] args) {
        String s1 = "reverse me please!";
        System.out.println("Reverse words in a string");
        reverseStringfn(s1);
        reverseString(s1);

    }
}
