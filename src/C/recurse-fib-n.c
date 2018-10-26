//Fibonacci Series using Dynamic Programming
#include<stdio.h>

int fib(int n)
{
  /* Declare an array to store Fibonacci numbers. */
  int f[n+2];   // 1 extra to handle case, n = 0
  int i;

  /* 0th and 1st number of the series are 0 and 1*/
  f[0] = 0;
  f[1] = 1;

  for (i = 2; i <= n; i++)
  {
      /* Add the previous 2 numbers in the series
         and store it */
      f[i] = f[i-1] + f[i-2];
  }

  return f[n];
}

int fibRecurse(int n)
{
   if (n <= 1)
      return n;
   return fibRecurse(n-1) + fibRecurse(n-2);
}



int main ()
{
  int n = 9;
  printf("%d", fib(n));
   printf("%d", fibRecurse(n));
  getchar();
  return 0;
}