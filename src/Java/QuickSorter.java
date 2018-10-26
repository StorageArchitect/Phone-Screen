package PhoneScreen;

import java.util.Arrays;

public class QuickSorter {
    private int[] a;
    private int n;

    public void sort(int[] a)
    {
        this.a=a;
        n=a.length;
        quicksort(0, n-1);
    }

    //  lo is the lower index, hi is the upper index
    //  of the region of array a that is to be sorted
    private void quicksort (int lo, int hi)
    {
        if (lo>=hi) // less than two elements
            return;

        // comparison element x
        int x=a[lo+(hi-lo)/2];

        //  partition
        int i=lo, j=hi;
        while (i<=j)
        {
            while (a[i]<x) i++;
            while (a[j]>x) j--;
            if (i<=j)
                swap(i++, j--);
        }

        // recursion
        quicksort(lo, j);
        quicksort(i, hi);

    }

    private void swap(int i, int j)
    {
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
    }

    public static void main(String[] args) {
        int arr[] = new int[] {13,4,2,1,23,3,43,17,81,38,7,25,28,9,10,96};
        QuickSorter qs = new QuickSorter();
        qs.sort(arr);
        System.out.println("The sorted Array is " + Arrays.toString(arr) );
    }
}
