/*
 *
 * Optimal Solution using Dynamic Programming.
 * An easier method also exist using recursion, but the complexity is of the order of exponent.
 *
*/

int countWays(int nSteps, int step)
{
    int arr[nSteps], i, j;

    //we have skipped the stone at least once, so set first and second element to 1
    arr[0] = arr[1] = 1;
    for (i = 2; i < nSteps; i++)
    {
        //current stone is not visited, so set it to 0
        arr[i] = 0;
        
        //as soon as the current stone is skipped, set the current index value to the sum
        //of until now possible skipped stones
        for (j = 1; j <= step; j++)
            arr[i] = arr[i] + arr[i-j];
    }
    
    //return the n'th step stone
    return arr[nSteps-1];
}

void getWays(int nSteps, int ways[])
{
    ways[nSteps] = countWays(nSteps + 1, 2);
}
