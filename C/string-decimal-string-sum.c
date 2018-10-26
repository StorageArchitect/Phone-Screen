#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void stringSum(){
  char val1[] = "23456789101112001";
  char val2[] = "98765342142324001";
  // expected   122222131243436002
  int size = strlen(val1); // assume string1 and string 2 are same size
  char result[256]={'\0'};
  int carry=0;
  int tmp;
  printf("String Size %d \n", size);
  int i = size-1;
  while(1){
    tmp = (val1[i] - '0') + (val2[i] - '0') + carry;
    carry = tmp / 10;
    result[i+1] = tmp%10 + '0';
    i--;
    if(i<0){
    if(carry != 0){
      result[0] = carry + '0';
     }
     break;
    }
  }

  printf("Calculated string sum %s", result);
}

int main(){
  stringSum();
  return 0;
}