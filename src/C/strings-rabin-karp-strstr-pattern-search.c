#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>



typedef enum {false, true} bool;

#define PRIME 101

long newHash(const char *str, int start, int end) {
  long hash = 0;
  //-- rabin fingerprint
  //Given an n-bit message m0,...,mn-1, we view it as a polynomial of degree n-1 over the finite field GF(2).
  // f(x) = m0 + (m1)x+ (m2)x^2 .... + (mn-1)x^n-1
  //-- v0*pow(prime,0) + v1*pow(prime,1) + v2(prime,2) ...
  for(int i = 0; i < end - start; i++ ){
    hash += ((int)str[start+i])*pow(PRIME,i);
  }

  return hash;
}

long reCalcHash(const char *str, int prev, int start, int end, long oldHash ) {
  //-- subtract the previous value
  //-- add the new value
  //-- divide by the prime
  //-- originalHash = v0*pow(prime,0) + v1*pow(prime,1) + v2(prime,2)
  long hash = oldHash - ((int)str[prev]) ;
  //-- note end is obtained by strlen (convert it to index value)
  hash += ((int)str[end-1])*pow(PRIME,(end  - start));
  //--- newHash = v0 + v1*pow(prime,0) + v2*pow(prime,1) + v3*pow(prime,2) ...
  hash = hash / PRIME;
  return hash;
}

int rabinKarp(const char *str, const char *pattern) {
  int index = -1;
  int len = strlen(pattern);
  long patternHash = newHash(pattern,0, strlen(pattern)) ;
  long strHash = newHash(str,0, strlen(pattern));
  //-- rolling hash or sliding window

  for(int i=1; i < strlen(str) - len; i++){
    if(strHash == patternHash) {
      return i;
    }
    strHash = reCalcHash(str, i - 1, i, i + len, strHash);
    printf("Orig hash %ld, calculated hash %ld @pos %d \n ",patternHash, strHash,i );
  }
  return index;
}


int main() {
  //--needle -haystack
  char str[256] ="hereismystring contains a string";
  char pattern[256] = "string";
  char nomatch[256] = " theis does not contain any matches that you are looking for";
  printf("Pattern %s is found in string %s at position %d \n",
          pattern, str,
          rabinKarp(str, pattern));
  printf("Pattern %s is found in string %s at position %d \n",
          pattern, nomatch,
          rabinKarp(nomatch, pattern));

  return 0;
}