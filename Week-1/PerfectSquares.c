/*
 * This program finds the perfect squres that exist within [a, b]
 * This is a brute force approach. However, there is a better way also to do the same problem
 * in more optimized way. But for now this is the solution.
*/
#include <stdio.h>

int main()
{
	long int a, b, ans = 0, i;
  
    scanf ("%ld%ld", &a, &b);
    
    //Start the loop from 1
    for(i = 1; ; i++)
    {
        //break the loop as soon as the square of i is greater than b
    	if(i * i > b)
        	break;
        //check for the perfect number within the boundary and count it
        if(i * i <= b && i * i >= a)
          	ans++;
    }
    printf ("%ld", ans);
    return 0;
}
