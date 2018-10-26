#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//-- Find the time at which there are maximum guests in the party.
//-- Note that entries in register are not in any order. But the entry and exit arrays are individually sorted
//-- assume numbers are in 24 hr rormat
void maxGuests() {
 int  arrl[] = {10, 12, 18, 19, 21};
 int   exit[] = {16, 17,21, 21, 23};

  int size = sizeof(arrl)/sizeof(int);
  int maxTime;
  int maxPPl;
  int pplCount;

  // arrival increases. departure decreases
  maxTime = arrl[0];
  pplCount = maxPPl = 1;
  for(int i = 1; i < size; i++) {
    if(exit[i-1] >= arrl[i]){
      pplCount++;
      if(pplCount > maxPPl){
        maxPPl = pplCount;
        maxTime = arrl[i];
      }
    } else {
      pplCount--;
    }

  }

  printf("MAX guests %d and MAX time %d \n", maxPPl, maxTime);

}


//-- the population increases during the year of birth and decreases on death
void maxPopulation(){
 int  birth[] = {1900, 1912, 1918, 1919, 1920, 1929};
 int  death[] = {1916, 1917, 1921, 1921, 1921, 1930};

  int size = sizeof(birth)/sizeof(int);
  int maxYear;
  int maxPPl;
  int pplCount;
  maxYear = birth[0];
  pplCount = maxPPl = 1;
  for(int i = 1; i < size; i++) {
    if(death[i-1] >= birth[i]){
      pplCount++;
      if(pplCount > maxPPl){
        maxPPl = pplCount;
        maxYear = birth[i];
      }
    } else {
      pplCount--;
    }

  }

  printf("MAX guests %d and MAX population year %d \n", maxPPl, maxYear);



}

int main(){

  maxPopulation();
  maxGuests();

  return 0;
}