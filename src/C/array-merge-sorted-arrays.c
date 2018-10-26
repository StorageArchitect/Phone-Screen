//-- [x] merge sorted arrays  https://www.geeksforgeeks.org/merge-two-sorted-arrays/
//-- the basic algorithm for merge sort.
#include <stdio.h>

void mergeSortedArrays(int arr1[], int arr2[], int n1,
                             int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;

    /**
     Traverse both array
     Check if current element of first
     array is smaller than current element
     of second array. If yes, store first
     array element and increment first array
     index. Otherwise do same with second array
     ***/
    while (i<n1 && j <n2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    // Store remaining elements of first array
    while (i < n1)
        arr3[k++] = arr1[i++];

    // Store remaining elements of second array
    while (j < n2)
        arr3[k++] = arr2[j++];

  printf("Processed sorted array: \n");
  for(i = 0; i < n1+n2; i++){
    printf("%d ", arr3[i]);
  }
  printf("\n");
}

int main(){

    int arr1[] = {1, 3, 5, 7, 9, 12};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8, 13};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1+n2];
    mergeSortedArrays(arr1, arr2, n1, n2, arr3);


 return 0;
}