package Misc;
import java.util.Arrays;
public class MaxArrayProductOfTwo {

    static int maxProductSort(int[] array){
         Arrays.sort(array);
         return array[array.length-1 ] * array[array.length-2];

    }

    static int maxProduct(int[] arr){
        //-- how to do this unsorted ?
        //-- calculate the first and second max
        int n = arr.length;
        if (n < 2)
        {
            System.out.println("No pairs exists");
            return -1 ;
        }
        int a = arr[0], b = arr[1];
        if (n == 2)
        {
           return a * b;
        }

        int posa = Integer.MIN_VALUE, posb = Integer.MIN_VALUE;

        // Iniitialize minimum and second minimum
        int nega = Integer.MIN_VALUE, negb = Integer.MIN_VALUE;

        // Traverse given array
        for (int i = 0; i < n; i++)     {
            // Update maximum and second maximum
            // if needed
            if (arr[i] > posa)
            {
                posb = posa;
                posa = arr[i];
            } else if (arr[i] > posb){
                posb = arr[i];
            }
           // Update minimum and second minimum
            // if needed
            if (arr[i] < 0 && Math.abs(arr[i]) > Math.abs(nega))   {
                negb = nega;
                nega = arr[i];
            }
            else if(arr[i] < 0 && Math.abs(arr[i]) > Math.abs(negb)){
                negb = arr[i];
            }

        }

        if (nega * negb > posa * posb) {
            System.out.println("Max product pair is {"
                    + nega + ", " + negb + "}");
            a = nega;
            b = negb;
        } else {
            System.out.println("Max product pair is {"
                    + posa + ", " + posb + "}");
            a = posa;
            b = posb;
        }
        return a * b;
    }

    public static void main(String[] args) {
        int[] array = new int[] {1,3,5,7,-9,16,32,-3, 4,6,8};

        System.out.println("Max product of two elements in sorted array " + maxProductSort(array));

        System.out.println("Max product of two elements in un sorted array " + maxProduct(array));
    }
}
