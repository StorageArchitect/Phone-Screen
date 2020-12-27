package Misc;
//-- determine if two strings are anagrams
//-- a approach would be to create a hash table
//-- put the the original string into the table
// iterate the next string and check if the char exists or not.

import java.util.HashMap;
import java.util.Hashtable;

public class Anagrams {

    static void isAnagram(String s1, String s2) {
        int cArray[] = new int[256];
        if(s1.length() != s1.length()){
            System.out.println(" String " + s1 + "String " + s2 + " are not anagrams");
            return;
        }

        for(int i= 0; i < s1.length(); i++){
            cArray[s1.charAt(i)] +=1;
        }

        for(int i= 0; i < s2.length(); i++){
            cArray[s2.charAt(i)] -=1;
            if(cArray[s2.charAt(i)] < 0){
                System.out.println(" String " + s1 + "String " + s2 + " are not anagrams");
                return;
            }
        }

        System.out.println(" String " + s1 + " String " + s2 + " are  anagrams");
    }


    static void isAnagramHashTable(String s1, String s2) {
        /**
         * Hashtable is basically a data structure to retain values of key-value pair.
         * It does not allow null for both key and value. It will throw NullPointerException.
         * Hashtable does not maintain insertion order. The order is defined by the Hash function.
         * So only use this if you do not need data in order.
         * It is synchronized. It is slow. Only one thread can access in one time.
         * HashTable rea thread safe.
         * HashTable uses Enumerator to iterate through elements.
         */
        Hashtable<Character, Integer> table = new Hashtable<>(256);
        if(s1.length() != s1.length()){
            System.out.println(" String " + s1 + " String " + s2 + " are not anagrams");
            return;
        }

        for(int i= 0; i < s1.length(); i++){
            int value = 0;
            if(table.containsKey(s1.charAt(i))) {
                value = table.get(s1.charAt(i));
            }
            table.put(s1.charAt(i), value +1);
        }

        for(int i= 0; i < s2.length(); i++){
            int value = 0;
            if(table.containsKey(s2.charAt(i))){
                value = table.get(s2.charAt(i));
            } else {
                System.out.println(" String " + s1 + " String " + s2 + " are not anagrams");
                return;
            }
            table.put(s2.charAt(i), value - 1);
            if(table.get(s2.charAt(i))  < 0){
                System.out.println(" String " + s1 + " String " + s2 + " are not anagrams");
                return;
            }
        }

        System.out.println(" String " + s1 + " String " + s2 + " are  anagrams");
    }

    static void isAnagramHashMap(String s1, String s2) {
        HashMap<Character, Integer> map = new HashMap<>(256);
        /****
         * Like Hashtable , HashMap also accepts key value pair.
         * It allows null for both key and value.
         * HashMap does not maintain insertion order. The order is defined by the Hash function.
         * It is not synchronized. It will have better performance.
         * HashMap are not thread safe, but you can use Collections.synchronizedMap(new HashMap<K,V>())
         */
        if (s1.length() != s2.length()) {
            System.out.println(" String " + s1 + " String " + s2 + " are not anagrams");
            return;
        }

        for(int i= 0; i < s1.length(); i++){
            int value = 0;
            if(map.containsKey(s1.charAt(i))) {
                value = map.get(s1.charAt(i));
            }
            map.put(s1.charAt(i), value +1);
        }

        for(int i= 0; i < s2.length(); i++){
            int value = 0;
            if(map.containsKey(s2.charAt(i))){
                value = map.get(s2.charAt(i));
            } else {
                System.out.println(" String " + s1 + " String " + s2 + " are not anagrams");
                return;
            }
            map.put(s2.charAt(i), value - 1);
            if(map.get(s2.charAt(i))  < 0){
                System.out.println(" String " + s1 + " String " + s2 + " are not anagrams");
                return;
            }
        }

        System.out.println(" String " + s1 + " String " + s2 + " are  anagrams");

    }
    public static void main(String[] args) {
        String s1 = "anagram";
        String s2 = "mnagraa";
        String s3 = "ammagra";
        System.out.println("Check if String  " + s1 + " is anagram of " + s2 );
        isAnagram(s1, s2);
        isAnagramHashTable(s1, s2);
        isAnagramHashMap(s1, s2);
        System.out.println();
        System.out.println("Check if String  " + s3 + " is anagram of " + s2 );
        isAnagram(s3, s2);
        isAnagramHashTable(s3, s2);
        isAnagramHashMap(s3, s2);


    }
}
