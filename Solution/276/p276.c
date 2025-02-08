#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char string[127];
    while (scanf("%s", string) != EOF)
    {
        int len = strlen(string);
        bool end = (string[len - 1] == '.');
        char at[] = "at";
        char the[] = "the";
        char of[] = "of";
        char and[] = "and";
        if (strcmp(string, at) == 0 || strcmp(string, the) == 0 || strcmp(string, of) == 0 || strcmp(string, and) == 0)
            continue;
        else if (strcmp(string, "at.") == 0 || strcmp(string, "the.") == 0 || strcmp(string, "of.") == 0 || strcmp(string, "and.") == 0)
            printf("\n");
        else
        {
            if (end)
                printf("%c\n", toupper(string[0]));
            else
                printf("%c", toupper(string[0]));
        }
    }
}