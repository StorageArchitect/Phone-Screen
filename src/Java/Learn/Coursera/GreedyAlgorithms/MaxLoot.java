package Coursera.GreedyAlgorithms;

import java.util.Arrays;
import java.util.HashMap;

/**
 * Input: The capacity of a backpack W as well as the weights (w1 ,...,wn) and per pound prices (p1 ,..., pn) of n
 * different compounds.
 * Output: The maximum total price of items that fit into the backpack of the given capacity: i.e.,
 * the maximum value of p1 · u1 + ··· + pn · un such that u1 + ··· + un ≤ W and 0 ≤ ui ≤ wi for all i
 *
 * A thief breaks into a spice shop and finds four pounds of saffron, three pounds of vanilla, and five pounds of
 * cinnamon. His backpack fits at most nine pounds, therefore he cannot take everything. Assuming that the prices of
 * saffron, vanilla, and cinnamon are $5 000, $200, and $10 per pound respectively, what is the most valuable loot in
 * this case? If the thief takes u1 pounds of saffron, u2 pounds of vanilla, and u3 pounds of cinnamon, the total price
 * of the loot is 5 000 · u1 + 200 · u2 + 10 · u3 . The thief would like to maximize the value of this expression
 * subject to the following constraints: u1 ≤ 4, u2 ≤ 3, u3 ≤ 5, u1 + u2 + u3 ≤ 9.
 *
 * caution: watch for index, practice iterating over a 2d array
 *
 * @author aahamad
 * @since 23-Dec-2020
 */
public class MaxLoot {

    /**
     * This approach uses an extra data structure to track back the weight and values
     * Alternative is to create a ivalue class with value, weight,  unit and sort this class with comparator
     * for ex
     * class Itemvalue {
     *    Double cost;
     *    double wt, val, indx;
     *    public ItemValue(int wt, int val, int ind) {
     *        this.wt = wt;
     *        this.val = val;
     *        this.indx = indx;
     *        this.cost = new Double((double) val / (double) wt);
     *    }
     *
     * }
     *
     *
     * sorting the array using comparator
     *    itemValArr[] = {new ItemValue(wt, val, idx), new ItemValue(wt,val,idx) ... };
     *    Arrays.sort(itemValArray, new Comprator<ItemValue>() {
     *       @Override
     *       public int compare(ItemValue o1, ItemValue o2) {
     *           return o2.cost.compareTo(o1.cost);
     *       }
     *    }
     *
     * @param items
     * @return
     */
    private static double calculateMaxValue(int maxWeight, int[][] items) {
        double maxVal = 0.0d;

        //-- sort the (2D array)items by their weight /values
        double[] unitValues = new double[items.length];
        HashMap<Double, Integer> valueWeightMap = new HashMap<>();
        for ( int i = 0; i< items.length; i++) {
           double unit = (double) items[i][0] / (double) items[i][1];
           unitValues[i] = unit;
           valueWeightMap.put(unit, items[i][1]);
        }

        //-- the array is sorted in natural order, which is descending
        Arrays.sort(unitValues);

        int indx = items.length - 1;
        while (maxWeight >= 0 && indx >=0) {
            int weight = valueWeightMap.get(unitValues[indx]);
            double currUnitVal  = unitValues[indx];
            if ( (maxWeight - weight) >=0 ) {
                maxVal +=  weight * currUnitVal;
                maxWeight -= weight;
            } else {
                //-- calculate fraction
                maxVal += unitValues[indx] * maxWeight;
                maxWeight = 0;

            }
            indx--;
        }
       return maxVal;
    }

    //-- this is a fractional backpack problem
    public static void main(String[] args) {
        int maxWeight = 50;
        int[][] items = { {60, 10} , {100, 40}, {120, 30}};
        System.out.println("The maximum value in the knapsack with capacity of 50 is " + calculateMaxValue(maxWeight, items) );
    }
}
