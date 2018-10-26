package PhoneScreen;

//Write a function that computes all combinations of a powerset.
// Ex: {1, 2, 3} = {}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}
public class PowerSet {

    public static void calculateSet(int[] arr){
        int total = (int) Math.pow(2, arr.length);
        int bitmask = 0;

        for(int i = 0; i < total; i++){
            bitmask = i;
            int pos = arr.length - 1;
            System.out.print("{");
            while(bitmask != 0){
                if((bitmask & 1) == 1 ){
                    System.out.print(" " + arr[pos]);
                }
                pos--;
                bitmask >>=1;
            }
            System.out.print(" }");
            System.out.println();

        }
    }

    public static void main(String[] args) {
        int[] arr = new int[] {1,2,3};
        calculateSet(arr);

    }

}
