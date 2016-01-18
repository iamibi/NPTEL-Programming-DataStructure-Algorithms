/*
 * This program checks whether the number is perfect or not.
 * A number is said to be perfect if its subsiquent divisor would sum up to the given number
*/

#include <stdio.h>

int main()
{
    long int x, i = 1, res = 0;
    
    scanf ("%ld", &x);
    
    //Start i from 1 to x
    while (i < x)
    {
        //If i divides x completely then it is a divisor for consideration
        if (x % i == 0)
            res = res + i;      //Add it to the resulting sum
        i++;
    }
    
    //If the resulting sum is equal to the original number, then it is perfect
    if (res == x)
        printf ("yes");
    else
        printf ("no");
        
    return 0;
}
