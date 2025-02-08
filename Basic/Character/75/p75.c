#include <stdio.h>
#include <ctype.h>

int main()
{
    char string[100];
    int times[26] = {0};
    int i = 0;
    while (scanf("%c", &string[i]) != EOF)
    {
        if (isupper(string[i]))
        {
            int value = string[i] - 'A';
            times[value]++;
        }
        else if (islower(string[i]))
        {
            int value = string[i] - 'a';
            times[value]++;
        }
        i++;
    }
    for (int i = 0; i < 26; i++)
        printf("%d\n", times[i]);
}