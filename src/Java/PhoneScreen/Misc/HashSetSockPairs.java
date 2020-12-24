package Misc;

import java.util.HashSet;

public class HashSetSockPairs {

    static void sockPairs(int n, int arr[]) {

        HashSet<Integer> socks = new HashSet<Integer>();
        int pairs = 0;
        for(int i = 0; i < n; i++){
            if(socks.contains(arr[i])){
                pairs++;
                socks.remove(arr[i]);
            } else {
                socks.add(arr[i]);
            }
        }

        System.out.println(" Found " + pairs + " of socks");

    }

    public static void main(String[] args) {
        int socks[] = {10, 20,10,30,30,20,40,90,90,100,80,30,90,20,10,100};
        System.out.println("Example to use hash set");
        sockPairs(socks.length, socks);
    }
}
