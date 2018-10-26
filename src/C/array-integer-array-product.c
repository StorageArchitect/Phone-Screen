#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

 // pattern = { 2x3x4x5, 1x3x4x5, 1x2x4x5, 1x2x3x5, 1x2x3x4 }
 //-- one pass left --> right initial product = 1
 //-- one pass right --> left initial product = 1
  // multiple the first and second array

  void arrayProduct() {
         int Values[] = {1, 2, 3, 4, 5};
         int size = sizeof(Values)/sizeof(int);
          int lrArray[size];
          int rlArray[size];

          int product = 1;
          for(int i = 0; i < size; i++ ){

              lrArray[i] =  product;
              product = product * Values[i];
          }
          product = 1;
          for(int j = size -1 ; j >= 0; j-- ){
              rlArray[j] =  product;
              product = product * Values[j];
          }

          for(int i = 0; i < size; i++ ){
              printf("%d ",  rlArray[i] *  lrArray[i]);
          }
          printf("\n");

  }

  int main(){
  arrayProduct();
  return 0;
  }