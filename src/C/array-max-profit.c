#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//https://www.geeksforgeeks.org/stock-buy-sell/
// solution structure
typedef struct intr
{
    int buy;
    int sell;
}Interval;

// This function finds the buy sell schedule for maximum profit
void stockBuySellDays()
{
  int price[] = {100, 180, 260, 310, 40, 535, 695, 10};
  int n = sizeof(price)/sizeof(price[0]);
    // Prices must be given for at least two days
    if (n == 1) {
            return;
    }

    int count = 0; // count of solution pairs
    // solution vector
    Interval sol[n/2 + 1];
    // Traverse through given price array
    int i = 0;
    while (i < n-1)
    {
        // Find Local Minima. Note that the limit is (n-2) as we are
        // comparing present element to the next element.
        while ((i < n-1) && (price[i+1] <= price[i]))
            i++;
        // If we reached the end, break as no further solution possible
        if (i == n-1)
            break;
        // Store the index of minima
        sol[count].buy = i++;
        // Find Local Maxima.  Note that the limit is (n-1) as we are
        // comparing to previous element
        while ((i < n) && (price[i] >= price[i-1]))
            i++;
        // Store the index of maxima
        sol[count].sell = i-1;
        // Increment count of buy/sell pairs
        count++;
    }

    // print solution
    if (count == 0)
        printf("There is no day when buying the stock will make profitn");
    else
    {
       for (int i = 0; i < count; i++)
          printf("Buy on day: %d\t Sell on day: %d \n", sol[i].buy, sol[i].sell);
    }

    return;
}


void maxStockProfit(){
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

int main() {

  maxStockProfit();
  stockBuySellDays();

  return 0;
}