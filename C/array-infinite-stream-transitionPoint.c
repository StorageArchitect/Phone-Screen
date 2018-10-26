#include <stdio.h>
https://www.geeksforgeeks.org/find-index-first-1-infinite-sorted-array-0s-1s/
//-- divide and conqure and find the block where there are both 0 and 1
//-- let us assume that there is a size limit to make sure that the program does not bomb
void findRange(int array[], int *l, int *r, int size){
  *l = 0;
  *r = 1;

  while(array[*r] == 0){
   *l = *r;
    *r = *r * 2;
    if(*r > size){
      printf("bad size \n");
    }
  }
}

void searchTransition(int array[], int l, int r){

  while(1){
    int mid = l + r / 2;
    if(array[mid] == 1 && array[mid -1] == 0 ){
      printf("found the transition @ %d, %d\n", mid, mid -1);
      return;
    } else if (array[mid] == 1){
      r-=1;
    } else if (array[mid] == 0){
      l+=1;
    }

  }
}

void findTransitionPoint() {
  int array[] = {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1};
  int size = sizeof(array)/sizeof(int);
  int l = 0;
  int r = 0;
  findRange(array, &l, &r, size);
  printf("Search between %d - %d \n", l,r);
  searchTransition(array, l, r);

}

int main() {

  findTransitionPoint();
  return 0;
}
