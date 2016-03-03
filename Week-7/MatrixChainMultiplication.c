/*
 *
 * Matrix Chain Multiplication using Dynamic Programming. This approach is better than the recursive
 * as it avoids the Overlapping Subproblems by creating a sparse matrix which keeps the record of
 * solved problems, and that they doesn't get solved again.
*/

int MatrixOrder(int *p, int n)
{
    // Each input Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
    int m[n][n], i, j, k, l, minMult;
    // the function should be defined such that  m[1][n-1] stores the minimum number of //multiplications.

    //set the sparse matrix to 0, as no single matrix is multiplied
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            m[i][j] = 0;

    //set i to 2 for chain length
    for (i = 2; i < n; i++)
    {
        //for every position j, check the chain of length i
        for (j = 1; j < n - i + 1; j++)
        {
            k = i + j - 1;
            m[j][k] = INT_MAX;

            for (l = j; l < k; l++)
            {
                minMult = m[j][l] + m[l+1][k] + p[j-1] * p[l] * p[k];

                if (minMult < m[j][k])
                    m[j][k] = minMult;
            }
        }
    }

    return m[1][n-1];
}

int verify(int row[], int col[], int no_of_mat)
{
    // Verify, Matrix A,B,C can be multiplied in the order A*B*C.
    // returns 1-- if can be multiplied else -1

    int i;

    for (i = 0; i < no_of_mat - 1; i++)
        if (col[i] != row[i+1])
            return -1;

    return 1;
}
