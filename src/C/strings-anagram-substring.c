#include <stdio.h>
#include <memory.h>
#include <stdlib.h>



typedef enum {false, true} bool;

int alphaPos(char *c) {
  return (*c -'a');
}

int match(int *array, char *word) {
  for(int i = 0; i < strlen(word); i++) {
    if(array[alphaPos(&word[i])] == 0) {
      return 0;
    }
  }

  return 1;
}

//-- find the position of the anagram
//-- standard progam to find anagram is to use a table to store histogram of char
//-- we will use a sliding window
int getAnagramPos(char *str, char *anagram) {
  int index = -1;
  int array[26]={0};
  for(int i = 0; i < ( strlen(str) - strlen(anagram)); i++){
    for(int j=0; j< strlen(anagram); j++){
      array[alphaPos(&str[i + j])] = 1;
    }
    if(match(array, anagram)) {
      return i;
    }
    memset(&array[0],0, 26);

  }
  return index;
}

int main() {
  char str[256] ="ieastring contains a string";
  char anagram[256] = "gnirts";

  printf("The anagram %s can be found at pos %d in str %s \n", anagram,
              getAnagramPos(str,anagram), str);
  return 0;
}