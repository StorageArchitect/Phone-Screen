#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/

void twoDiff(){
  int hashmap[65536] = {0};
  int array[] = {0,2,1,3,6,7,8,9,11,14,17,19};
  int diff = 6;
  int size = sizeof(array)/sizeof(int);
    //-- this is a forward looking algorithm,set the hash table elements to 1
    for (int i = 0; i < size; i++){
        hashmap[array[i]] = 1;
    }

    for (int i = 0; i < size; i++)
    {
        int x = array[i];
        if (x + diff < 65536 && hashmap[x + diff]) {
           printf("found {%d,%d}  that forms diff %d \n",x, x+diff, diff);
        }
        hashmap[x] = 0;
    }

}

int main(){
  twoDiff();
  return 0;
}