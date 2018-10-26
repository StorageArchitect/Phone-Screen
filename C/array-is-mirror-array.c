#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


//create a table that contains numbers that can be mirrors
void validMirror(int array[], int size) {
  int valid[] = {1,1,0,0,0,0,1,0,1,1};
  //-- for ex 0 = 0, 6=9, 8=8, 1=1
  //-- {0,1,2,3,4,5,6,7,8,9}
  int j = size -1;
  for(int i = 0; i< size; i++){
    //-- first pass check if these belong to valid set
    if(valid[array[i]] == 0){
      printf("validity check failed, bad values %d, %d found @ %d and %d\n",array[i], array[j], i, j);
      return;
    }
    // now if they are different from begining and end
    if(array[i] != array[j]){
      if( (array[i]!= 6 && array[j] != 9) || (array[i] != 9 && array[j] != 6) ){
        continue;
      } else {
        printf("Array is invalid,  bad values %d, %d found\n",array[i], array[j]);
        return;
     }

    }
    j--;

  }
  printf("Arrays are valid \n");

}

int main(){

  int validArray[] = {1,6,8,0,0,8,9,1};
  int validALen = sizeof(validArray)/ sizeof(int);
  int invalidArray[] = {5,1,6,8,0,0,8,9,1,5};
  int invalidALen = sizeof(invalidArray)/ sizeof(int);

  validMirror(validArray, validALen);
  validMirror(invalidArray, invalidALen);

  return 0;
}
