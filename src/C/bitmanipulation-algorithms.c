#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_BITS_SIZE 32


int count_bits_brute(int value){
  //-- brute force method
  int count = 0;
  while( value) {
    if(value & 1  ) {
      count++;
    }
    value = value >> 1;
  }

  return count;
}

int count_bits_chunked( int value) {
  //-- create a table with values and bits
  //-- and count 4 bits at a time
  //-- value = {0,1,2,3,4,5,6, 7,8,9,10.11.12.13.14.15}
  int lookUP[16] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
  int count = 0;

  while( value ) {
    count +=lookUP[value & 0xf];
    printf("counted %d in %d\n", count, (value &0xf));
    value = value >> 4;
  }

  return count;

}
//-- swap without extra variable
char * rev_str( char * str) {
  int len = strlen(str);
  int start = 0;
  int end = len-1;
  char temp;

  printf("string length %d \n",len);

   while(start < end){
    str[start] ^= str[end];
    str[end] ^= str[start];
    str[start] ^= str[end];
     //printf("Start %d, end %d \n", start, end);
     /**
     temp = str[start];
     str[start] = str[end];
     str[end] = temp;
     **/
        start++;
        end--;
  }

        return str;

}

int count_equal_sum_xor( int value ) {
  // find values of i such that 0 <= i <= values such that
  // value + i = value ^ i
  //-- burte force is straight forward (iterate over the values of i and compare)
  //-- algorithm is ... some formula a+b = (a XOR b) + (a AND b)*2
  // a & b ==0 implies   a + b == a^b (half adder circuits )
  //-- solve for a & b = 0
  // so for ex 7 (111) has only 0 as solution
  // 12 = 1100 &  00xx  = 0 has solution (0000,0010, 0001, 0011) , count the bits to un set ..
  int unset = 0;
  while(value){
    if((value & 1) == 0) {
      unset++;
    }
    value = value>>1;
  }

  return 1 << unset;

}


// -- count the number of ones
// -- number is power of two if only one one is set
char * is_power_of_two(int x) {

  return ((x & (x -1))  ? "false" : "true");
}

int count_bits(int value) {
  int count = 0;

  while(value){
    value = value & (value - 1);
    count++;
  }

  return count;

}

char * is_even(int value) {

  if(value & 1 ) {
    return "Odd";

  }

  return "Even";

}

int modify_bit(int value, int pos, int state){
  return ((value & ~(1 << pos) ) | (-state & (1 << pos)));
}

char * is_bit_set(int value, int pos) {
  if( value & 1 << pos) {
    return "true";
  }

  return "false";

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
  //-- rotate bits
  int n = 5;
  int d = 2;
  char str[256] = "wearenotamused";

  printf("Rotate left %d\n", rotate_left(n,d));
  printf("Rotate right %d\n", rotate_right(n,d));
  //add 2^3 to the original value
  printf("set bit 3 iof 5 retured %d\n", set_bit(5,3));
  printf("clear bit 3 of 13 retured %d\n", clear_bit(13,3));
  printf("flip bit 2 of 5 retured %d\n", clear_bit(5,2));
  printf("is bit 2 of 5 set %s\n", is_bit_set(5,2));
  printf("is bit 1 of 5 set %s\n", is_bit_set(5,1));
  printf("5 is  %s\n", is_even(5));
  printf("15 is  %s\n", is_even(5));
  printf("16 is power of two %s \n", is_power_of_two(16));
  printf("15 is power of two %s \n", is_power_of_two(15));
  printf("the number of values in count sum xor for 12 are %d\n", count_equal_sum_xor(12));
  printf("the number of values in count sum xor for 7 are %d\n", count_equal_sum_xor(7));
  printf("reverse string of wearenotamused is %s \n",rev_str(str));
  printf("there are %d bits in 61439 found with lookup \n", count_bits_chunked(61439));
  printf("there are %d bits in 61439 found with count \n", count_bits(61439));
  return 0;
}

