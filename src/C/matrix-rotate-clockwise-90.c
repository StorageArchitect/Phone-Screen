#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define R 4
#define C 4

void swap(int *x, int *y){
  if(*x == *y)
     return;
  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
}



void printMatrix(int matrix[R][C]){
  printf("\n");
  for(int i =0; i < R; i++){
    printf("{ ");
    for(int j = 0; j < C; j++){
      printf("%d, ",matrix[i][j]);
    }
    printf(" }");
    printf("\n");
  }
}


/****
Let the given matrix be
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

First we find transpose.
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16

Then we reverse elements of every column after transosition to rotate 90 degrees
4 8 12 16
3 7 11 15
2 6 10 14
1 5  9 13

instead if we reverse every element of the row after transposition to rotate 270 degrees
13 9  5  1
14 10 6  2
15 11 7  3
16 12 8  4
****/

// After transpose reverse the elements in the rows
void reverseRows(int arr[R][C]) {

  for(int i =0; i < R; i++){
    for(int j=0, k=C-1; j<C/2; j++, k--){
      swap(&arr[i][j], &arr[i][k]);
    }
  }

}



// Function for do transpose of matrix
// To "transpose" a matrix, swap the rows and columns.
void transpose(int arr[R][C])
{
    for (int i=0; i<R; i++)
        for (int j=i; j<C; j++)
            swap(&arr[i][j], &arr[j][i]);
}


// Function to rotate anti-clockwise by 90 degree
void rotateClock90(){
    int arr[4][4]= { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    printf(" Oritinal matrix \n");
    printMatrix(&arr[0][0]);
    transpose(arr);
    printf(" transpose matrix \n");
    printMatrix(&arr[0][0]);
    reverseRows(arr);
    printf("Rotate matrix 90 clockwise \n");
    printMatrix(&arr[0][0]);

}


int main(){
 rotateClock90();
 return 0;
}