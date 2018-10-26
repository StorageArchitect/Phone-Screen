#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//https://www.geeksforgeeks.org/given-two-unsorted-arrays-find-pairs-whose-sum-x/

void twoSum(){
  //-- store the difference of the desired sum and value at index
  int table[65536] = {0};
  int array[] = {0,1,2,3,6,8,9,11,12,14,17,19};
  int sum = 20;
  int size = sizeof(array)/sizeof(int);
  for (int i = 0; i < size; i++)
   {
      int x =  array[i];
      // -- this is a backward looking algorithm
      if (sum - x >= 0 && table[sum -x] == 1) {
        printf("found {%d,%d} that forms sum %d \n", array[i],sum-x,sum);
      }
      table[x] = 1;
  }

}
int main() {
  twoSum();
  return 0;
}