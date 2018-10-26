#include <stdio.h>
#include <math.h>

void validMirror(int array[], int size) {
  //-- valid array{0,1,2,3,4,5,6,7,8,9}
  int valid[] = {1,1,0,0,0,0,1,0,1,1};
  int j = size -1;
  for(int i = 0; i< size; i++){
    if(valid[array[i]] == 0){
      printf("valid check failed, bad values %d, %d found @ %d and %d\n",array[i], array[j], i, j);
      return;
    }
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


int main() {
  int validArray[] = {1,6,8,0,0,8,9,1};
  int invalidArray[] = {5,1,6,8,0,0,8,9,1,5};

 validMirror(validArray, sizeof(validArray)/ sizeof(int));
  validMirror(invalidArray, sizeof(invalidArray)/ sizeof(int) );

}