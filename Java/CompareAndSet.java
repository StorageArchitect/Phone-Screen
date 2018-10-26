package PhoneScreen;

import java.util.concurrent.atomic.AtomicLong;
//-- mvcc equivalent in java

public class CompareAndSet {
    private final AtomicLong largest = new AtomicLong();

    public void updateAndTrack2(long observedValue)
    {
        long oldValue, newValue;
        //-- get the current value or version
        //-- call compareAndSet till it returns true ..
        do {
            oldValue = largest.get();
            newValue = Math.max(oldValue, observedValue);
        } while (!largest.compareAndSet(oldValue, newValue));
    }

    public void updateAndTrack3(long observedValue) {
        //-- caution what happens when the value observed value is smaller ?
        largest.accumulateAndGet(observedValue, Math::max);
        //OR
        largest.updateAndGet(x -> Math.max(x, observedValue));

    }

}
