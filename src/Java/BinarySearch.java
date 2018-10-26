package PhoneScreen;

import java.util.Arrays;

public class BinarySearch {
    //-- look for the number of occurance of value without axullary space
    //-- we could do this recursively too ..
    public static int searchRight(int[] arr, int start) {
        int count = 0;
        int value = arr[start];
        while(start < arr.length){
            if(arr[++start] == value){
                 count++;
            } else {
                return count;
            }
        }

        return count;
    }

    public static int searchLeft(int[] arr, int start) {
        int count = 0;
        int value = arr[start];
        while(start > 0 ){
            if(arr[--start] == value){
                 count++;
            } else {
                return count;
            }
        }
        return count;
    }

  public static int  countOccurance(int[] arr, int start) {
        return searchRight(arr, start) + searchLeft(arr, start) + 1 ;
     }

    static void binSearch(int [] arr, int k) {
        int start = arr.length / 2;

        while(start < arr.length){
            if(arr[start] == k){
              System.out.println(" Value " + k + " occurs " + countOccurance(arr, start) + " times") ;
              return;
            } else {
                if(arr[start] > k) {
                    //-- go left
                    start = start/2;
                } else {
                    start += start/2;
                    //-- go right
                }

            }
        }

        System.out.println(" Value " + k + " could not be found ") ;
    }

    public static void main(String[] args) {
        int arr[] = new int[] {3,4,2,1,3,3,3,7,8,8,7,5,8,9,10,16};
        int k = 13;
        System.out.println("Binary search sorted array of Integers for array of size " + arr.length);
        Arrays.sort(arr);

        binSearch(arr, k);
        int val = 16;
        System.out.println("Binary search sorted array of Integers for " + val + " found @ pos " +
                Arrays.binarySearch(arr, val));

    }
}
