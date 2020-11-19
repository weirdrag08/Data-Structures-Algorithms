// TO CALCULATE THE LARGEST SUBMATRIX OF ALL 0's IN A GIVEN MATRIX
#include <iostream>
using namespace std;

// int binary_matrix_helper(int start_row, int start_col, int end_row, int end_col, int* *matrix){
//     if(start_row == end_row && start_col == end_col){
//         return 0; // '0' here means that the size of the matrix is 0
//     }

//     int horizontal_size = 0;
//     int diagonal_size = 0;
//     int vertical_size = 0;

//     if(start_col < end_col){
//         horizontal_size = binary_matrix_helper(start_row, start_col + 1, end_row, end_col, matrix);
//     }

//     if(start_row < end_row && start_col < end_col){
//         diagonal_size = binary_matrix_helper(start_row + 1, start_col + 1, end_row, end_col, matrix);
//     }

//     if(start_row < end_row){
//         vertical_size = binary_matrix_helper(start_row + 1, start_col, end_row, end_col, matrix);
//     }

//      if(matrix[start_row][start_col] == 0){
//          return 1 + min(horizontal_size, min(diagonal_size, vertical_size));
//      }
//     else{
//         return 0;
//     }
// }

// int binary_matrix(int row, int col, int* *matrix){
//     int start_row = 0;
//     int start_col = 0;
//     int end_row = row - 1;
//     int end_col = col - 1;
//     return binary_matrix_helper(start_row, start_col, end_row, end_col, matrix);
// }

int max_binary_matrix(int row, int col, int **matrix)
{
    int **dp = new int *[row];
    for (int i = 0; i < row; i++)
    {
        dp[i] = new int[col];
        if (matrix[i][0] == 0)
        {
            dp[i][0] = 1;
        }
        else
        {
            dp[i][0] = 0;
        }
        if (i == 0)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }

    int max_submatrix_size = 0;

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                int prev_vertical = dp[i - 1][j];
                int prev_diagonal = dp[i - 1][j - 1];
                int prev_horizontal = dp[i][j - 1];

                int minimum = min(prev_vertical, min(prev_diagonal, prev_horizontal));
                dp[i][j] = 1 + minimum;
            }
            max_submatrix_size = max(max_submatrix_size, dp[i][j]);
        }
    }
    return max_submatrix_size;
}

int main()
{
    int row, col;
    cout << "Enter the number of rows in the array: " << endl;
    cin >> row;
    cout << "Enter the number of columns in the array: " << endl;
    cin >> col;
    cout << "Enter " << (row * col) << " elements in the array: " << endl;

    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    int sub_matrix_size = max_binary_matrix(row, col, arr);
    cout << "The largest possible size of the matrix: " << sub_matrix_size << endl;
}

