package PhoneScreen;

import java.util.concurrent.*;
class SummationTask extends RecursiveTask<Long> {
    private final int THRESHOLD = 2;
    final long[] array;
    final int lo, hi;

    SummationTask(long[] array, int lo, int hi) {
        this.array = array;
        this.lo = lo;
        this.hi = hi;
    }

    protected Long compute() {
        if (hi - lo < THRESHOLD)
        {
            long result = 0;
            for (int i = lo; i < hi; ++i)
                result += array[i];
            return result;
        } else {
            int mid = (lo + hi) >>> 1;
            SummationTask left = new SummationTask(array, lo, mid);
            left.fork();
            SummationTask right = new SummationTask(array, mid, hi);
            long result = right.compute() + left.join();
            return result;
        }
    }

    public static void main(String[] args) throws ExecutionException, InterruptedException {
        long[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        SummationTask incrementTask = new SummationTask(array, 0, 9);
        ForkJoinPool forkJoinPool = new ForkJoinPool();
        forkJoinPool.invoke(incrementTask);
        System.out.println(incrementTask.get());
    }
}