/*
 * This program prints the 2D array aka matrix in spiral order
*/

#include <stdio.h>

int main()
{
    register int i = 0, j = 0, row = 0, column = 0;
    int m, n;

    scanf ("%d%d", &m, &n);
    int arr[m][n];

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf ("%d", &arr[i][j]);

    for (column = row = 0; row < m && column < n; )
    {
        //print the first row from the available rows
        for (i = column; i < n; i++)
            printf ("%d ", arr[row][i]);
            
        //increment the rows counter
        row++;
        
        //print the last column from the available columns
        for (i = row; i < m; i++)
            printf ("%d ", arr[i][n-1]);
            
        //decrement the number of columns
        n--;
        
        //print the last row from the current rows
        if (row < m)
        {
            for (i = n - 1; i >= column; i--)
                printf ("%d ", arr[m-1][i]);

            //decrement the number of rows
            m--;
        }
        
        //print the first column from the current columns
        if (column < n)
        {
            for (i = m - 1; i >= row; i--)
                printf ("%d ", arr[i][column]);

            //increment the columns counter
            column++;
        }
    }
    return 0;
}
