package Coursera.DivideConqure;

import java.util.Arrays;

import static PhoneScreen.Utils.*;

/**
 * Implement the quick sort algorithm
 *
 * @author aahamad
 * @since 26-Dec-2020
 */
public class QuickSort {

    private static int[] quickSort(int[] array) {
        //Arrays.sort(array);
        sort(array,0, array.length -1);
        return array;
    }

    private static void sort(int[] array, int low, int high) {
        if (low >= high) {
            return;
        }
        int pivot = partition(array, low, high);
        sort(array, low, pivot -1);
        sort(array, pivot+1, high);
    }

    private static int partition(int array[], int low, int high)
    {
        int pivot = array[high];
        int pos = (low-1); // index of smaller element
        for (int curr = low; curr < high; curr++) {
            // If current element is smaller than the pivot
            if (array[curr] < pivot) {
                pos++;
                // swap arr[pos] and arr[curr]
                swap(array, pos, curr);
            }
        }
        // swap current position arr[pos+1] and with pivot arr[high]
        swap(array, pos+1, high);
        return pos+1;
    }


    private static void swap(int [] array, int i, int j)
    {
        int t=array[i];
        array[i]=array[j];
        array[j]=t;
    }

    public static void main(String[] args) {
        int [] array = { 3, 2, 1, 4 , 12, 7, 6, 11, 9};
        System.out.print(" Sort the array " );
        printArray(array);
        System.out.print( "Result ");
        printArray(quickSort(array));
    }


}
