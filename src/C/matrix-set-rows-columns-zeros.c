#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//https://www.geeksforgeeks.org/a-boolean-matrix-question/
typedef enum { false, true } bool;
//-- set the rows and columns 0 if any item is zero

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


void printMatrix(int matrix[5][5]){
  printf("\n");
  for(int i =0; i < 5; i++){
    printf("{ ");
    for(int j = 0; j < 5; j++){
      printf("%d, ",matrix[i][j]);
    }
    printf(" }");
    printf("\n");
  }
}

void twoDMatrix(){
  int matrix[5][5]= { {1,0,1,1,1}, {1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,1,0} };
  bool row[5] = {{false}};
  bool col[5] = {{false}};
 int numRow = sizeof(matrix) / sizeof(matrix[0]);
 int numCol = sizeof(matrix[0]) / sizeof(int);

 printf("using Axullary matrix \n");
  printMatrix(&matrix[0][0]);
 //-- first pass check if any one of the members is zero
  for(int i = 0; i < numRow; i++){
    for(int j = 0; j< numCol; j++){
      if(matrix[i][j] == 0){
        row[i]= true;
        col[j]= true;
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

  printMatrix(&matrix[0][0]);


}


//-- without extra space
void modifyMatrix()
{
    int R = 5;
    int C = 5;
    int mat[5][5]= { {1,0,1,1,1}, {1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,1,0} };
    bool row_flag = false;
    bool col_flag = false;

    printf("Space effecient \n");
    // use the first row and column as a placeholder for indication that the row or column needs to be zeroed
    printMatrix(&mat[0][0]);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i == 0 && mat[0][j] == 0){
                row_flag = true;
            }

            if (j == 0 && mat[i][0] == 0){
                col_flag = true;
            }

            if (mat[i][j] == 0) {
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }

    // Modify the rows and columns of the matrix based on the first row and first column of Matrix
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {

            if (mat[0][j] == 0 || mat[i][0] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    // modify all elements first row if there was any 0 encounted that row
    if (row_flag == true) {
        for (int i = 0; i < C; i++) {
            mat[0][i] = 0;
        }
    }

    // modify all elements  first col if there was any 0
    if (col_flag == true) {
        for (int i = 0; i < R; i++) {
            mat[i][0] = 0;
        }
    }

  printMatrix(&mat[0][0]);

}

int main(){
  twoDMatrix();
  modifyMatrix();
  return 0;
}