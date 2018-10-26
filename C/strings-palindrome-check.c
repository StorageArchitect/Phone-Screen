#include <stdio.h>
#include <memory.h>
#include <stdlib.h>



typedef enum {false, true} bool;


void checkIsPalindrome(char *str){

  for(int i = 0, j = strlen(str)-1; i <  strlen(str)/2; i++, j-- ){
    if(str[i] != str[j]){
      printf("Found a mismatch between %d <-> %d in string %s \n", i, j, str);
      return;
    }
  }

 printf("Strings %s is a palindrome\n",str );
}


int main() {
  char str1[] ="malayalam";
  char str2[] = "palindrome";
  char str3[] = "tacocat";


  checkIsPalindrome(str1);
  checkIsPalindrome(str2);
  checkIsPalindrome(str3);

  return 0;
}