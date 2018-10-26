#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//https://www.geeksforgeeks.org/find-subarray-with-given-sum/
//-- caution pay attention to the index that is inremented in nested loops
//-- calculate the sum of contigious elements

void expandingWindowSum(int sum) {
 int array[] = {1,3,5,7,8,9,11,13,14,16,19,20,21,22,24};
 int size = sizeof(array)/ sizeof(int);

  printf("Expanding Window: \n");
  /* Initialize curr_sum as value of first element      and starting point as 0 */
    int curr_sum = array[0];
    int start = 0;

    /* Add elements one by one to curr_sum and if the curr_sum exceeds the
       sum, then remove starting element */
    for (int i = 1; i <= size; i++)
    {
        // If curr_sum exceeds the sum, then remove the starting elements
        while (curr_sum > sum && (start < i-1)) {
            curr_sum -=  array[start];
            start++;
        }

        // If curr_sum becomes equal to sum, then return true
        if (curr_sum == sum) {
            printf ("Sum found between indexes (%d - %d) with desired sum %d \n", start, i-1,sum);
            return;
        }

        // Add this element to curr_sum
        if (i < size){
          curr_sum += array[i];
        }
    }

    // If we reach here, then no subarray
    printf("No subarray found");
}


int main(){
  expandingWindowSum(23);
  return 0;
}