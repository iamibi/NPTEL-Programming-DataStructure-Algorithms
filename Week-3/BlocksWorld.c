/*
 * This program is similar to tower of hanoi problem, and so there is a shortcut
 * method to find the number of steps involved in rearranging the blocks
 *
 * The general formula for calculating the number of steps is as follows: (2^n) - 1
*/

#include <stdio.h>

//As the math library is not allowed, create a custom power function
int power(int x, int y)
{
    int i, result = 1;

    for (i = 1; i <= y; i++)
        result = x * result;

    return result;
}

int main(void)
{
    int n;

    scanf ("%d", &n);
    n = power(2, n);
    printf ("%d", --n);

    return 0;
}
