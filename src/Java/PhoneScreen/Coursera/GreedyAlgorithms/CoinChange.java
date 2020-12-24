package Coursera.GreedyAlgorithms;

/**
 * Compute the minimum number of coins needed to change the given value into coins with denominations 1, 5, and 10.
 * Be sure to to keep an eye on index and handle edge cases, such as exact change etc
 *
 * @author aahamad
 * @since 23-Dec-2020
 */
public class CoinChange {

    private static int[] coins = {1,5,10,25,50};

    private static int calulateMinNumCoins(int change) {
        if ( change > 100 || change < 0) {
            throw new IllegalArgumentException("This program cannot make change for " + change);
        }
        int min = 0;
        int indx = coins.length-1;
        int tmp = change;
        // find the largest coin to use, then use the next coin etc
        while (tmp > 0 && indx >= 0) {
            if ( tmp >= coins[indx] ) {
                tmp -= coins[indx];
                min++;
            } else {
                indx--;
            }

        }

        return min;
    }

    public static void main(String[] args) {
        int change1 = 81;
        System.out.println("Calculated minum number of coins to make chage for " + change1 + " is " + calulateMinNumCoins(change1));
        int change2 = 99;
        System.out.println("Calculated minum number of coins to make chage for " + change2 + " is " + calulateMinNumCoins(change2));
        int change3 = 1;
        System.out.println("Calculated minum number of coins to make chage for " + change3 + " is " + calulateMinNumCoins(change3));
        int change4 = 100;
        System.out.println("Calculated minum number of coins to make chage for " + change4 + " is " + calulateMinNumCoins(change4));

    }




}
