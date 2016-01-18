/*
 * This program checks whether the points are in a straight line or not.
 *
 * Points are said to lie in a straight line if the slope of any two points are equal
 * i.e., y2 - y1     y3 - y1
 *       -------  =  --------
 *       x2 - x1     x3 - x1
*/

#include <stdio.h>

int main()
{
    int x1, y1, x2, y2, x3, y3;

    //Input the points
    scanf ("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    
    //Check the slope for equality
    if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1))
        printf ("Yes");
    else
        printf ("No");

    return 0;
}
