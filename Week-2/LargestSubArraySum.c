#include <stdio.h>

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

    maxVal = MAX = arr[0];
    for (i = 1; i < n; i++)
    {
        maxVal = FindMax(arr[i], maxVal + arr[i]);
        MAX = FindMax(MAX, maxVal);
    }

    printf ("%d", MAX);

    return 0;
}
