/*
 * The operator overloading and dynamic memory allocation.
 * Had a tough time cracking this one, to be frank. :P
*/

String String::operator+ (String str)
{
    String newStr;
    char temp[MAXLEN];              //declare a temporary string of MAXLEN
    int i, j;

    for (i = 0; s[i] != '\0'; i++)
        temp[i] = s[i];             //copy the contents of the first string s1
    for (j = 0; str.s[j] != '\0'; j++, i++)
        temp[i] = str.s[j];         //copy the contents of the second string s2

    temp[i] = '\000';               //put a '\0' character at the end of concatenated string

    newStr = temp;                  //copy the contents of the temporary string to the new string
    return newStr;
}

void String::replace (char oldChar, char newChar)
{
    int i;

    //replace the old character with the new one
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == oldChar)
            s[i] = newChar;
}

bool String::find (char c)
{
    int i;

    //is the character c in the string, if yes then return true
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return true;

    //else return false
    return false;
}

char * String::getCharArray()
{
    char * str = new char[size+1];
    int i;

    for (i = 0; s[i] != '\0'; i++)
        str[i] = s[i];

    str[i] = '\000';
    return str;
}
