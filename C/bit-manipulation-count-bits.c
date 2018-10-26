//-- count the number of bits in an integer
int count_bits_chunked( int value) {
  //-- create a table with values and bits
  //-- and count 4 bits at a time
  //-- value = {0,1,2,3,4,5,6, 7,8,9,10.11.12.13.14.15}
  int lookUP[16] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
  int count = 0;

  while( value ) {
    count +=lookUP[value & 0xf];
    printf("counted %d in chunk %d\n", count, (value & 0xf));
    value = value >> 4;
  }

  return count;

}

int main() {
 printf("there are %d bits in 61439 found with lookup \n", count_bits_chunked(61439));
 printf("there are %d bits in 65536 found with lookup \n", count_bits_chunked(65535));
 return 0;
}
