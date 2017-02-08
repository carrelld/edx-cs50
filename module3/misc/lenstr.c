#include <stdio.h>
#include <cs50.h>

int strlength(string s);
int strlengthR(string s);
int strlengthR2(string s, int c);

int main(void)
{
    printf("%i\n", strlength("this is a test straaaaaaaaaing"));
    printf("%i\n", strlengthR("this is a test straaaaaaaaaing"));
    return 0;
}

int strlength(string s)
{
    int count = 0;
    
    while (s[count] != '\0')
    {
        count++;
    }
    return count;
}

int strlengthR(string s)
{
    return strlengthR2(s, 0);
}

int strlengthR2(string s, int c)
{
    if (s[c] == '\0')
    {
        return 0;
    }
    else
    {
        return 1 + strlengthR2(s, c + 1);
    }
}