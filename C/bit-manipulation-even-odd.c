#include <stdio.h>


typedef enum {false, true} bool;


//-- bit manipulation
int bit_flip(int value, int pos) {
  return(value ^ ( 1 << pos));
}


char * is_even_odd(int value) {

  if(value & 1 ) {
    return "Odd";
  }
  return "Even";

}

int main() {

  printf("5 is  %s\n", is_even_odd(5));
  printf("16 is  %s\n", is_even_odd(16));
  printf("Flip 3rd bit in 15 results in %d \n",bit_flip(15,3));

  return 0;
}
