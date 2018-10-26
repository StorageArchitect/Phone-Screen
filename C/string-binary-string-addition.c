#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//https://www.geeksforgeeks.org/program-to-add-two-binary-strings/

void addTwoBinaryStrings() {
  char val1[] = "10101010101010110";
  char val2[] = "10101010101001010";
  // expected   101010101010100000
  int size = strlen(val1); // assume string1 and string 2 are same size
  char result[256]={'\0'};
  int carry=0;
  int tmp;
  printf("String Size %d \n", size);
  int i = size-1;
  while(1){
    tmp = (val1[i] - '0') + (val2[i] - '0') + carry;
    carry = tmp / 2;
    result[i+1] = tmp%2 + '0';
    i--;
    if(i<0){
      printf("Carry is %d\n", carry);
      if(carry != 0){
      result[0] = carry + '0';
     }
     break;
    }
  }

  printf("Calculated binary string sum %s \n", result);

}

int main(){
  addTwoBinaryStrings();
  return 0;
}
