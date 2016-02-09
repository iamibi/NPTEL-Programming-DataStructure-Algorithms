/*
 * This program evaluates the polynomial expression
 * Pi(x) = ai + x * Pi-1(x)
*/

#include <stdio.h>

int main()
{
    int n, m, k, i, res = 0;

    scanf ("%d%d%d", &n, &m, &k);
    int arr[n+1];

    for (i = 0; i <= n; i++)
        scanf ("%d", &arr[i]);

    //used the general formula
    for (i = 0; i <= m; i++)
        res = arr[i] + k * res;
    printf ("%d", res);

    return 0;
}
