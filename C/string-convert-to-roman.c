#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROMAN 3999 // corresponds to MMMCMXCIX
void convertToRoman(int value){
  int index = 0;
  int max = 4;
  int valArray[max]; // the maximum size is 4 digits
  char *romanArray[4][9] ={
   {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
   {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
   {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
   {"M", "MM", "MMM", "",  " ", " ", " ", " ", " "}
   } ;
  if(value > MAX_ROMAN || value <= 0)
    return;

  while(value !=  0){
  //-- store remainder into an array
   valArray[index++] = value % 10;
   //-- divide the value and do this again
    value /=10;
  }

  int row = max-1; // row index into the array table
  //-- since we are going from left to right, row starts at max -1
  for(int i = 0; i < max; i++){
    index = valArray[(max-1)-i] ;
    if(index > 0) {
     printf("%s", romanArray[row][index - 1]);
    }
    row--;
  }
  printf("\n");

}

int main() {
 int value = 3008 ;
  convertToRoman(value);
  return 0;
}

