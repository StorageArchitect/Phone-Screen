/--[x] rotate array  https://www.geeksforgeeks.org/array-rotation/
#include <stdio.h>

/******************************************
// using extra space
 Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
1) Store d elements in a temp array
   temp[] = [1, 2]
2) Shift rest of the arr[]
   arr[] = [3, 4, 5, 6, 7, 6, 7]
3) Store back the d elements
   arr[] = [3, 4, 5, 6, 7, 1, 2]
**********************************************/


/* Function to left Rotate arr[] of size n by 1*/
// O(n*d) but O(1) space
void leftRotatebyOne(int arr[], int n);


/* utility function to print an array */
void printArray(int arr[], int n)
{
  int i;
  printf("Printing rotated array: \n");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
}


/*Function to left rotate arr[] of size n by d*/
void leftRotateArray(int arr[], int pivot, int n)
{
  int i;
  for (i = 0; i < pivot; i++)
    leftRotatebyOne(arr, n);
}

void leftRotatebyOne(int arr[], int n)
{
//-- move the elements to fron of array
//-- swap the first and last element and
  int temp = arr[0], i;
  for (i = 0; i < n-1; i++){
     arr[i] = arr[i+1];
     }
  arr[i] = temp;
}

/* Driver program to test above functions */
int rotateArray()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7,8,9,11,19};
   int n = sizeof(arr) / sizeof(arr[0]);
   int pivot = 4;

  // we have to move the items from the pivot to the front not swap them
  leftRotateArray(arr,pivot, n);


   printArray(arr, n);
   return 0;
}

int main(){
  rotateArray();
 return 0;
}