#include <stdio.h>
#include <math.h>
// [ ] Convert Roman numerals to decimal between 1 to 3999
// [x] Convert Decimal between 1 tp 3999 to Romanvalue
// [x] find all possible sub sets of array
// [x] Two sum in a sorted array. pairs whose sum is k
// [x] count all distinct pairs that the differnce is equal to k
// [x] Three sum problem with array
// [x] in sorted array of nonnegative integers, find a continous subarray which adds to a given number.
// [x] Sliding window sum ..
// [x] find the maximum profit given stock price
// [x] Given two strings as integers give their sum
// [x] Add two binary strings
// [x] Given an input array of numbers return if 180 rotation matches {1,6,9,1} matches
// [x] maximum overlapping interval given arrivals and exits
// [x] maximum population given birth and deaths
// [x] Circular queue or ring buffer
// [ ] Given 2 very large numbers represented as  array of integers, function to x, + , -

// To execute C, please define "int main()"
char *romanArray[4][9] ={
   {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
   {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
   {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
   {"M", "MM", "MMM", "",  " ", " ", " ", " ", " "}
} ;
#define MAX_VALUE 3999
#define MAX_ELEMENTS 256


void convertToRoman(int value){
  int index  = 0 ;
  int max = 4;
  int table =3;
  int valArray[max];
  if(value > MAX_VALUE || value <= 0) {
    return ;
  }

  //-- confusion -- tried to use shift, then used powers of 10
  //-- better solution is to use remainder and then divide
  //-- one approach would to modularize code into two parts,
  //-- one utility function and one algorithm ..
  while(value !=  0){
   valArray[index++] = value % 10;
    value /=10;
  }

  for(int i = 0; i < max; i++){
    index = valArray[max-1-i] ;
    if(index > 0) {
     printf("%s", romanArray[table][index - 1]);
    }
    table--;
  }
  printf("\n");

}

//-- i did not do this best done in java..
void convertToDecimal(char *str) {
  //-- use a map to store the values from str to decilmal
 /*****
   map<char, int> m = {{'I', 1}, {'V', 5},{'X', 10},{'L', 50},
        {'C', 100},{'D', 500},{'M', 1000}};

        int total = 0;
        for(int i = 0; i < s.length(); i++){
            if(m[s[i+1]] <= m[s[i]])  total += m[s[i]];
            else  total -= m[s[i]];
        }
        return total;

  *****/



}

void powerSet() {
   /**
         * base cases {} and {123}
         * the subsets are {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}
         * general case total 2^n for an set of {abc}
         * 000 => {}
         * 001 => {c}
         * 010 => {b}
         * 011 => {bc}
         * 100 ={a}
         * 101 = {ac}
         * 110 = {bc}
         * 111 = {abc}
         */
        // Run a loop for printing all 2^n
        // subsets one by one
  int array[] = {1,2,3};
  // there are 2^3 subsets
  int size = (sizeof(array)/sizeof(int));
  int max = pow(2,size);

  for(int i = 0; i < max; i++){
    int pos = size -1;
    int bitmask = i;
    printf("{ ");
    while(bitmask > 0)
     {
        if(1 == (bitmask & 1)){
            printf("%d ",array[pos]);
        }
        bitmask >>= 1;
        pos--;
     }
    printf("} ");

  }
}

//-- if the values are small between 1 and 65536 and problem wants the value not index
//-- if the array is sorted
void twoDiffHash( ){
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
      #if 0 // dont need this in sorted array this is a forward looking algorithm..
        if (x - diff >= 0 && hashmap[x - diff]){
           printf("found {%d,%d} that forms diff %d \n",x , x-diff, diff);
        }
      #endif
        if (x + diff < 65536 && hashmap[x + diff]) {
           printf("found {%d,%d}  that forms diff %d \n",x, x+diff, diff);
        }
        hashmap[x] = 0;
    }

}



void twoDiffTable( ){
  int hashmap[65536] = {0};
  int array[] = {0,2,1,3,6,7,8,9,11,14,17,19};
  int diff = 5;
  int size = sizeof(array)/sizeof(int);

    // backward looking algorithm
    for (int i = 0; i < size; i++)
    {
        int x = array[i];
        if (x - diff >= 0 && hashmap[x - diff]){
           printf("found {%d,%d} that forms diff %d \n",x , x-diff, diff);
        }
        hashmap[x] = 1;
    }

}

void twoSumTable() {
  int table[65536] = {0};
  int array[] = {0,1,2,3,6,8,9,11,12,14,17,19};
  int sum = 20;
  int size = sizeof(array)/sizeof(int);
  for (int i = 0; i < size; i++)
   {
      int x =  array[i];
      // -- this is a backward looking algorithm
      if (sum - x >= 0 && table[sum -x] == 1) {
        printf("found {%d,%d} that forms sum %d \n", array[i],sum-x,sum);
      }
      table[x] = 1;
  }

}

// find all the pairs of index that form a given value
void twoSumBrute() {
  int array[] = {0,1,2,3,6,8,9,11,12,14,17,19};
  int sum = 20;
  int size = sizeof(array)/sizeof(int);
  int sArray[size];

  for(int i = 0; i < size; i++) {
    sArray[i] = sum - array[i];
  }

  for(int i = 0; i < (size/2 +1); i++){
    for(int j = 0; j < size; j++){
      if(array[i] == sArray[j]){
        printf("found index {%d,%d}  that forms sum %d \n", i, j,sum);

      }
    }
  }

}

//-- Three Sum problem, given an array of n integers, where elements a,b,c such that a+b+c = 0
//-- find all unique triplets which give a sum of zero
//-- assume a sorted array
void threeSum() {
  int s[] = {-2,-1,0,1, 2, 3, 4};
  //-- {-2,-1,3}, {-1,0,1}, {-2,0,2}
  //-- caution with converting size into index ..
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


//-- caution pay attention to the index that is inremented in nested loops
void slidingWindowSum(int target, int w){
 int array[] = {1,3,5,7,8,9,11,13,14,16,19,20,21,22,24};
 int size = sizeof(array)/ sizeof(int);
 int sum = 0;
  printf("Sliding Window: \n");

  for(int i=0; i < w; i++){
   sum += array[i];

  }

  for(int i = 1; i< size - w; i++ ){
    if(sum == target){
      printf("Found a window of range  %d - %d with desired sum %d \n", i-w, i-1, target);
    }
    sum -=array[i-1];
    sum +=array[i];

  }

}



//-- caution pay attention to the index that is inremented in nested loops
void expandingWindowSumBrute(int target) {
 int array[] = {1,3,5,7,8,9,11,13,14,16,19,20,21,22,24};
 int size = sizeof(array)/ sizeof(int);

  printf("Expanding Window Brute: \n");

  for(int i =0; i < size; i++ ){
    int l = i+1;
    int sum = array[i];
    while(l < size){
       if(sum > target ) {
         break;
       } else if(sum == target) {
         printf("found contigious range (%d - %d) with desired sum %d \n",i, l-1, sum, target);
           break;
       }
       sum+=array[l];
       l++;
    }
  }

}

//-- caution pay attention to the index that is inremented in nested loops
void expandingWindowSum(int sum) {
 int array[] = {1,3,5,7,8,9,11,13,14,16,19,20,21,22,24};
 int size = sizeof(array)/ sizeof(int);

  printf("Expanding Window: \n");
  /* Initialize curr_sum as value of first element      and starting point as 0 */
    int curr_sum = array[0];
    int start = 0;

    /* Add elements one by one to curr_sum and if the curr_sum exceeds the
       sum, then remove starting element */
    for (int i = 1; i <= size; i++)
    {
        // If curr_sum exceeds the sum, then remove the starting elements
        while (curr_sum > sum && (start < i-1)) {
            curr_sum -=  array[start];
            start++;
        }

        // If curr_sum becomes equal to sum, then return true
        if (curr_sum == sum) {
            printf ("Sum found between indexes (%d - %d) with desired sum %d \n", start, i-1,sum);
            return;
        }

        // Add this element to curr_sum
        if (i < size){
          curr_sum += array[i];
        }
    }

    // If we reach here, then no subarray
    printf("No subarray found");
    return 0;


}


void maxDiff( ){
  int arr[] = {1, 2, 6, 80, 100, 189, 981, 900,1000};
  int size = sizeof(arr)/sizeof(arr[0]);

  int max_diff = arr[1] - arr[0];
  int min_element = arr[0];
  int i;
  for(i = 1; i < size; i++)
  {
    if (arr[i] - min_element > max_diff){
      max_diff = arr[i] - min_element;
    }
    if (arr[i] < min_element){
         min_element = arr[i];
    }
  }
  printf("The maximum difference is %d\n",max_diff);
}

/*
The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days. For example, if the given array is {100, 180, 260, 310, 40, 535, 695}, the maximum profit can earned by buying on day 0, selling on day 3. Again buy on day 4 and sell on day 6. If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.
*/
void maxProfit() {

  int price[] = {100, 180, 260, 310, 40, 535, 695, 10};
  int n = sizeof(price)/sizeof(price[0]);
  int minima;
  int maxima;

  minima = maxima = price[0];
  int i =1;
  while(1){
    if(price[i] > maxima){
      maxima = price[i];
    }
    if(price[i] < minima){
      minima = price[i];
    }
    //-- when to trigger a sell
    if((price[i+1] < maxima)){
      printf("Sold the stock @ %d for a profit of %d \n",maxima, maxima - minima);
      maxima = minima= price[i+1];
    }

    if(i == n-1){
      if( maxima > minima){
        printf("Sold the stock @ %d for a profit of %d \n",maxima, maxima - minima);
      }
      break;
    }
   i++;

  }

}

/**`

    This implies that if there was a better solution possible,
    it will definitely have the Height greater than    min(a1, aN).
    Base * Height > (N-1) * min(a_1, a_N)
    We know that, Base min(a1, aN)
    This means that we can discard min(a1, aN) from our set and look to solve this problem again from the start.
    If a1 < aN, then the problem reduces to solving the same thing for a2, aN.
    Else, it reduces to solving the same thing for a1, aN-1

**/

void maxArea()
{
    int array[] = {3, 1, 2, 4, 5};
    //-- h * b = 3 * 4 (height capped @ 3) (dist between 3 -5)
    int size = sizeof(array)/sizeof(int);
    int l = 0;
    int r = size -1;
    int area = 0;
    //-- non-negative integers a_1, a_2, ..., a_n where each represents a point at coordinate (i, a_i)
    // vertical lines are drawn from 0 (the content of the array represents the height), the distance between
    // them is 1 unit, ie the distance between 4-5 is 1 unit and 3 - 4 is 3 units,

    while (l < r)
    {
        // Calculating the max area
        area = fmax(area, fmin(array[l],
                        array[r]) * (r - l));

            if (array[l] < array[r]){
                l += 1;
            }    else {
                r -= 1;
            }
    }
    printf("Max Area found to be %d \n", area);
}

//-- ring buffer or circular queue
typedef struct Queue {
  int tail;
  int head;
  int * items[MAX_ELEMENTS];
  int size;
} queue;

void enQueue(queue *q, void *item) {
  if(q->tail > MAX_ELEMENTS){
    //-- reset the tail
    q->tail = 0;
  }
  q->items[q->tail++] = item;
  q->size++ ;
}

void * deQueue(queue *q){
 void *item;
  if(q->head <= MAX_ELEMENTS){
   item =  q->items[q->head++];
  } else {
    q->head = 0;
  }
  q->size--;
}

void createQueue(queue **q) {

  *q = (queue *) malloc(sizeof(queue));
 ((queue *) *q)->size = ((queue *) *q)->tail =  ((queue *) *q)->head = 0;

}

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

void maxPopulation() {
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


//-- assume that both size are equal -- there is a seperate algorithm when they are not
//-- when decrementing be sure to see that the index is below zero before breaking
void stringSum() {
  char val1[] = "23456789101112001";
  char val2[] = "98765342142324001";
  // expected   122222131243436002
  int size = strlen(val1); // assume string1 and string 2 are same size
  char result[256]={'\0'};
  int carry=0;
  int tmp;
  printf("String Size %d \n", size);
  int i = size-1;
  while(1){
    tmp = (val1[i] - '0') + (val2[i] - '0') + carry;
    carry = tmp / 10;
    result[i+1] = tmp%10 + '0';
    i--;
    if(i<0){
     break;
    }
    if(carry != 0){
      result[0] = carry + '0';
     }
  }

  printf("Calculated string sum %s", result);
}


void binaryStringAddition(){
  char val1[] = "10101010101010110";
  char val2[] = "10101010101001010";
  // expected   101010101010100000
  int size = strlen(val1); // assume string1 and string 2 are same size
  char result[256]={'\0'};
  int carry=0;
  int tmp;
  printf("String Size %d \n", size);
  int i = size-1;
  while(1){
    tmp = (val1[i] - '0') + (val2[i] - '0') + carry;
    carry = tmp / 2;
    result[i+1] = tmp%2 + '0';
    i--;
    if(i<0){
     break;
    }
    if(carry != 0){
      result[0] = carry + '0';
     }
  }

  printf("Calculated binary string sum %s \n", result);

}

void validMirror(int array[], int size) {
  int valid[] = {1,1,0,0,0,0,1,0,1,1};
  int j = size -1;
  for(int i = 0; i< size; i++){
    if(valid[array[i]] == 0){
      printf("valid check failed, bad values %d, %d found @ %d and %d\n",array[i], array[j], i, j);
      return;
    }
    if(array[i] != array[j]){
      if( (array[i]!= 6 && array[j] != 9) || (array[i] != 9 && array[j] != 6) ){
        continue;
      } else {
        printf("Array is invalid,  bad values %d, %d found\n",array[i], array[j]);
        return;
     }

    }
    j--;

  }
  printf("Arrays are valid \n");

}

int main() {
  int validArray[] = {1,6,8,0,0,8,9,1};
  int invalidArray[] = {5,1,6,8,0,0,8,9,1,5};
  convertToRoman(3998);
  convertToRoman(3008);
  powerSet();
  printf("Two Sum Brute \n");
  twoSumBrute();
  printf("Two Sum Table \n");
  twoSumTable();
  printf("Two diff Table \n");
  twoDiffTable();
  twoDiffHash();
  printf("Looking for triplets \n");
  threeSum();
  slidingWindowSum(23, 4);
  expandingWindowSumBrute(23);
  expandingWindowSum(23);
  maxDiff();
  maxProfit();
  maxArea();
  maxGuests();
  maxPopulation();
  stringSum();
  binaryStringAddition();
  validMirror(validArray, sizeof(validArray)/ sizeof(int));
  validMirror(invalidArray, sizeof(invalidArray)/ sizeof(int) );

  return 0;
}

