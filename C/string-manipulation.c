#include <stdio.h>
#include <string.h>
#include <math.h>


//[x]    Generate all permutations of a given String
//[x]    Substrings of a given String
//[x]    Reversing a given String
//[x]    String Compression
//[x]    String Rotation
//[x]    is rotated string;
//[x]    Edit distance
//[x]    Merge Sorted array
//[x]   URLfy string
typedef int bool;
#define true 1
#define false 0


// To execute C, please define "int main()"
void mergeSortedArrays(){
  int array1[] = {0,2,4,6};
  int array2[] = {1,3,7,9,11};
  int size1= sizeof(array1)/sizeof(int);
  int size2 = sizeof(array2)/sizeof(int);
  int newArray[size1 + size2];
  int i = 0, j=0, k = 0;

  printf("mergeSortedArrays \n");
  while(1){
   if(array1[i] < array2[j]) {
     newArray[k] = array1[i];
     if(i < size1){
       i++;
       k++;
     }
   } else {
     newArray[k] = array2[j];
     if(j < size2){
      j++;
      k++;
     }
   }
    if(i >= (size1) && j >= (size2)){
      break;
    }

  }

 for(i = 0; i < size1 + size2; i++){
         printf("%d ", newArray[i]);
  }
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int n)
{
   int i;
   if (l == n) {
     printf("%s\n", a);
   }
   else
   {
       for (i = l; i <= n; i++)
       {
          swap(&a[l], &a[i]);
          permute(a, l+1, n);
          swap(&a[l], &a[i]); //backtrack
       }
   }
}

void allPermutations(){
  //-- algorithm, swap the i,j th elements for the size of the string.
  //  A string of length n has n! permutation.
  // -- for {i=0,j=0}, {i=0,j=1}, {i=1,j=0} ...
  char str[] = "ABC"; //-- values are {ABC} {ACB}  ...
  char len = strlen(str);
  // len -1 is require to avoid duplicates
  permute(str,0, len-1 );

}

// Given a string as an input.
// We need to write a program that will print all non-empty substrings of that given string.
void printAllSubStrings() {
  char str[] = "abc";
  int total = pow(2,strlen(str));
  int bitMask=total-1;

  while(1) {
    printf("{");
    for(int i = 0; i < strlen(str); i++){
      if(bitMask & 1 ){
        printf("%c",str[i]);
      }
      bitMask >>=1;
    }
    printf("}");
    bitMask = --total;
    if(total <= 0){
      break;
    }
  }
}

bool isSubString(char *str1, char *str2) {
  return strstr(str1,str2) == NULL ? false : true;
}

void isRotatedString(){
  char str1[]="waterbottle";
  char str2[]="erbottlewt";
  char str[strlen(str1) + strlen(str2)];
  strcpy(str,str1);
  strcat(str,str1);
  bool value = isSubString(str,str2);
  printf("String %s is a rotation of %s ? %d\n",str2,str1,value);
}

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
      printf("Sorry String is %d edit distance away \n", count);
      return;
    }
   } else {
     i++;
     j++;
   }

  }
  if(i < len1 || j < len2)
    count++;

  printf("The string is only %d edit distance away \n", count);

}

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

void compressString(){
  char str[] = "runnyyyyssstrinnnng ";
  int count = 0;
  int prev = 0;
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


void urlfy() {
  char str[] = "replace blanks in this string               "; // this string has adequate spaces for in place
  // count spaces and find current length
    int space_count = 0, i;
    for (i = 0; str[i]; i++)
        if (str[i] == ' ')
            space_count++;

    // Remove trailing spaces
    while (str[i-1] == ' ')
    {
       space_count--;
       i--;
    }

    // Find new length.
    int new_length = i + space_count * 2 + 1;

    // Start filling character from end
    int index = new_length - 1;

    // Fill string termination.
    str[index--] = '\0';

    // Fill rest of the string from end
    for (int j=i-1; j>=0; j--)
    {
        // inserts %20 in place of space
        if (str[j] == ' ')
        {
            str[index] = '0';
            str[index - 1] = '2';
            str[index - 2] = '%';
            index = index - 3;
        }
        else
        {
            str[index] = str[j];
            index--;
        }
    }


  printf("URLfy string %s\n", str);
}


//-- strlen will return length without the \0
//-- index is always going to be len -1 because index starts @ 0
void reverseStr(){
  char str[]="reverseMePls";
  int len = strlen(str)-1;
  for(int i = 0; i< len/2; i++){
    swap(&str[i],&str[len -i]);
    printf("%c",str[i]);
  }
  printf("\nReversed string %s", str);


}

/**************************************************************************
Given a NxN matrix with 0s and 1s. Set every row that contains a 0 to all 0s
and set every column that contains a 0 to all 0s.

For example

1 0 1 1 0
0 1 1 1 0
1 1 1 1 1
1 0 1 1 1
1 1 1 1 1

results in

0 0 0 0 0
0 0 0 0 0
0 0 1 1 0
0 0 0 0 0
0 0 1 1 0

***************************************************************************/
void nullifyRow(int matrix[5][5], int row ){

  for(int i = 0; i < 5; i++){
    matrix[row][i] = 0;
  }

}

void nullifyCol(int matrix[5][5], int col){
  for(int i = 0; i < 5; i++){
    matrix[i][col] = 0;
  }

}
void twoDArray(){
  int matrix[5][5]= { {1,0,1,1,1}, {1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,1,0} };
  bool row[5] = {{false}};
  bool col[5] = {{false}};

  //-- find the size of this matrix ?
int rows = sizeof(matrix) / sizeof(matrix[0]);
int cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);
printf("Size of matrix is %d Rows x %d columns\n", rows, cols );

  for(int i =0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(matrix[i][j] == 0){
        row[i] = true;
        col[j] = true;
      }
    }
  }


  for(int i = 0; i < 5; i++){
    if(row[i] == true){
      nullifyRow(&matrix[0][0],i);
    }
  }


  for(int i = 0; i < 5; i++){
    if(col[i] == true){
      nullifyCol(&matrix[0][0],i);

    }
  }

  for(int i =0; i < 5; i++){
    printf("{ ");
    for(int j = 0; j < 5; j++){
      printf("%d, ",matrix[i][j]);
    }
    printf(" }");
    printf("\n");
  }


}

/****
Let the given matrix be
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

First we find transpose.
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16

Then we reverse elements of every column.
4 8 12 16
3 7 11 15
2 6 10 14
1 5  9 13
****/

// After transpose we swap elements of column
// one by one for finding left rotation of matrix
// by 90 degree
void reverseColumns(int arr[5][5])
{
    for (int i=0; i<5; i++)
        for (int j=0,  k=5-1; j<k; j++,k--)
            swap(&arr[j][i], &arr[k][i]);
}


// Function for do transpose of matrix
void transpose(int arr[5][5])
{
    for (int i=0; i<5; i++)
        for (int j=i; j<5; j++)
            swap(&arr[i][j], &arr[j][i]);
}

// Function to anticlockwise rotate matrix
// by 90 degree
void rotate90()
{
    int arr[5][5]= { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25} };
    transpose(arr);
    reverseColumns(arr);

  printf("Rotate matrix 90 \n");
  for(int i =0; i < 5; i++){
    printf("{ ");
    for(int j = 0; j < 5; j++){
      printf("%d, ",arr[i][j]);
    }
    printf(" }");
    printf("\n");
  }
}


int  main() {

  //mergeSortedArrays();
  urlfy();
  rotateString();
  allPermutations();
  printAllSubStrings();
  reverseStr();
  compressString();
  isRotatedString();
  isStringEditDistanceAway();
  twoDArray();
  rotate90();


  return 0;

}