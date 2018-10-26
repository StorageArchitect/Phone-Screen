//--[x] minimum in rotated sorted array
//https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
#include <stdio.h>

void recurseFind(int arr[], int start, int size ){
  if(size == 0){
    printf("Could not Find the minimum  \n");
    return;
  }
  if(arr[start] < arr[start + 1]){
    printf("Found the minimum %d @pos  %d \n",start, arr[start] );
    return;
  } else {
    recurseFind(arr,start -1, size -1);
  }

}

void findMinRotatedSortedArray() {
  int arr[] = {5,6,7,8,0,1,2,3,4};
  int n = sizeof(arr) / sizeof(arr[0]);
  recurseFind(arr,0, n -1);
}

int main(){
 findMinRotatedSortedArray();
 return 0;
}