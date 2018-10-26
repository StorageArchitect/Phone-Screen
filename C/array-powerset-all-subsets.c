#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//--[x] print all the subsets of a set
// https://www.geeksforgeeks.org/power-set/
void powerSet() {
   /**
         * base cases {} and {123}
         * the subsets are {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}
         * general case total 2^n for an set of {abc}
         * 000 => {}
         * 001 => {c}
         * 010 => {b}
         * 011 => {bc}
         * 100 ={a}
         * 101 = {ac}
         * 110 = {bc}
         * 111 = {abc}
         */
        // Run a loop for printing all 2^n
        // subsets one by one
  int array[] = {1,2,3};
  // there are 2^3 subsets
  int size = (sizeof(array)/sizeof(int));
  int max = pow(2,size);

  for(int i = 0; i < max; i++){
    int pos = size -1;
    int bitmask = i;
    printf("{ ");
    while(bitmask > 0)
     {
        if(1 == (bitmask & 1)){
            printf("%d ",array[pos]);
        }
        bitmask >>= 1;
        pos--;
     }
    printf("} ");

  }
}

int main(){

  powerSet();
  return 0;
}