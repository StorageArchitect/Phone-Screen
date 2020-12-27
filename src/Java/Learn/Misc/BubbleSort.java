package Misc;

public class BubbleSort {

    static int count;

    static void swap(int arr[], int i, int j){
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
        count++;

    }

    //-- bubble the value to the very end of the array
    //-- decrement the number of elements to be sorted ..
    static void bubbleSort(int arr[]) {
        count = 0;
        System.out.println(" Unsorted Array ");
        printArray(arr);
        int unsorted = arr.length -1;
        boolean isSorted = false;
        while(!isSorted) {
            isSorted = true;
            for(int i=0; i < unsorted; i++){
                if(arr[i] > arr[i+1] ){
                    swap(arr, i, i+1);
                    isSorted = false;
                }
            }
            unsorted--;
        }

        System.out.println();
        System.out.println(" Sorted Array ");
        printArray(arr);
        System.out.println("Requred " + count + " swaps");
    }

    static void printArray(int arr[]) {
        for(int i=0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }
    public static void main(String[] args) {
        int arr[] = new int[] {3,4,2,1,5,8,9,12,6};
        System.out.println("BubbleSort An array of Integers");
        bubbleSort(arr);
    }
}
