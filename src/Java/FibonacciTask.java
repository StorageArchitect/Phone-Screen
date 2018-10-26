package PhoneScreen;

import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveTask;

public class FibonacciTask extends RecursiveTask<Long> {
    final long n; FibonacciTask(long n) {
        this.n = n;
    }

    protected Long compute() {
        if (n <= 1) return n;
        FibonacciTask f1 = new FibonacciTask(n - 1);
        f1.fork();
        FibonacciTask f2 = new FibonacciTask(n - 2);
        return f2.compute() + f1.join();
    }

    public static void main(String[] args) {

        FibonacciTask fibonacci = new FibonacciTask(50);
        System.out.println( "Fibonacci returned " + ForkJoinPool.commonPool().invoke(fibonacci));
    }
}
