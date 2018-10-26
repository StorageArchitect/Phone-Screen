#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

// Given a string as an input.
// We need to write a program that will print all non-empty substrings of that given string.
void printAllSubStrings() {
  char str[] = "abc";
  int total = pow(2,strlen(str));
  int bitMask=total-1;

  while(1) {
    printf("{");
    for(int i = 0; i < strlen(str); i++){
      if(bitMask & 1 ){
        printf("%c",str[i]);
      }
      bitMask >>=1;
    }
    printf("}");
    bitMask = --total;
    if(total <= 0){
      break;
    }
  }
}


int main() {
  printAllSubStrings();
  return 0;

}