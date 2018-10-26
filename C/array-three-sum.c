#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
void threeSum(){
  int s[] = {-2,-1,0,1, 2, 3, 4};
  //-- {-2,-1,3}, {-1,0,1}, {-2,0,2}
  //-- caution with converting size into index ..
  //-- start at position i and check if i+1 and size-1 make up the sum
  int size = sizeof(s)/sizeof(int);
  for(int i = 0; i < (size -2); i++ ) {
    int l = i +1;
    int r = size -1;
    while(l < r) {
      if(s[i] + s[l] + s[r] == 0) {
        printf("Found a triplet %d + %d + %d = 0\n", s[i], s[l], s[r]);
        l++;
        r--;
      } else if (s[i] + s[l] + s[r] > 0) {
        printf("triplet %d + %d + %d > 0\n", s[i], s[l], s[r]);
        r--;
      } else if(s[i] + s[l] + s[r] < 0) {
        printf(" triplet %d + %d + %d < 0\n", s[i], s[l], s[r]);
        l++;

      }
    }
  }

}

int main(){
  threeSum();
  return 0;
}