#include <stdio.h>
#include <stdlib.h>

//-- given two sorted arrays a, b where array a is 2n and b is n
//-- merge the arrays without using any dynamic memory allocation.

void mergeSortedArrays(int *a, int *b, int n){

  int index = 2*n-1;
  int i = n-1;
  int j = n-1;
  //-- optimize
  if(a[n-1] < b[1] ) {
    printf("Optimized \n");
    for(int i = 0; i < n; i++){
      a[n+i] = b[i];
      printf("%d ", a[i]);
    }
    return;
  }

  //-- main case
  while(i >0 || j > 0 ){
    if(a[i] < b[j]){
      a[index--] = b[j--];
    } else {
      a[index--] = a[i--];
    }
  }

}

int main(){
  int a[8] = {1,3,7,9};
  int b[4] = {4,6,8,10};
  int c[8] = {1,3,5,7};
  int d[4] = {8,9,10,12};

  mergeSortedArrays(c, d, 4);
  printf("\n Optimized Array Merge \n");
  for(int i =0; i < 8; i++){
    printf("%d ", c[i]);
  }
  printf("\n Un optimized Array Merge \n");
  mergeSortedArrays(a, b, 4);
  for(int i =0; i < 8; i++){
    printf("%d ", a[i]);
  }
  return 0;
}