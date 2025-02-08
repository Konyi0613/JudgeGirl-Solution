#include <stdio.h>
#include <string.h>
int main()
{
    char string[10];
    int width, height;
    while (scanf("%s%d%d", string, &width, &height) != EOF)
    {
        int half_height = height / 2;
        int len = strlen(string);
        for (int i = 0; i < half_height; i++)
        {
            for (int j = 0; j < len; j++)
            {
                int value = string[j] - '0';
                char digit;
                if (i == 0)
                {
                    printf(" ");
                    if (value == 1 || value == 4)
                        digit = ' ';
                    else
                        digit = string[j];
                    for (int k = 0; k < width - 3; k++)
                        printf("%c", digit);
                    if (j == len - 1)
                        printf("\n");
                    else
                        printf("  ");
                }
                else
                {
                    if (value == 1 || value == 2 || value == 3)
                        printf(" ");
                    else
                        printf("%c", string[j]);
                    for (int k = 0; k < width - 3; k++)
                        printf(" ");
                    if (value == 5 || value == 6)
                        printf(" ");
                    else
                        printf("%c", string[j]);
                    if (j == len - 1)
                        printf("\n");
                    else
                        printf(" ");
                }
            }
        }
        for (int i = 0; i < len; i++)
        {
            char digit;
            if (string[i] - '0' == 0 || string[i] - '0' == 1 || string[i] - '0' == 7)
                digit = ' ';
            else
                digit = string[i];
            printf(" ");
            for (int j = 0; j < width - 3; j++)
                printf("%c", digit);
            if (i == len - 1)
                printf("\n");
            else
                printf("  ");
        }
        for (int i = 0; i < half_height; i++)
        {
            for (int j = 0; j < len; j++)
            {
                int value = string[j] - '0';
                char digit;
                if (i == half_height - 1)
                {
                    printf(" ");
                    if (value == 1 || value == 4 || value == 7 || value == 9)
                        digit = ' ';
                    else
                        digit = string[j];
                    for (int k = 0; k < width - 3; k++)
                        printf("%c", digit);
                    if (j == len - 1)
                        printf("\n");
                    else
                        printf("  ");
                }
                else
                {
                    if (value == 0 || value == 2 || value == 6 || value == 8)
                        printf("%c", string[j]);
                    else
                        printf(" ");
                    for (int k = 0; k < width - 3; k++)
                        printf(" ");
                    if (value == 2)
                        printf(" ");
                    else
                        printf("%c", string[j]);
                    if (j == len - 1)
                        printf("\n");
                    else
                        printf(" ");
                }
            }
        }
    }
}