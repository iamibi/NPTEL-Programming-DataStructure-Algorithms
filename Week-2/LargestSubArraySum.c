/*
 * This program calculates the maximum sum of the contiguous sub array possible.
 * It takes in the array value and sets the maxVal and MAX to the array's first value.
 * And then we iterate through the array, taking in the new maximum value in maxVal,
 * and updating the original MAX, if necessary.
*/

#include <stdio.h>

//This function calculates the maximum of two numbers
int FindMax(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    int n, i, MAX = 0, maxVal = 0;

    scanf ("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++)
        scanf ("%d", &arr[i]);

    //Set the maximum sum to the first element of the array
    maxVal = MAX = arr[0];
    
    //repeat for finding the maximum sum
    for (i = 1; i < n; i++)
    {
        //is the maximum value the current value or an addition of previous maxVal and current array value
        maxVal = FindMax(arr[i], maxVal + arr[i]);
        
        //set the final maximum value to maximum between maxVal and current MAX
        MAX = FindMax(MAX, maxVal);
    }

    printf ("%d", MAX);

    return 0;
}
