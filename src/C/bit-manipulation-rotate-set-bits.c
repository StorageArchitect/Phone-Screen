#include <stdio.h>


typedef enum{false, true} bool;
#define INT_BITS_SIZE 32

bool is_bit_set(int value, int pos) {
  //-- index starts from 0
  if( value & 1 << pos) {
    return true;
  }

  return false;

}

//-- bit manipulation
int bit_flip(int value, int pos) {
  return(value ^ ( 1 << pos));
}

int clear_bit (int value, int pos){
  return (value & ~(1 << pos));
}
int set_bit( int value, int pos) {

  return (value | 1 << pos );
}
//-- right rotate to preserve the sign
int rotate_right(int value, int n) {

 return ((value >> n % INT_BITS_SIZE) | ( value << (INT_BITS_SIZE - n) % INT_BITS_SIZE));
}

int rotate_left(int value, int n) {

 return ((value << n )| ( value >> (INT_BITS_SIZE - n)));
}


int main() {
  int n = 5;
  int d = 2;

  printf("Rotate left %d\n", rotate_left(n,d));
  printf("Rotate right %d\n", rotate_right(n,d));
  //add 2^3 to the original value
  printf("set bit 3 iof 5 retured %d\n", set_bit(5,3));
  printf("clear bit 3 of 13 retured %d\n", clear_bit(13,3));
  printf("flip bit 2 of 5 retured %d\n", clear_bit(5,2));
  //-- index or pos is 0-3
  printf("is bit 2 of 5 set %d\n", is_bit_set(5,2));
  printf("is bit 1 of 5 set %d\n", is_bit_set(5,1));


 return 0;
}
