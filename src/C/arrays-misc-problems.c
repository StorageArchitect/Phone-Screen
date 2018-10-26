#include <stdio.h>
// [ ] find intersection of two sorted arrays
// [x] move all non zero elements to the front of array
// [x] find minimum in rotated sorted array
// [x] rotate sorted array at given position
// [x] eliminate duplicates from sorted array
// [x] convert string to integer value
// [x] power function
// [x] swap without using variable
// [x] merge two sorted arrays

//-- xor is commutative and associative
void swap(int *x, int *y) {
  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
}

long power(int x, int n ){
  if(n == 0){
    return 1;
  }
  long temp = power(x, n/2);

  if(n%2==0){
    return temp * temp;
  } else {
    return x * temp * temp;
  }

}

/* Function to left Rotate arr[] of size n by 1*/
void leftRotatebyOne(int arr[], int n);

/*Function to left rotate arr[] of size n by d*/
void leftRotate(int arr[], int d, int n)
{
  int i;
  for (i = 0; i < d; i++)
    leftRotatebyOne(arr, n);
}

void leftRotatebyOne(int arr[], int n)
{
  int temp = arr[0], i;
  for (i = 0; i < n-1; i++)
     arr[i] = arr[i+1];
  arr[i] = temp;
}

/* utility function to print an array */
void printArray(int arr[], int n)
{
  int i;
  printf("Printing rotated array: \n");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
}

/* Driver program to test above functions */
int rotateArray()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7,8,9,11,19};
   int n = sizeof(arr) / sizeof(arr[0]);
   leftRotate(arr, 2, 6);
   printArray(arr, n);
   return 0;
}

void pushZerosToEnd(int arr[], int n)
{
    int count = 0;  // Count of non-zero elements

    // Traverse the array. If element encountered is non-
    // zero, then replace the element at index 'count'
    // with this element
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            arr[count++] = arr[i]; // here count is
    // Now all non-zero elements have been shifted to
    // front and  'count' is set as index of first 0.
    // Make all elements 0 from count to end.
    while (count < n)
        arr[count++] = 0;
  printf("Processed Array: \n");
   for(int i = 0; i < n; i++){
     printf(" %d", arr[i]);
   }
}

void mergeSortedArrays(int arr1[], int arr2[], int n1,
                             int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;

    // Traverse both array
    while (i<n1 && j <n2)
    {
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    // Store remaining elements of first array
    while (i < n1)
        arr3[k++] = arr1[i++];

    // Store remaining elements of second array
    while (j < n2)
        arr3[k++] = arr2[j++];

  printf("Processed sorted array: \n");
  for(i = 0; i < n1+n2; i++){
    printf("%d ", arr3[i]);
  }
  printf("\n");
}

void recurseFind(int array[], int start, int end ){
 if(start == end) {
   printf("minmum %d", array[start]);
   return;
 }
 if(array[start] > array[end]) {
   recurseFind(array, start+1, end - 1);
 }else {
   printf("minimum %d", array[start]);
   return;
 }

}


findMinRotatedSortedArray() {
  int arr[] = {5,6,7,8,0,1,2,3,4};
  int n = sizeof(arr) / sizeof(arr[0]);
  recurseFind(arr,0, n -1);
}

removeDuplicates() {
  int array[] = {0,0,1,2,3,7,7,8,9,10,11};
  int n = sizeof(array) / sizeof(array[0]);
  int prev = 0;
  for(int i = 0; i < n; i++){
    if(array[i] != array[prev]){
      array[++prev] = array[i];
    }
  }

  printf("processed duplicates : \n");
  for(int i = 0; i< prev; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void convertToDecimal(char *str, int *value, int pos, int max) {
  char c = *str;
  //-- note how the power is calculated
  int pow = max -2 - pos;
  if(c == NULL){
      return 0;
  }
  //printf("%d + %d * %d ", *value, (c-'0'), power(10, pow) );
  *value = *value + (c -'0') * power(10,pow);
  convertToDecimal(str+1,value,pos+1, max);

}

int main() {

    int value = 0;
    char str[7]="896712";
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

        int arr1[] = {1, 3, 5, 7, 9, 12};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8, 13};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1+n2];
    mergeSortedArrays(arr1, arr2, n1, n2, arr3);

    pushZerosToEnd(arr, n);
    printf("\n2 power 3 is %ld \n", power(2,3));
    findMinRotatedSortedArray();
    removeDuplicates();
    rotateArray();
    printf("Converting %s to decimal\n", &str[0]);
    convertToDecimal(str,&value, 0,7);
    printf("Converted to Decimal %d",value);

}


