/*
 * This program counts the depth of the letter.
 * The concept is to first initialise a count to 0 and then
 * incrementing it every time a '(' occurs and
 * decrementing it every time a ')' occurs and
 * finally, printing the value of count if a letter occurs.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[101];
    int i, len, count = 0;

    scanf ("%s", str);
    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        //if the current character is '(', increase the counter value by one
        if (str[i] == '(')
            count = count + 1;
            
        //else if the current character is ')', decrease the counter value by one
        else if (str[i] == ')')
            count = count - 1;
            
        //else if the current character is an alphabet, just print the current value of count
        else
            printf ("%d ", count);
    }
    
    //Append '#' at the end of the string
    printf ("#");
    return 0;
}
