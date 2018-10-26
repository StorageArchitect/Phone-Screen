package PhoneScreen;
//https://www.journaldev.com/14512/java-treemap-treemap-in-java
//https://www.baeldung.com/java-concurrent-skip-list-map
//-- TreeMap is Red-Black tree based NavigableMap implementation.
//   It is sorted according to the natural ordering of its keys.

import java.util.Comparator;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;



public class TreeMapExample {

    public static void display(TreeMap<Integer, String> tMap) {

        Set set = tMap.entrySet();
        Iterator iterator = set.iterator();
        while(iterator.hasNext()) {
            Map.Entry mentry = (Map.Entry)iterator.next();
            System.out.print("key is: "+ mentry.getKey() + " & Value is: ");
            System.out.println(mentry.getValue());
        }
    }

    public static void main(String args[]) {

      /* This is how to declare TreeMap */
        TreeMap<Integer, String> tmapAscend =
                new TreeMap<Integer, String>(new Comparator<Integer>() {
                    @Override
                    public int compare(Integer a, Integer b) {
                        return -1 * (a - b) ;
                    }
                }
                );

        TreeMap<Integer, String> tmapDescend =
                new TreeMap<Integer, String>( );

      /*Adding elements to TreeMap*/
        tmapDescend.put(1, "Data1");
        tmapDescend.put(23, "Data2");
        tmapDescend.put(70, "Data3");
        tmapDescend.put(4, "Data4");
        tmapDescend.put(2, "Data5");


         /*Adding elements to TreeMap*/
        tmapAscend.put(1, "Data1");
        tmapAscend.put(23, "Data2");
        tmapAscend.put(70, "Data3");
        tmapAscend.put(4, "Data4");
        tmapAscend.put(2, "Data5");
      /* Display content using Iterator*/

        display(tmapDescend);
        System.out.println("  ");
        display(tmapAscend);



    }
}
