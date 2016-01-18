#include <stdio.h>

int main()
{
    long int x, i = 1, res = 0;
    
    scanf ("%ld", &x);
    while (i < x)
    {
        if (x % i == 0)
            res = res + i;
        i++;
    }
    
    if (res == x)
        printf ("yes");
    else
        printf ("no");
        
    return 0;
}
