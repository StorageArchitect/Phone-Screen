package PhoneScreen;

public class GenerateUglyNum {

    //-- an ugly number is one only with factors of 2,3,5
    // https://www.geeksforgeeks.org/ugly-numbers/

    public static boolean isUgly(int n) {
        while(n % 2 == 0  ){
            n = n/2;
        }
        while(n % 3 == 0  ){
            n = n/3;
        }
        while(n % 5 == 0  ){
            n = n/5;
        }
        return n == 1 ? true: false;

    }

    /* Function to get the nth ugly
    number*/
    static int getNthUglyNo(int n)
    {
        int i = 1;

        // ugly number count
        int count = 1;

        // check for all integers
        // until count becomes n
        while(n > count)
        {
            i++;
            if(isUgly(i) )
                count++;
        }
        return i;
    }

    /*************************************************************************
        Function to get the nth ugly number
            initialize
           ugly[] =  | 1 |
           i2 =  i3 = i5 = 0;

        First iteration
           ugly[1] = Min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)
                    = Min(2, 3, 5)
                    = 2
           ugly[] =  | 1 | 2 |
           i2 = 1,  i3 = i5 = 0  (i2 got incremented )

        Second iteration
            ugly[2] = Min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)
                     = Min(4, 3, 5)
                     = 3
            ugly[] =  | 1 | 2 | 3 |
            i2 = 1,  i3 =  1, i5 = 0  (i3 got incremented )

        Third iteration
            ugly[3] = Min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)
                     = Min(4, 6, 5)
                     = 4
            ugly[] =  | 1 | 2 | 3 |  4 |
            i2 = 2,  i3 =  1, i5 = 0  (i2 got incremented )

        Fourth iteration
            ugly[4] = Min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)
                      = Min(6, 6, 5)
                      = 5
            ugly[] =  | 1 | 2 | 3 |  4 | 5 |
            i2 = 2,  i3 =  1, i5 = 1  (i5 got incremented )

        Fifth iteration
            ugly[4] = Min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)
                      = Min(6, 6, 10)
                      = 6
            ugly[] =  | 1 | 2 | 3 |  4 | 5 | 6 |
            i2 = 3,  i3 =  2, i5 = 1  (i2 and i3 got incremented )

        Will continue same way till I < 256

   ************************************************************************************************ */
   public static int getNthUglyNoDynamic(int n)
    {
        //-- just find numbers that are multiples of 2 * 3 * 5
        int ugly[] = new int[n];
        int i2 = 0, i3 = 0, i5 = 0;
        int next_multiple_of_2 = 2;
        int next_multiple_of_3 = 3;
        int next_multiple_of_5 = 5;
        int next_ugly_no = 1;

        ugly[0] = 1;

        //-- just generate the ugly integers
        for(int i = 1; i < n; i++)
        {
            next_ugly_no = Math.min(next_multiple_of_2,
                    Math.min(next_multiple_of_3,
                            next_multiple_of_5));

            ugly[i] = next_ugly_no;
            if (next_ugly_no == next_multiple_of_2)
            {
                i2 = i2+1;
                next_multiple_of_2 = ugly[i2]*2;
            }
            if (next_ugly_no == next_multiple_of_3)
            {
                i3 = i3+1;
                next_multiple_of_3 = ugly[i3]*3;
            }
            if (next_ugly_no == next_multiple_of_5)
            {
                i5 = i5+1;
                next_multiple_of_5 = ugly[i5]*5;
            }
        } /*End of for loop (i=1; i<n; i++) */
        return next_ugly_no;
    }

    public static void main(String[] args) {
        int N = 256;
        System.out.println("Generated the " + N + " ugly number " + getNthUglyNo(N) + " Using Brute Force" );
        System.out.println("Generated the " + N + " ugly number " + getNthUglyNoDynamic(N) + " Using Dynamic Programming");
    }

}
