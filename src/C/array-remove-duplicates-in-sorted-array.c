//https://www.geeksforgeeks.org/remove-duplicates-sorted-array/
//-- [x] remove duplicates https://www.geeksforgeeks.org/remove-duplicates-sorted-array/

#include <stdio.h>

void removeDups(){
  int array[] = {0,0,1,2,3,7,7,8,9,10,11};
  int n = sizeof(array) / sizeof(array[0]);
  int prev = 0;
  for(int i = 0; i < n; i++){
    if(array[i] != array[prev]){
      array[++prev] = array[i];
    }
  }

  printf("processed duplicates : \n");
  for(int i = 0; i< prev; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

}

int main(){
  removeDups();
 return 0;
}