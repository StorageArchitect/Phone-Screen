package Coursera.DivideConqure;

import java.util.Arrays;

import static PhoneScreen.Utils.*;

/**
 * Implementation of the merge sort algorithm. Divide the array into smaller parts and sort them
 *
 * Pay close attention to the index, and array lengths you start at 0 and go up to length-1
 *
 * MergeSort(arr[], l, r) If r > l
 * Find the middle point to divide the array into two halves:
 * middle m = (l+r)/2
 * Call mergeSort for first half:
 * mergeSort(arr, l, m)
 * Call mergeSort for second half:
 * Call mergeSort(arr, m+1,r)
 * Merge the two halves sorted in step 2 and 3:
 * Call merge(arr, l, m, r)
 *
 * @author aahamad
 * @since 27-Dec-2020
 */
public class MergeSort {

    private static int[] mergeSort(int array[]) {
        divide(array);
        return array;
    }


    //-- merge sort requires in place merge
    private static void merge(int[] result, int[] array1, int[] array2) {
        int i = array1.length -1;
        int j = array2.length -1;
        int pos = array1.length + array2.length -1;

        while(i >= 0 && j >= 0) {
            if (array1[i] > array2[j]) {
                result[pos--] = array1[i--];
            } else {
                result[pos--] = array2[j--];
            }
        }
        while(i>= 0) {
            result[pos--] = array1[i--];
        }
        while(j>= 0) {
            result[pos--] = array2[j--];
        }
    }

    /**
     * recursively divide into two halves
     * sort abd merge the two halves
     * @param array
     */
    private static void divide(int[] array) {
        int start = 0;
        int size = array.length;
        if (size < 2) {
            return;
        }
        int mid = (size)/2;
        int[] left = new int[mid];
        int[] right = new int[size - mid];

        for(int i = start, k = 0; i < mid;  i++) {
            left[k++] = array[i];
        }
        for(int i = mid, k = 0; i < size; i++) {
            right[k++] = array[i];
        }
        divide(left);
        divide(right);
        //-- merge the two halves
        merge(array, left, right);

    }

    public static void main(String[] args) {
        int [] array = { 3, 2, 1, 4 , 12, 7, 6, 11, 9, 13};
        int [] array1 = {1,2,3};
        int [] array2 = {5,6,7};
        int [] result = new int[array1.length + array2.length];

        System.out.println(" merge the arrays  " + Arrays.toString(array1) + " and  " + Arrays.toString(array2));
        merge(result, array1, array2);
        printArray(result);

        System.out.print(" Sort the array " );
        printArray(array);
        System.out.print( "Result ");
        printArray(mergeSort(array));
    }

}
