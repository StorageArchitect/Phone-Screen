#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>


void swap(char *x, char *y) {
  char tmp = *x;
  *x = *y;
  *y = tmp;

}

void rotateString() {
  char str[] ="rotatemewillya";
  int len = strlen(str);
  for(int i = 0; i < len/2; i++){
    swap(&str[i], &str[len - 1 -i]);
  }
  printf("Rotated string %s \n ", str);
}


int main() {

  rotateString();
  return 0;
}