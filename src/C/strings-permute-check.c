#include <stdio.h>
#include <memory.h>
#include <stdlib.h>



typedef enum {false, true} bool;


void checkIsPermutation(char *str1, char *str2){
  bool seen[128] = {false};
  int index = 0;

  //-- both are same size
  while(str1[index] !='\0'){
    seen[str1[index++]] = true;
  }

  index = 0;
  while(str2[index] != '\0'){
   if(seen[str2[index++]] == false) {
     printf("The strings %s and %s are NOT permutations  \n", str1, str2);
     return;
   }
  }

 printf("Strings %s and %s are permutations \n", str1, str2);
}


int main() {
  char str1[] ="this is the original";
  int  size1 = strlen(str1);
  char str2[] = "original this is jhe";
  char str3[] = "original thit is she";
  int size2 = strlen(str2);
  int size3 = strlen(str3);

  if(size1 != size2 && size3 != size1){
    printf("strings cannot be a permutation \n");
    return;
  }

  checkIsPermutation(str1, str2);
  checkIsPermutation(str1, str3);

  return 0;
}