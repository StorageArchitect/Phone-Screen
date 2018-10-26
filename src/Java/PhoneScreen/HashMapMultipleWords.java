package PhoneScreen;

import java.util.HashMap;

public class HashMapMultipleWords {
    public static void main(String[] args) {
        System.out.println("Example to use a hash map to count words");
        HashMap<String, Integer> map = new HashMap<>();
        HashMap<String, Boolean> newMap = new HashMap<>();
        String[] arr = new String[]{"hello", "hello", "world", "i", "see",
                "hello", "hello", "world", "i", "see",
                "hello", "hello", "world", "I", "see",
                "See", "See", "my"
        };

        for(int i = 0; i < arr.length; i++) {
            Integer n = map.get(arr[i]);
            if(n == null){
                map.put(arr[i], 1);
                newMap.put(arr[i], false);
            } else {
                map.put(arr[i], n+1);
                newMap.put(arr[i], true);
            }
        }

        for(String key : map.keySet()){
            if(newMap.get(key)){
                System.out.println(" Word " + key + " Occurs multiple times Times");
            } else {
                System.out.println(" Word " + key + " Doesn't Occurs multiple times Times");
            }
        }

    }
}
