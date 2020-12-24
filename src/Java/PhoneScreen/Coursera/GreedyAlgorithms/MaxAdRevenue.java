package Coursera.GreedyAlgorithms;

import java.util.Arrays;

/**
 * Find the maximum dot product of two sequences of numbers.
 *
 * Input: Two sequences of n positive integers: price1 ,...,pricen and clicks1 ,...,clicksn.
 * Output: The maximum * value of price1 · c1 + ··· + pricen · cn, where c1 ,..., cn is a permutation of clicks1 ,...,clicksn.
 *
 * You have n = 3 advertisement slots on your popular Internet page and you want to sell them to advertisers. They
 * expect, respectively, clicks1 = 10, clicks2 = 20, and clicks3 = 30 clicks per day. You found three advertisers
 * willing to pay price1 = $2, price2 = $3, and price3 = $5 per click. How would you pair the slots and advertisers? For
 * example, the blue pairing gives a revenue of 10·5+ 20·2+ 30·3 = 180 dollars, while the black one results in revenue
 * of 10 · 3 + 20 · 5 + 30 · 2 = 190 dollars.
 *
 * @author aahamad
 * @since 23-Dec-2020
 */
public class MaxAdRevenue {

    private static int calculateMaxRev(int slots, int[] slotClicks, int[] cpm) {
        int maxRev = 0;
        if (slots <=0 || slotClicks.length <= 0 || cpm.length <= 0) {
            throw new IllegalArgumentException("program cannot support supplied  input prameters " );
        }
        //-- cpm can be sorted but clicks are associated with the slots
        Arrays.sort(cpm);
        int clicksIdx = 0;
        int cpmIdx = cpm.length - 1;
        while(slots > 0 && clicksIdx < cpm.length && cpmIdx >= 0) {
            maxRev += slotClicks[clicksIdx++] * cpm[cpmIdx--];
            slots--;
        }
        return maxRev;
    }


    public static void main(String[] args) {
        int adSlots = 3;
        int cpm[] = {2, 3, 9};
        int slotClicks[] = {7,4,2};

        System.out.println("maximum revenue for " + "avail slots " + adSlots + " is " + calculateMaxRev(adSlots, slotClicks, cpm) );

    }
}
