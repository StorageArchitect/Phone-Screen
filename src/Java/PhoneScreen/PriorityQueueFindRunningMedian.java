package PhoneScreen;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
//-- inspired by https://www.youtube.com/watch?v=VmogG01IjYc
public class PriorityQueueFindRunningMedian {


    static void  rebalance( PriorityQueue<Integer> lPQ, PriorityQueue<Integer> hPQ){
        PriorityQueue<Integer> bigger = lPQ.size() > hPQ.size() ? lPQ : hPQ;
        PriorityQueue<Integer> smaller = lPQ.size() > hPQ.size() ? hPQ : lPQ;
        if(Math.abs(bigger.size() - smaller.size()) > 1 ){
            smaller.add(bigger.poll());
        }
    }

    static double computeMedian(PriorityQueue<Integer> lPQ, PriorityQueue<Integer> hPQ){
        PriorityQueue<Integer> bigger = lPQ.size() > hPQ.size() ? lPQ : hPQ;
        PriorityQueue<Integer> smaller = lPQ.size() > hPQ.size() ? hPQ : lPQ;

        if( bigger.size() == smaller.size()){
           return ( (double) bigger.peek() + smaller.peek() )/ 2.0 ;
        } else {
            return (double) bigger.peek();
        }


    }

    static void addNumber(Integer number, PriorityQueue<Integer> lPQ, PriorityQueue<Integer> hPQ) {

        if(lPQ.size() == 0 || number < lPQ.peek()){
            lPQ.add(number);
        } else {
            hPQ.add(number);
        }
    }

    static double[] getMedian(Integer[] array) {
        double medians[] = new double[array.length];
        PriorityQueue<Integer> lPQ = new PriorityQueue<Integer>();
        PriorityQueue<Integer> hPQ = new PriorityQueue<Integer>(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return -1 * a.compareTo(b);
            }
        });


        for(int i = 0; i < array.length; i++){
            addNumber(array[i], lPQ, hPQ);
            rebalance(lPQ, hPQ);
            medians[i] = computeMedian(lPQ, hPQ);

        }
        return medians;

    }


    public static void main(String[] args) {
        Integer[] array = new Integer[] {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 9, 21};
        System.out.println(" Computed median " + Arrays.toString(getMedian(array)));

    }

}
