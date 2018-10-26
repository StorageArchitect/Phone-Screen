#include <stdio.h>

// To execute C, please define "int main()"
//-- implement a min heap
//--- root element is the smallest and will always be at position 0
//-- relation ship are
//--- PARENT = (index  -   1  )/2
//--  LCHILD = (index * 2  + 1)
//--  RCHILD = (index * 2  + 2)
//-- heapify will make the parent smaller (min heap) than the child via swap
//-- insert alway goes to empty spot, lef to right, top to bottom

#define MAX_ELEMENTS 256
//-- methods to get index
#define LCHILD_IDX(IDX) ( IDX * 2 + 1)
#define RCHILD_IDX(IDX) ( IDX * 2 + 2)
#define PARENT_IDX(IDX) ( IDX - 1 ) / 2
//-- methods to get element
#define GET_LCHILD(IDX, ITEMS) ( ITEMS[LCHILD_IDX(IDX)] )
#define GET_RCHILD(IDX, ITEMS) ( ITEMS[RCHILD_IDX(IDX)] )
#define GET_PARENT(IDX, ITEMS) ( ITEMS[PARENT_IDX(IDX)] )
//-- some test methods
#define HAS_LEFT_CHILD(IDX, SIZE) (LCHILD_IDX(IDX) > SIZE ? 0 : 1  )
#define HAS_RIGHT_CHILD(IDX, SIZE) (RCHILD_IDX(IDX) > SIZE ? 0 : 1  )
#define HAS_PARENT(IDX) (PARENT_IDX(IDX) < 0 ? 0 : 1  )
//-- using gcc extension swap two values ..
#define SWAP_VAL(x, y) do { typeof(x) SWAP = x; x = y; y = SWAP; } while (0)


//-- global size
int g_size = 0;

void swapElements(int *array, int idxOne, int idxTwo) {
  int temp = array[idxOne];
  array[idxOne] = array[idxTwo];
  array[idxTwo] = temp;
  printf(" %d @ %d --> %d @ idx %d \n", array[idxOne], idxTwo, array[idxTwo], idxOne);

}
//-- swap element with child, you start with left by convention
void heapifyDown(int *array) {
  int index = 0;
  printf("heapifyDown \n");

  while(index < g_size) {
    //-- compare the item with both the children
    int smallerChildIDX = LCHILD_IDX(index);
    //-- if the left child is larger than right child the right is the smaller
    if(HAS_RIGHT_CHILD(index,g_size) && GET_RCHILD(index, array) < GET_LCHILD(index, array) ) {
      smallerChildIDX = RCHILD_IDX(index);
    }
    if(array[index] > array[smallerChildIDX]) {
       swapElements(array, index, smallerChildIDX);
    } else {
      break;
    }
    index = smallerChildIDX;
    printf("index is currently %d \n", index);

  }


}

//-- swap element with its parent
void heapifyUp(int *array) {
  int index = g_size - 1;
  //-- if there is a parent and the parent is bigger than my current pos
  //-- swap me with my parent
  while(HAS_PARENT(index) && GET_PARENT(index, array) > array[index] ) {
     swapElements(array, PARENT_IDX(index), index);
     index = PARENT_IDX(index);
  }

}

//-- look into the array and return the root
int peek(int *array) {
 if (g_size > 0){
    return array[0];
 }
   return -1;
}
//-- look into the array and remove and return item
int poll(int *array) {
  int item;
  //-- bug the last element cannot be removed ..
 if (g_size >= 0){
    //-- get the very last element from the array and move it to position zero
    item = array[0];
    array[0] = array[--g_size];
    //-- heapify the array
    heapifyDown(array);

    return item;
 }

  return -1;

}

void add(int *array, int item) {
  if( g_size > MAX_ELEMENTS  )
      return;
  array[g_size++] = item;
  //-- heapify up
  heapifyUp(array);
}


int main() {
  int array[MAX_ELEMENTS];
  g_size = 0 ;
  add((int *) &array, 13);
  add((int *) &array, 23);
  add((int *) &array, 31);
  add((int *) &array, 43);
  add((int *) &array, 53);
  add((int *) &array, 30);
  add((int *) &array, 12);
  add((int *) &array, 8);
  add((int *) &array, 9);
  add((int *) &array, 1);

  printf("current Min element: %d \n",peek((int *) &array));
  int total = g_size;
  for (int i = 0; i < total; i++) {
     printf(" %d", array[i]);
  }
  printf("\n");
  total = g_size;
  for (int i = 0; i < total; i++) {
     printf("\n Removed min element %d \n", poll(&array));
  }

  return 0;
}
