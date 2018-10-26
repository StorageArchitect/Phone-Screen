#include <stdio.h>
#include <string.h>
#include <math.h>

typedef int bool;
#define true  1
#define false 0

// [x] rotate matrix



void swapChar(char *x, char *y) {
  if(*x == *y)
     return;
  char tmp = *x;
  *x = *y;
  *y = tmp;
}


void swap(int *x, int *y){
  if(*x == *y)
     return;
  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
}

/**************************************************************************
Given a NxN matrix with 0s and 1s. Set every row that contains a 0 to all 0s
and set every column that contains a 0 to all 0s.

For example

1 0 1 1 0
0 1 1 1 0
1 1 1 1 1
1 0 1 1 1
1 1 1 1 1

results in

0 0 0 0 0
0 0 0 0 0
0 0 1 1 0
0 0 0 0 0
0 0 1 1 0

***************************************************************************/
void nullifyRow(int matrix[5][5], int row ){

  for(int i = 0; i < 5; i++){
    matrix[row][i] = 0;
  }

}

void nullifyCol(int matrix[5][5], int col){
  for(int i = 0; i < 5; i++){
    matrix[i][col] = 0;
  }

}
void twoDArray(){
  int matrix[5][5]= { {1,0,1,1,1}, {1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,1,0} };
  bool row[5] = {{false}};
  bool col[5] = {{false}};

  //-- find the size of this matrix ?
int rows = sizeof(matrix) / sizeof(matrix[0]);
int cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);
printf("Size of matrix is %d Rows x %d columns\n", rows, cols );

  for(int i =0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(matrix[i][j] == 0){
        row[i] = true;
        col[j] = true;
      }
    }
  }


  for(int i = 0; i < 5; i++){
    if(row[i] == true){
      nullifyRow(&matrix[0][0],i);
    }
  }


  for(int i = 0; i < 5; i++){
    if(col[i] == true){
      nullifyCol(&matrix[0][0],i);

    }
  }

  for(int i =0; i < 5; i++){
    printf("{ ");
    for(int j = 0; j < 5; j++){
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

// After transpose we swap elements of column
// one by one for finding left rotation of matrix
// by 90 degree
void reverseColumns(int arr[4][4])
{
    for (int i=0; i<4; i++)
        for (int j=0,  k=4-1; j<k; j++,k--)
            swap(&arr[j][i], &arr[k][i]);
}


// Function for do transpose of matrix
// To "transpose" a matrix, swap the rows and columns.
void transpose(int arr[4][4])
{
    for (int i=0; i<4; i++)
        for (int j=i; j<4; j++)
            swap(&arr[i][j], &arr[j][i]);
}

// After transpose reverse the elements in the rows
void reverseRows(int arr[4][4]) {

  for(int i =0; i < 4; i++){
    for(int j=0, k=3; j<2; j++, k--){
      swap(&arr[i][j], &arr[i][k]);
    }
  }

}

void printMatrix(int arr[4][4]){
  for(int i =0; i < 4; i++){
    printf("{ ");
    for(int j = 0; j < 4; j++){
      printf("%d, ",arr[i][j]);
    }
    printf(" }");
    printf("\n");
  }

}
// Function to rotate anti-clockwise by 90 degree
void rotateAntiClock90()
{
    int arr[4][4]= { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    transpose(arr);
    reverseColumns(arr);
    printf("Rotate matrix 90 anti-clockwise \n");
    printMatrix(&arr[0][0]);
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

void swapCharTest(){
  char str[] = "ABCD";
  int len = strlen(str);
  for(int i=0, k=len-1; i < len/2; i++, k--){
    swapChar(&str[i], &str[k]);
  }
  for(int i = 0; i< len; i++)
     printf("%c",str[i]);
}

int  main() {

  twoDArray();
  rotateAntiClock90();
  rotateClock90();
  swapCharTest();


  return 0;

}