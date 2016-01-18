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
    printf ("%ld\n", prod);
    return 0;
}
