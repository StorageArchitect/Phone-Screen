package Misc;

//-- see NQueen problem in this package for more readable and reasoned approach

public class BacktrackingQueens {
    //inspired by https://introcs.cs.princeton.edu/java/23recursion/Queens.java.html

    /***************************************************************************
     * Return true if queen placement q[n] does not conflict with
     * other queens q[0] through q[n-1]
     ***************************************************************************/
    public static boolean isValid(int[] q, int col) {
        for (int i = 0; i < col; i++) {
            if (q[i] == q[col])             return false;   // same column
            if ((q[i] - q[col]) == (col - i)) return false;   // same major diagonal
            if ((q[col] - q[i]) == (col - i)) return false;   // same minor diagonal
        }
        return true;
    }

    /***************************************************************************
     * Prints n-by-n placement of queens from permutation q in ASCII.
     ***************************************************************************/
    public static void printQueens(int[] q) {
        int n = q.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (q[i] == j){
                    System.out.print("Q ");
                }
                else {
                    System.out.print("* ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }


    /***************************************************************************
     *  Try all permutations using backtracking
     ***************************************************************************/
    public static void enumerate(int n) {
        int[] a = new int[n];
        enumerate(a, 0);
    }

    public static void enumerate(int[] q, int col) {
        int size = q.length;
        if (col == size){
            printQueens(q);
            return;
        }

        for (int i = 0; i < size; i++) {
            q[col] = i;
            if (isValid(q, col)){
                    enumerate(q, col+1);
            }
        }

    }


    public static void main(String[] args) {
        int n = 4;
        enumerate(n);

    }



}


