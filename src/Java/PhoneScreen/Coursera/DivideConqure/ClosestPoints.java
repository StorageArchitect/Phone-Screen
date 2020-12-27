package Coursera.DivideConqure;
import static PhoneScreen.Utils.*;

/**
 * Closest Points Problem Find the closest pair of points in a set of points on a plane.
 *
 * Input: A set of points on a plane.
 * Output: The minimum distance between a pair of these points.
 *
 * @author aahamad
 * @since 24-Dec-2020
 */
public class ClosestPoints {

    private static double closestPair(int[][] inputArray) {
        double closestDistance = 0.0d;

        return closestDistance;
    }

    public static void main(String[] args) {
        int[][] inputArray = {{4,4}, {-1,-3},{-2,-2},{-3,-4}, {2,3}, {-4,0}, {1,1}, {-1, -1}, {3,-1}, {-4,2}, {-2,4} };
        printArray(inputArray);
        System.out.println("Calculate the closest points " + closestPair(inputArray) );

    }
}
