#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// To execute C, please define "int main()"

// implement calloc


// A structure to represent a stack
typedef struct Stack
{
    int top;
    unsigned capacity;
    int* array;
} Stack;

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}


void * my_calloc(int num, int size){
  //-- some sort of pre checks for over flow
  size_t total_size = num * size;
  void *ptr = malloc(total_size);
  if(ptr){
    memset(ptr,0x00,total_size);
    printf("allocated total %ld bytes \n", total_size);
  }


  return ptr;
}


typedef enum { false, true } bool;


bool isDigit(char *c) {

  return (c >= '0' && c <= '9');

}

int my_atoi(char *str) {

  bool isNegative = false;
  int val = 0;

  if(str == NULL)
      return -1;

  switch(*str){
    case '-':
      isNegative = true;
    case '+':
      str++;
    break;
  }
  while(isDigit(*str)) {
    val = (val * 10 ) + (*str - '0');
    str++;
  }

  return (isNegative ?  -1 * val : val );

}

//-- implement a queue from two stacks

void enQueue(Stack *in, int value) {
   push(in, value);
}

int deQueue(Stack *out, Stack *in) {
  //-- if the out is empty
  //-- transfer items from in to out
  if(isEmpty(out)){
    while(!isEmpty(in)) {
      push(out, pop(in));
    }
  }
  return pop(out);
}


int main() {
   struct Stack* stack = createStack(100);
   struct Stack* in = createStack(256);
   struct Stack* out = createStack(256);

   printf("converted -4234 to integer %d  \n", my_atoi("-4234"));
   printf("converted 234 to integer %d  \n", my_atoi("+234"));
   printf("converted 0iA2 to integer %d  \n", my_atoi("0iA2"));
   my_calloc(1024,sizeof(long));
   push(stack, 10);
   push(stack, 20);
   push(stack, 30);
   printf("%d popped from stack\n", pop(stack));
   for(int i = 0; i < 5; i++ ){
     printf("Enqueue %d\n",i);
     enQueue(in,i);
   }
   for(int i = 0; i < 5; i++ ){
     printf("Dequeued %d \n", deQueue(out,in));
   }

  return 0;
}
