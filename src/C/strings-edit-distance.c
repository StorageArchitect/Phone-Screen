#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

/*************************************************************************

An edit between two strings is one of the following changes.

    Add a character
    Delete a character
    Change a character

Given two string s1 and s2, find if s1 can be converted to s2 with exactly one edit.
Expected time complexity is O(m+n) where m and n are lengths of two strings.


Let the input strings be s1 and s2 and lengths of input
strings be m and n respectively.

1) If difference between m an n is more than 1,
     return false.
2) Initialize count of edits as 0.
3) Start traversing both strings from first character.
    a) If current characters don't match, then
       (i)   Increment count of edits
       (ii)  If count becomes more than 1, return false
       (iii) If length of one string is more, then only
             possible  edit is to remove a character.
             Therefore, move ahead in larger string.
       (iv)  If length is same, then only possible edit
             is to  change a character. Therefore, move
             ahead in both strings.
    b) Else, move ahead in both strings.
*****************************************************************************/
void isStringEditDistanceAway(){
  char str1[] ="firstString";
  char str2[] ="xirstString";
 int len1 = strlen(str1);
 int len2 = strlen(str2);
 int i = 0, j=0;
 int count = 0;
  while(i < len1 && j < len2){
   if(str1[i] != str2[j]) {
    if(len1 > len2) {
     i++;
    } else if(len1 < len2) {
      j++;
    } else {
      i++; j++;
    }
    count++;
    if(count > 1){
      printf("Sorry String %s is %d edit distance away from %s \n",str2,  count, str1);
      return;
    }
   } else {
     i++;
     j++;
   }

  }
  if(i < len1 || j < len2)
    count++;

  printf("The string %s is only %d edit distance away from %s\n", str2, count,str1);

}



int main() {
  isStringEditDistanceAway();
  return 0;
}