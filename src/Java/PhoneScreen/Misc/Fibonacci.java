package Misc;

//-- find the nth fibonacci number
//-- use recursion and then use memoization
//--  Fn = Fn-1 + Fn-2
//-- 0, 1, 1, 2, 3, 5,8 ...
public class Fibonacci {

    static int N = 30;


    static long fibonacciRecurse(int f){
        if(f<=1)
            return f;
        return fibonacciRecurse(f -1) + fibonacciRecurse(f-2);
    }

    static long  fibonnacciMemoize(int N) {
        long memo[] = new long[N + 1];
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;

        for(int i = 3; i < N+1; i++){
            memo[i] = memo[i-1] + memo[i-2];
        }

       return memo[N];
    }

    static int fibonnacciLastDigit(int N) {

        return (int)  (fibonnacciMemoize(N) % 10);

    }

    public static void main(String[] args) {
        System.out.println("Generate the first " + N + " Fibonacci Numbers");
        System.out.println();
        System.out.println("The " + N + "th fibonacci number by recursion is " + fibonacciRecurse(N));
        System.out.println("The " + N + "th fibonacci number by memoization is " + fibonnacciMemoize(N));
        System.out.println("The " + N + "last diit of the Nth fibonacci number by memoization is " + fibonnacciLastDigit(N));
    }
}
