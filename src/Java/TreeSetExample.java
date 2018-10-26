package PhoneScreen;
//-- sortedSet is an interface while TreeSet is the class implementing it.
//-- TreeMap is Red-Black tree based NavigableMap implementation.
//   It is sorted according to the natural ordering of its keys.

import java.util.Comparator;
import java.util.Iterator;
import java.util.Map;

import java.util.Set;
import java.util.TreeSet;

public class TreeSetExample {

    public static void display(TreeSet<String> tSet) {

        Iterator iterator = tSet.iterator();
        while(iterator.hasNext()) {
            System.out.println("Set Contains   " + iterator.next());
        }
    }

    public static void main(String args[]) {

      /* This is how to declare TreeMap */
        TreeSet<String> tSetAscend =
                new TreeSet<String>(new Comparator<String>() {
                    @Override
                    public int compare(String a, String b) {
                        return -1 * a.compareTo(b) ;
                    }
                }
                );

        TreeSet<String>  tSetDescend =
                new TreeSet<String>( );

      /*Adding elements to TreeSet*/
        tSetDescend.add("Data1");
        tSetDescend.add("Data2");
        tSetDescend.add("Data3");
        tSetDescend.add("Data4");
        tSetDescend.add("Data5");


        /*Adding elements to TreeSet*/
        tSetAscend.add("Data1");
        tSetAscend.add("Data2");
        tSetAscend.add("Data3");
        tSetAscend.add("Data4");
        tSetAscend.add("Data5");
      /* Display content using Iterator*/

        display(tSetDescend);
        System.out.println("  ");
        display(tSetAscend);



    }
}
