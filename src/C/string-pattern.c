#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
//-- find the first occurance of the string in a given string, return the index
//-- there is a one off bug here ...

int getSubStringIdx(char *str, char *word) {
  int index = -1;
  // -- using a sliding window algorithm
  for(int i = 0; i < strlen(str); i++ ){
    if(str[i] == word[0]) {
      for(int j = 0; j< strlen(word); j++) {
        if(str[i+j] != word[j]) {
          break;
        }
        if(j == strlen(word) -1  ) {
          return i;
        }
      }
    }
  }

  return index;
}

//-- find the anagram of the string ...
//-- assume ascii alphabets, lowere case

int alphaPos(char *c) {
  return (*c -'a');
}

void clearArray(int *array){

  for(int i=0; i < 26; i++) {
    array[i] = 0;
  }
}

int match(int *array, char *word) {
  for(int i = 0; i < strlen(word); i++) {
    if(array[alphaPos(&word[i])] == 0) {
      return 0;
    }
  }

  return 1;
}
//-- find the position of the anagram
int getAnagramPos(char *str, char *anagram) {
  int index = -1;
  int array[26];
  clearArray(&array[0]);
  for(int i = 0; i < ( strlen(str) - strlen(anagram)); i++){
    for(int j=0; j< strlen(anagram); j++){
      array[alphaPos(&str[i + j])] = 1;
    }
    if(match(array, anagram)) {
      return i;
    }
   clearArray(&array[0]);

  }
  return index;
}


long newHash(const char *str, int start, int end, int prime) {
  long hash = 0;
  //-- rabin hash formula is
  //-- v0*pow(prime,0) + v1*pow(prime,1) + v2(prime,2)
  for(int i = 0; i < end - start; i++ ){
    hash += ((int)str[start+i])*pow(prime,i);
  }

  return hash;
}

long reCalcHash(const char *str, int prev, int start, int end, long oldHash, int prime ) {
  //-- subtract the previous value
  //-- divide by the prime
  //-- add the new value
  //-- original = v0*pow(prime,0) + v1*pow(prime,1) + v2(prime,2)
  //--- hash = v0 + v1*pow(prime,0) + v2*pow(prime,1) + v3*pow(prime,2)
  long hash = oldHash - ((int)str[prev]) ;
  //-- note end is obtained by strlen (convert it to index value)
  hash += ((int)str[end-1])*pow(prime,(end  - start));
  hash = hash / prime;
  return hash;
}

int rabinKarp(const char *str, char *pattern) {
  int index = -1;
  int prime  = 101;
  long patternHash = newHash(pattern,0, strlen(pattern), prime) ;
  long strHash = newHash(str,0, strlen(pattern), prime);
  for(int i=1; i < strlen(str); i++){
    if(strHash == patternHash) {
      return i;
    }
    strHash = reCalcHash(str, i - 1, i, i + strlen(pattern), strHash, prime );
    printf("Orig hash %ld, calculated hash %ld @pos %d \n ",patternHash, strHash,i );
  }
  return index;
}

char *reverseStr(char *str ) {
  char *tmp;
  //-- converting length to index
  int j = strlen(str)-1;
  for(int i = 0; i < strlen(str)/2; i++) {
    tmp = str[j];
    str[j--] = str[i];
    str[i] = tmp;
  }

  return str;
}

  char * palindrome(char *str) {
    int j = strlen(str) - 1;
    for(int i = 0; i < strlen(str)/2; i++) {
      if(str[i] != str[j--]) {
        return "false";
      }
    }

    return "true";
  }

void getDups(char * str) {
  int array[26];
  clearArray(&array[0]);

  for(int i = 0; i < strlen(str); i++ ){
    array[alphaPos(&str[i])] +=1;
  }

  for(int i = 0; i < 26; i++) {
    if(array[i] >=2 ) {
      printf("%c: %d ",(char)('a'+i), array[i] );
    }
  }
  printf("\n");

}

void reverseRecurse(char *str, int i, int j) {
  char *tmp = str[i];
  if(j <= i) {
    return;
  }
  str[i] = str[j];
  str[j] = tmp;
  reverseRecurse(str, i+1, j-1);
  return ;
}

void reverseMe(char *str) {
   printf("reverse string %s \n",str) ;
   reverseRecurse(str, 0, strlen(str) -1 );
}

long power(int x, int y) {

  long temp;
  if(y==0) {
    return 1;
  }
  //--divide and conqure with lookup ..
  temp = power(x,y/2);
  if( y%2 == 0) {
    return temp * temp;
  } else {
    return x * temp * temp;
  }

}

long calculatePower(int x, int y) {

  return power(x,y);

}
int main() {
  char str[256] ="this string contains a iestring";
  char word[256] = "string";
  char anagram[256] = "gnirts";
  char pali[256] = "malayalam";
  char dups1[256] = "java";
  char dups2[256] = "havaheva";

  printf("The word %s can be found at pos %d in str %s \n", word,
              getSubStringIdx(str, word), str);

  printf("The anagram %s can be found at pos %d in str %s \n", anagram,
              getAnagramPos(str, word), str);

  printf("The pattern %s can be found at pos %d in str %s using rabin \n", word,
              rabinKarp(str, word), str);

  printf("Reversed string gnirts to %s \n", reverseStr(anagram));

  printf("String mamayalam is a palindrome ? %s \n", palindrome(pali));
  printf("String gnirts is a palindrome ? %s \n", palindrome(anagram));

  printf("Find duplicates in %s \n", dups1);
  getDups(&dups1[0]);
  printf("Find duplicates in %s \n", dups2);
  getDups(&dups2[0]);

  reverseMe(anagram);
  printf("%s\n",anagram);
  printf("calculated 5th power of 2 = %ld \n", calculatePower(2,5));
  return 0;
}

