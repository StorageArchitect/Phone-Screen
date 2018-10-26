package PhoneScreen;

//-- find the nth fibonacci number
//-- use recursion and then use memoization
//--  Fn = Fn-1 + Fn-2
//-- 0, 1, 1, 2, 3, 5,8 ...
public class Fibonacci {

    static int N = 10;
    static void fibonacciPrintRecurse( int f1, int f2) {

        if(f1 == 3 ){
            System.out.print( " " + 0 + " "+ 1 + " " + 1);
            return;
        }
        fibonacciPrintRecurse(f1 -1 , f2 - 2);
        int fib = f1 + f2;
        if(fib <= N)
          System.out.print( " " + fib);

    }

    static int fibonacciRecurse(int f){
        if(f<=1)
            return f;
        return fibonacciRecurse(f -1) + fibonacciRecurse(f-2);
    }

    static int  fibonnacciMemoize(int N) {
        int memo[] = new int[N + 1];
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;

        for(int i = 3; i < N+1; i++){
            memo[i] = memo[i-1] + memo[i-2];
        }

       return memo[N];
    }


    public static void main(String[] args) {
        System.out.println("Generate the first " + N + " Fibonacci Numbers");
        fibonacciPrintRecurse(N-1, N-2);
        System.out.println();
        System.out.println("The " + N + "th fibonacci number by recursion is " + fibonacciRecurse(N));
        System.out.println("The " + N + "th fibonacci number by memoization is " + fibonnacciMemoize(N));
    }
}
