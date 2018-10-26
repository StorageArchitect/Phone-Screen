#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//https://www.geeksforgeeks.org/window-sliding-technique/
void slidingWindow(int target, int w){

 int array[] = {1,3,5,7,8,9,11,13,14,16,19,20,21,22,24};
 int size = sizeof(array)/ sizeof(int);
 int sum = 0;
  printf("Sliding Window: \n");
  //-- initial window sum
  for(int i=0; i < w; i++){
   sum += array[i];
  }

  for(int i = 1; i< size - w; i++ ){
    if(sum == target){
      printf("Found a window of range  %d - %d with desired sum %d \n", i-w, i-1, target);
    }
    //-- remove prev element
    sum -=array[i-1];
    //-- add next element
    sum +=array[i];

  }

}

int main(){
  slidingWindow(23,4);
  return 0;
}