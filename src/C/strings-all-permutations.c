#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

void swap(char *x, char *y) {
  char tmp = *x;
  *x = *y;
  *y = tmp;

}



/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int n)
{
   int i;
   if (l == n) {
     printf("%s\n", a);
   }
   else
   {
       for (i = l; i <= n; i++)
       {
          swap(&a[l], &a[i]);
          permute(a, l+1, n);
          swap(&a[l], &a[i]); //backtrack by swaping back
       }
   }
}


void allPermutations(){
  //-- algorithm, swap the i,j th elements for the size of the string.
  //  A string of length n has n! permutation.
  // -- for {i=0,j=0}, {i=0,j=1}, {i=1,j=0} ...
  char str[] = "ABC"; //-- values are {ABC} {ACB}  ...
  char len = strlen(str);
  // len -1 is require to avoid duplicates
  permute(str,0, len-1 );

}

int main() {
  allPermutations();
  return 0;

}