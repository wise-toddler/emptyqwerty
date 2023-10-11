package kshitjSir;
// package kshitjSir;
public class Oct2RotRecurrsion
{
    public static void rotateMatrix(int[][] matrix) 
    {
        int n = matrix.length;
        rotate(matrix, 0, 0, n);
    }

    private static void rotate(int[][] matrix, int row, int col, int size) 
    {
        if (size <= 1)
            return;
        

        int n = size / 2;
        int[][] temp = new int[n][n];
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                temp[i][j] = matrix[row + i][col + j];

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                matrix[row + i][col + j] = matrix[row + i][col + n + j];

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                matrix[row + i][col + n + j] = matrix[row + n + i][col + n + j];
        
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                matrix[row + n + i][col + n + j] = matrix[row + n + i][col + j];
            
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                matrix[row + n + i][col + j] = temp[i][j];

        rotate(matrix, row, col, n);
        rotate(matrix, row, col + n, n);
        rotate(matrix, row + n, col + n, n);
        rotate(matrix, row + n, col, n);

    }

    private static void printMatrix(int[][] matrix) 
    {
        for (int[] row : matrix) 
        {
            for (int num : row) 
                System.out.print(num + " ");    
            System.out.println();
        }
    }
    public static void main(String[] args) 
    {
        int[][] matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 0, 1, 2},
            {3, 4, 5, 6}
        };
        rotateMatrix(matrix);
        printMatrix(matrix);
    }

}
