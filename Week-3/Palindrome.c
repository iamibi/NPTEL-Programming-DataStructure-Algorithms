/*
 * This code checks for the suffix and prefix of a string by reversing the original string
 * and saving the result to a temporary string. And finally checking for the curresponding values
*/

char temp[100];

//reverse the string
int reverse(const char *ptr, int len)
{
    int i, j;

    for (i = len - 1, j = 0; i >= 0; i--, j++)
        temp[j] = ptr[i];

    temp[j] = '\000';

    return 0;
}

int main()
{
    int len, i, flag = 0;

    scanf ("%s", str);
    len = strlen(str);
    reverse(str, len);

    for (i = 0; i < len; i++)
    {
        if (str[i] != temp[i])
        {
            //if the start symbol is not same as the ending symbol
            if (i == 0)
                flag = 1;
            break;
        }
        printf ("%c", str[i]);
    }
    
    //print 0, if flag = 1
    if (flag)
        printf ("0");
    return 0;
}
