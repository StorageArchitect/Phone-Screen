package Misc;

import java.util.Arrays;

//-- given an menu at ice cream parlor, find return the index of
//-- two ice creams that add up to given sum
public class IceCreamParlorTwoSum {

    public static int indexOf(int value, int[] menu, int exclude ){
        for(int i=0; i < menu.length; i++){
            if(menu[i] == value && i != exclude){
                return i;
            }
        }
        return -1;

    }

    public static void printIndex(int i, int j, int[] arr){
        int value1 = indexOf(i, arr, -1);
        int value2 = indexOf(j, arr, value1);
        System.out.println(" " + value1 + " " + value2);

    }


    public static void iceCreamIndeces(int[] arr, int target){
        int[] menu = arr.clone();
        Arrays.sort(menu);
        int i = 0;
        int j = menu.length -1;
        while((i < menu.length -1 )|| (j < 0) ){
            int price = menu[i] + menu[j] ;
            if( price > target){
                j--;
            } else if(price < target) {
                i++;
            } else {
                //-- find these values in the original menu
                System.out.println(" Found price " + price + "  @ " + i + "  " +  j);
                printIndex(menu[i],menu[j],arr);
                return;
            }

        }

        System.out.println(" None ");
    }

    public static void main(String[] args) {
        int[] array = new int[] {2,7,13,5,4,13,5};

        System.out.println("The index of two items that meet the criteria " );
        //iceCreamIndeces(array, 16);
        iceCreamIndeces(array, 15);
    }
}
