#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

 //https://www.geeksforgeeks.org/find-possible-words-phone-digits/
// hashTable[i] stores all characters that correspond to digit i in phone
const char hashTable[10][5] = {" ", " ", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};

// A recursive function to print all possible words that can be obtained
// by input number[] of size n.  The output words are one by one stored
// in output[]
void  printWordsUtil(int number[], int curr_digit, char output[], int n)
{
    // Base case, if current output word is prepared
    int i;
    if (curr_digit == n)
    {
        printf("%s ", output);
        return ;
    }

    // Try all  possible characters for current digit in number[]
    // and recur for remaining digits
    // printf("working on digit %d \n", number[curr_digit]);
    for (i=0; i<strlen(hashTable[number[curr_digit]]); i++)
    {
        output[curr_digit] = hashTable[number[curr_digit]][i];
        printWordsUtil(number, curr_digit+1, output, n);
        if (number[curr_digit] == 0 || number[curr_digit] == 1){
            //printf("Exiting without processing reached %d\n", number[curr_digit]);
            //return;
        }
    }
}

// A wrapper over printWordsUtil().  It creates an output array and
// calls printWordsUtil()
void printWords(int number[], int n)
{
    char result[n+1];
    result[n] ='\0';
    printWordsUtil(number, 0, result, n);
}

//Driver program
int main(void)
{
    //-- why does 911 not work
    int number[] = {9, 9, 1};
    int n = sizeof(number)/sizeof(number[0]);
    printWords(number, n);
    return 0;
}