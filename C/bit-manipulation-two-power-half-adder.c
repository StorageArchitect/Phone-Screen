#include <stdio.h>


typedef enum {false, true} bool;

/**

Count numbers whose sum with x is equal to XOR with x
Given a integer x, find the number of values of a satisfying the following conditions:
    0 <= a <= x
    a XOR x = a + x
*/

int half_adder(int value){
  //-- algorithm is ...  a+b = (a XOR b)  + carry (a AND b)*2 (half adder circuit)
  // a & b ==0 implies   a + b == a^b  + 0
  //-- solve for a & b = 0
  // so for ex 7 (111) & 0000 - 0 has only all bits to unset as a solution
  // 12 = 1100 &  00xx  = 0 has solution (0000,0010, 0001, 0011) , therefore count the bits to un set ..
  int unset = 0;
  while(value){
    if((value & 1) == 0) {
      unset++;
    }
    value = value>>1;
  }
  return 1 << unset;
}


bool is_power_of_two(int value){
  // bit wise and of value and value -1
  return (value & (value -1)) ? false : true;
}

int main() {

  printf("16 is a power of two %d\n", is_power_of_two(16));
  printf("13 is a power of two %d\n", is_power_of_two(13));
  printf("Found the %d solutions that sums 12  \n", half_adder(12));
  return 0;
}

