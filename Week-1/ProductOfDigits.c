/*
 * This program is very basic. Just divide the given number with 10 until
 * it becomes 0 and multiply the number to the result modulo 10.
*/
#include <stdio.h>

int main()
{
    long int n, prod = 1;
    
    scanf ("%ld", &n);
    while (n != 0) 
    {
        prod *= n % 10;
        n /= 10;
    }
    printf ("%ld", prod);
    return 0;
}
