/****************************************************************
Let us see an example.
   arr[] = {2, 4, 7, 9, 2, 4}
1) Get the XOR of all the elements.
     xor = 2^4^7^9^2^4 = 14 (1110)
2) Get a number which has only one set bit of the xor.
   Since we can easily get the rightmost set bit, let us use it.
     set_bit_no = xor & ~(xor-1) = (1110) & ~(1101) = 0010
   Now set_bit_no will have only set as rightmost set bit of xor.
3) Now divide the elements in two sets and do xor of
   elements in each set, and we get the non-repeating
   elements 7 and 9. Please see implementation for this step

********************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* This function sets the values of *x and *y to non-repeating
 elements in an array arr[] of size n*/
void get2NonRepeatingNos(int arr[], int n, int *x, int *y)
{
  int xor = arr[0]; /* Will hold xor of all elements */
  int set_bit_no;  /* Will have only single set bit of xor */
  int i;
  *x = 0;
  *y = 0;

  /* Get the xor of all elements */
  for(i = 1; i < n; i++)
   xor ^= arr[i];

  /* Get the rightmost set bit in set_bit_no */
  set_bit_no = xor & ~(xor-1);

  /* Now divide elements in two sets by comparing rightmost set
   bit of xor with bit at same position in each element. */
  for(i = 0; i < n; i++)
  {
    if(arr[i] & set_bit_no)
     *x = *x ^ arr[i]; /*XOR of first set */
    else
     *y = *y ^ arr[i]; /*XOR of second set*/
  }
}

/* Driver program to test above function */
int main()
{
  int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
  int *x = (int *)malloc(sizeof(int));
  int *y = (int *)malloc(sizeof(int));
  get2NonRepeatingNos(arr, 8, x, y);
  printf("The non-repeating elements are %d and %d", *x, *y);
  getchar();
}