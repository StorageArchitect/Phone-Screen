package Misc;

/****
 * sieve of Eratosthenes ( find primes up to n)
 *  1) generate numbers up to n
 *  2) find multiples of 2,3,4 ... sqrt(n), except by itself
 *  3) remaining numbers are prime ..
 *  4) The data structure to use is a bool array
 *
 ****/

public class GeneratePrimes {

    static void seiveBrute(int n) {
        //--complexity is O(n*Sqrt(n))
        boolean[] seive = new boolean[n];
        int total = 0;
        for(int i = 0; i < n; i++){
            seive[i] = true;
        }
        for(int i = 2; i <= Math.sqrt(n); i++){
            for(int j = 0; j < n; j++){
                total++;
                if((j%i == 0) && (j != i)){
                    seive[j] = false;
                }
            }
        }

        for(int i = 2; i < n; i++){
            if(seive[i] == true  ){
                System.out.print( i + " " );
            }
        }
        System.out.println();
        System.out.println("Total iterations in the inner loop " + total);

    }

    static void seiveOW(int n) {
        boolean[] seive = new boolean[n];
        int total = 0;
        for(int i = 0; i < n; i++){
            seive[i] = true;
        }

        for(int p = 2; p <= Math.sqrt(n); p++){

            if(seive[p] == true){
                //-- update all multiples of p as false
                int i = 2;
                while(true){
                  if(p*i >= n){
                        break;
                  }
                  seive[p*i] = false;
                  i++;
                  total++;
                }

            }
        }

        for(int i = 2; i < n; i++){
            if(seive[i] == true  ){
                System.out.print( i + " " );
            }
        }
        System.out.println();
        System.out.println("Total iterations in the inner loop " + total);
    }

    static void seiveOF(int n) {
        boolean[] seive = new boolean[n];
        int total = 0;
        for(int i = 0; i < n; i++){
            seive[i] = true;
        }

        for(int p = 2; p <= Math.sqrt(n); p++){

            if(seive[p] == true){
                //-- update all multiples of p as false
               for(int i = p*2; i < n; i+=p) {
                   total++;
                   seive[i] = false;
               }
            }
        }

        for(int i = 2; i < n; i++){
            if(seive[i] == true  ){
                System.out.print( i + " " );
            }
        }
        System.out.println();
        System.out.println("Total iterations in the inner loop " + total);
    }



    public static void main(String[] args) {
        int N = 256;
        System.out.println("Generate first " + N + " primes using the seive of Eratosthenes" );
        seiveBrute(N);
        seiveOW(N);
        seiveOF(N);
    }

}
