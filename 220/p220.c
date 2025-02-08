#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char s[4];
    scanf("%c%c%c", &s[0], &s[1], &s[2]);
    int sum = 0, test = 0;
    while (scanf("%c", &s[3]) != EOF)
    {
        if (s[0] == '.')
        {
            if ((s[1] == ' ' && s[2] == ' ') || s[1] == '\n')
            {
                sum++;
            }
        }
        if (s[0] == '.' && s[1] == ' ' && s[2] == '\n' && (s[3] == ' ' || s[3] == '\n'))
        {
            test = 1;
        }
        if (s[3] != ' ' && s[3] != '\n')
        {
            test = 0;
        }
        s[0] = s[1];
        s[1] = s[2];
        s[2] = s[3];
    }
    if (s[2] == '.' || (s[1] == '.' && (s[2] == ' ' || s[2] == '\n') || (s[0] == '.' && (s[1] == ' ' || s[1] == '\n') && (s[2] == ' ' || s[2] == '\n'))))
    {
        sum++;
    }
    if (test)
        sum++;
    printf("%d", sum);
    return 0;
}