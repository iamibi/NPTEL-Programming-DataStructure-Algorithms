/*
 * The approach in this program is to first check whether the string lengths are equal or not.
 * if they are not equal, then they are not permutations of each others.
 * else if they have equal length, sort the string alphabetically and check for the unequal character.
*/

#include <stdio.h>
#include <string.h>

int sort(char *, int);

int main()
{
    char str1[101], str2[101];
    int i, len;

    scanf ("%s%s", str1, str2);

    if (strlen(str1) != strlen(str2))
    {
        printf ("no");
        return 0;
    }

    len = strlen(str1);
    
    //Sort both the strings alphabetically
    sort (str1, len);
    sort (str2, len);

    for (i = 0; i < len; i++)
    {
        //if there is an unmatching character, then string is not a permutation
        if (str1[i] != str2[i])
        {
            printf ("no");
            return 0;
        }
    }

     printf ("yes");
     return 0;
}

//Sort the string using shell sort
int sort(char *chars, int n)
{
    register int i, j, space, k;
    char x, a[5];

    a[0]=9;
    a[1]=5;
    a[2]=3;
    a[3]=2;
    a[4]=1;

    for(k = 0; k < 5; k++)
    {
        space = a[k];
        for(i = space; i < n; i++)
        {
            x = chars[i];
            for(j = i - space; (x < chars[j]) && (j >= 0); j = j - space)
                chars[j+space] = chars[j];
            chars[j+space] = x;
        }
    }
    return 0;
}
