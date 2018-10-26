#include <stdio.h>
#include <memory.h>
#include <stdlib.h>



typedef enum {false, true} bool;

void uniqueCheck(char *str) {
  bool seen[128] = {false};
  int index = 0;

  while(str[index] != '\0'){
    if(seen[(int)str[index]] == true){
      printf("String %s is not unique found %c \n", str, str[index]);
      return;
    }else {
      seen[(int) str[index]] = true;
    }
    index++;
  }

  printf("String %s is unique \n", str);

}

int main() {
  char str1[]="asdfghjkl;'/.,mnbvcxz1234567890!@#$%^&*()_+";
  char str2[]="...this has no uniques ...";
  uniqueCheck(str1);
  uniqueCheck(str2);
  return 0;
}