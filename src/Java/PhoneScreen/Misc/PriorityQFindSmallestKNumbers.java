package Misc;

import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class PriorityQFindSmallestKNumbers {

    static Integer[] getSmallestArray(List<Integer> list, int k){
        Integer[] small = new Integer[k];
        PriorityQueue<Integer> pQ = new PriorityQueue<Integer>(list);
        for(int i = 0; i <  k ; i++){
            small[i] = pQ.poll();
            System.out.println( " " + small[i]);
        }

        return small;
    }

    public static void main(String[] args) {
        Integer[] array = new Integer[] {5, 15, 0, 3, 2, 8, 7, 9, 10, 6, 11, 4};
        List <Integer> list = Arrays.asList(array);
        int k = 3;

        System.out.println("Smallest Element array" +
                Arrays.toString(getSmallestArray(list, k)) );
    }
}
