#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [x] find transition point of the an infinite stream of sorted 0 - 1 ..
// [x] is string unique
// [x] check permutation
// [x] given a string check if it is a permutation of palindrome
//-- infinite array of [0,1]

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


void uniqueCheck(char *str, int size){
 int table[128] = {0};
 if(size > 128) {
   printf("The string cannot have unique char \n");
   return;
 }
  for(int i = 0; i < size; i++){
    if(table[(int)str[i]] == 1){
      printf("string %s is not unique it has a repete char %c \n",
                                                       str, str[i]);
      return;
    }
    table[(int)str[i]] = 1;
  }

  printf("String %s\n", str);

}

void checkStrings(char *str1, char *str2) {
 int table[256] = {0};

  for(int i = 0; i < strlen(str1); i++){
    table[(int) str1[i]] +=1;
  }

  for(int i = 0; i < strlen(str2); i++){
    if((table[(int) str2[i]] -=1) < 0) {
      printf("The two strings are not a permutation \n");
        return;
    }
  }
  printf("Two strings are permutations \n");


}

void checkPermutations(){
char str1[] ="this is the original";
int  size1 = strlen(str1);
char str2[] = "original this is jhe";
int size2 = strlen(str2);

  if(size1 != size2){
    printf("strings cannot be a permutation \n");
    return;
  }

  checkStrings(str1, str2);


}

void hasAllUniqueChar() {
  char str1[]="asdfghjkl;'/.,mnbvcxz1234567890!@#$%^&*()_+";
  char str2[]="...this has no uniques ...";
  uniqueCheck(str1, strlen(str1));
  uniqueCheck(str2, strlen(str2));

}

void palindromePermutationCheck() {
  char str[] = "tactcoa";
  int table[256] = {0};
  int oddCount =0;
  int evenCount = 0;
  //-- tacocat is a palindrome, atcocta is a palindrome
  //-- check that the letters occur exactly twice if it is even string and only one odd if length is odd
  //-- reducing it there should be eaxctly 0 or 1 odds
  //-- pay attention to to lower ..
  for(int i = 0; i < strlen(str); i++){
    table[(int) str[i]] +=1;
  }
  for(int i= 0; i< 256; i++){
    if((table[i] % 2 ) == 1){
      oddCount +=1;
    }
  }
  if(oddCount >1 ) {
    printf("The string %s is not a permutation of a palindrome \n", str);
    printf("The odd count is %d\n", oddCount);
    return;
  }

    printf("The string %s is a permutation of a palindrome \n", str);
}

int main() {
  findTransitionPoint();
  hasAllUniqueChar();
  checkPermutations();
  palindromePermutationCheck();

  return 0;
}
