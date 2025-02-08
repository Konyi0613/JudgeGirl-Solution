#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char string[100];
    int i = 0;
    int num = 0, alpha = 0, vowel = 0, consonant = 0;
    while (scanf("%c", &string[i]) != EOF)
    {
        if (isdigit(string[i]))
            num++;
        if (isalpha(string[i]))
        {
            alpha++;
            if (string[i] == 'a' || string[i] == 'A' || string[i] == 'e' || string[i] == 'E' || string[i] == 'i' || string[i] == 'I' || string[i] == 'o' || string[i] == 'O' || string[i] == 'u' || string[i] == 'U')
                vowel++;
            else
                consonant++;
        }
        i++;
    }
    printf("%d %d %d %d", num, alpha, vowel, consonant);
}