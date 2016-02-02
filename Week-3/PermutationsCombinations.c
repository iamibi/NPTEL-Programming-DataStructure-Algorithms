/*
 * For this program, the main function is pre-defined so I have not included it.
 * This program calculates the factorial, permutation and combination
*/

//Factorial function
int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return (n * fact(n - 1));
}

//Combination function
int ncr(int n,int r)
{
    int i, j, row[10] = {0};

    //value of ncr(0,0)
    row[0] = 1;
    
    // from the recurrence ncr(n, r) = ncr(n - 1, r - 1) + ncr(n - 1, r)
    for (i = 1; i <= n; i++)
        for (j = i; j > 0; j--)
            row[j] = row[j] + row[j-1];

     return row[r];
}

//Permutation function
int npr(int n,int r)
{
	return (fact(n)/fact(n - r));
}
