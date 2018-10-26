//---[x] searching through two sorted arrays
//https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/
#include <stdio.h>

void findIntersection(int arr1[], int arr2[], int n1, int n2){

  int i = 0, j = 0;
 //-- both start at zero index and since array is sorted you increment one or the other
  while( i < n1 && j < n2){
    if(arr1[i] == arr2[j]){
      printf("Found intersection of two arrays found at pos %d and %d with value %d\n", i,j, arr1[i]);
      return;
    } else if( arr1[i] > arr2[j]){
      j++;
    } else {
      i++;
    }
  }

}

int main(){
 int arr1[] = {9,13,24,27,28, 31};
 int n1 = sizeof(arr1) / sizeof(arr1[0]);

 int arr2[] = {1, 3, 5, 7, 9, 12};
 int n2 = sizeof(arr2) / sizeof(arr2[0]);

 findIntersection(arr1, arr2, n1, n2);

 return 0;
}