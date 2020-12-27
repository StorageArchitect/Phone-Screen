package Misc;

import java.util.LinkedHashMap;
import java.util.Map;
import java.util.WeakHashMap;

public class LRUCache<K,V> {
    final Map<K,V> MRUdata;
    final Map<K,V> LRUdata;

    public LRUCache(final int capacity)
    {
        LRUdata = new WeakHashMap<K, V>();

        MRUdata = new LinkedHashMap<K, V>(capacity+1,
                                    0.75f, true) {
            protected boolean removeEldestEntry(Map.Entry<K,V> entry)
            {
                if (this.size() > capacity) {
                    LRUdata.put(entry.getKey(), entry.getValue());
                    return true;
                }
                return false;
            };
        };
    }

    public synchronized V tryGet(K key)
    {
        V value = MRUdata.get(key);
        if (value!=null)
            return value;
        value = LRUdata.get(key);
        if (value!=null) {
            LRUdata.remove(key);
            MRUdata.put(key, value);
        }
        return value;
    }

    public synchronized void set(K key, V value)
    {
        LRUdata.remove(key);
        MRUdata.put(key, value);
    }

}
