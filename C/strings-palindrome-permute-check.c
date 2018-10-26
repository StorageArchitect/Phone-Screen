#include <stdio.h>
#include <memory.h>
#include <stdlib.h>



typedef enum {false, true} bool;


void palindromePermuteCheck(char *str){
  // count the number of occurance of each letter there must be only one odd
  int table[128] = {0};
  int oddCount =0;
  int evenCount = 0;
  //-- tacocat is a palindrome , atcocta is a palindrome permution are tactcoa (not a palindrome but can be)
  //-- check that the letters occur exactly twice if it is even string and only one odd if length is odd
  //-- reducing it there should be eaxctly 0 or 1 odds
  //-- pay attention to to lower ..
  for(int i = 0; i < strlen(str); i++){
    table[(int) str[i]] +=1;
  }
  for(int i= 0; i< 128; i++){
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
  char str1[] = "tacocat";
  char str2[] = "atcocta";
  char str3[] = "tcocta";
  char str4[] = "tactcoa";

  palindromePermuteCheck(str1);
  palindromePermuteCheck(str2);
  palindromePermuteCheck(str3);
  palindromePermuteCheck(str4);

  return 0;
}