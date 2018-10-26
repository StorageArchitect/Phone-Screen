package PhoneScreen;

public class BacktrackingConnectedIslands {

//-- you can either use visited or modify the matrix


    public static int getBiggestRegion(int[][] matrix) {
        int max = 0;
        for (int row = 0; row < matrix.length; row++) {
            for (int col = 0; col < matrix[0].length; col++) {
                max = Math.max(max, countCells(matrix, row, col));
            }
        }
        return max;
    }

    //-- recurse in 8 directions
    private static int countCells(int[][] matrix, int row, int col) {
        if (row < 0 || col < 0 || row >= matrix.length || col >= matrix[0].length) return 0;
        if (matrix[row][col] == 0) return 0;

        int count = 1;
        matrix[row][col] = 0;
        count += countCells(matrix, row + 1, col);
        count += countCells(matrix, row - 1, col);
        count += countCells(matrix, row, col + 1);
        count += countCells(matrix, row, col - 1);
        count += countCells(matrix, row + 1, col + 1);
        count += countCells(matrix, row - 1, col - 1);
        count += countCells(matrix, row - 1, col + 1);
        count += countCells(matrix, row + 1, col - 1);
        return count;
    }

    public static void main(String[] args) {
        int M[][]=  new int[][] {
                {1, 1, 0, 0, 0},
                {0, 1, 0, 1, 1},
                {1, 1, 0, 1, 1},
                {1, 0, 0, 0, 0},
                {1, 1, 1, 0, 1}
        };

        System.out.println(" The biggest region was found to be of size " + getBiggestRegion(M) );

    }
}
