#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//https://www.geeksforgeeks.org/container-with-most-water/
//-- non-negative integers a_1, a_2, ..., a_n where each represents a point at coordinate (i, a_i)
// vertical lines are drawn from 0 (the content of the array represents the height), the distance between
// them is 1 unit, ie the distance between 4-5 is 1 unit and 3 - 4 is 3 units,
//-- start on both sides of the array and work towards the middle
void maxArea()
{
    int array[] = {3, 1, 2, 4, 5};
    //-- h * b = 3 * 4 (height capped @ 3) (dist between 3 -5)
    int size = sizeof(array)/sizeof(int);
    int l = 0;
    int r = size -1;
    int area = 0;

    while (l < r)
    {
        // Calculating the max area
        area = fmax(area, fmin(array[l],
                        array[r]) * (r - l));

            if (array[l] < array[r]){
                l += 1;
            }    else {
                r -= 1;
            }
    }
    printf("Max Area found to be %d \n", area);
}

int main(){
  maxArea();
  return 0;

}
