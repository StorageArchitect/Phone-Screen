//---[x] searching through two sorted arrays
#include <stdio.h>
//https://www.geeksforgeeks.org/move-zeroes-end-array/
vvoid pushZerosToEnd(int arr[], int size)
 {
     int count = 0;  // Count of non-zero elements

     // Traverse the array. If element encountered is non-
     // zero, then replace the element at index 'count'
     // with this element
     for (int i = 0; i < size; i++)
         if (arr[i] != 0)
             arr[count++] = arr[i]; // here count is
     // Now all non-zero elements have been shifted to
     // front and  'count' is set as index of first 0.
     // Make all elements 0 from count to end.
     while (count < size)
         arr[count++] = 0;
   printf("Processed Array: \n");
    for(int i = 0; i < size; i++){
      printf(" %d", arr[i]);
    }
 }

int main(){
  int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

 pushZerosToEnd(arr, n);
 return 0;
}