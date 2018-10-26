#include <stdio.h>
#include <memory.h>
#include <stdlib.h>



typedef enum {false, true} bool;

void swap(char *c1, char *c2){
  if(*c1 != *c2){
    char tmp;
    tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
  }
}

void reverseStr(char *str){
 for(int i=0, j = strlen(str) -1 ; i < strlen(str)/2; i++, j--) {
   swap(&str[i], &str[j] );
 }
}

//-- create a histogram ..
void findDups(char *str){
  int seen[128] = {0};
  for(int i = 0; i < strlen(str); i++){
    if(seen[(int) str[i]] >= 1){
      printf("Seen %c : %d times before\n", str[i], seen[(int) str[i]] );
    }
    seen[(int) str[i]] +=1;

  }

}

int main() {
  char anagram[256] = "gnirts";
  char dups1[256] = "java";
  char dups2[256] = "havaheva";

  printf("Reverse of %s \n", anagram);
  reverseStr(anagram);
  printf("%s", anagram);
  printf("Check dups in %s \n",dups1);
  findDups(dups1);
  printf("Check dups in %s \n",dups2);
  findDups(dups2);

  return 0;
}