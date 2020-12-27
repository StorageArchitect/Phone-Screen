package Misc;

import java.util.HashMap;

public class HashMapWordCount {

    public static void main(String[] args) {
        System.out.println("Example to use a hash map to count words");
        HashMap<String, Integer> map = new HashMap<>();
        String[] arr = new String[]{"hello", "hello", "world", "i", "see",
                                    "hello", "hello", "world", "i", "see",
                                     "hello", "hello", "world", "I", "see",
                                     "See", "See", "my"
        };

        for(int i = 0; i < arr.length; i++) {
            Integer n = map.get(arr[i]);
            if(n == null){
                map.put(arr[i], 1);
            } else {
                map.put(arr[i], n+1);
            }
        }

        for(String key : map.keySet()){
            System.out.println(" Word " + key + " Occurs " + map.get(key) + " Times");
        }

    }

}
