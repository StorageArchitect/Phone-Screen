package PhoneScreen;

import java.util.HashMap;
import java.util.Map;

public class HashMapReplaceValue {

    public static void printmap(HashMap<String,String> map) {
        System.out.println("Current map values");
        for (String key : map.keySet()) {
            System.out.println(map.get(key));
        }

    }

    public static void main(String[] args) {
        System.out.println("Example to use a hash map");
        HashMap<String, String> map = new HashMap<>();
        map.put("a", "myitem-a");
        map.put("b", "myitem-b");
        map.put("v", "myitem-v");
        map.put("d", "myitem-v");
        map.put("e", "myitem-e");
        printmap(map);
        String s = map.get("a");
        if(s != null){
            map.put("b",s);
            map.put("a","");
        }
        printmap(map);


    }
}
