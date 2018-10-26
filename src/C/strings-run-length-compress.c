#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>
void swap(char *x, char *y) {
  char tmp = *x;
  *x = *y;
  *y = tmp;

}

void compressString(){
  char str[] = "runnyyyyssstrinnnng ";
  int count = 0;
  int prev = 0;
  printf("Run length compress %s \n", str);
  for(int i=1; i < strlen(str); i++){
    if(str[prev] != str[i]){
      if(count > 0){
        str[++prev] = '0' +  count+1;
        str[++prev] = str[i];
        swap(&str[prev-1], &str[prev-2]);
      } else {
        str[++prev] = str[i];
      }
      count = 0;
    }else{
     count++;
    }

  }
  str[prev+1]='\0';

  printf("Runlength compressed string to %s\n",str);
}


int main() {
  compressString();
  return 0;
}