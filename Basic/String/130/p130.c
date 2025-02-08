#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        char str1[100];
        char str2[100];
        scanf("%s%s", str1, str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        if (abs(len1 - len2) > 1)
        {
            printf("no\n");
            continue;
        }
        if (strcmp(str1, str2) == 0)
        {
            printf("yes\n");
            continue;
        }
        if (abs(len1 - len2) == 1)
        {
            int counter = (len1 < len2) ? len1 : len2;
            bool longer2 = true;
            if (counter != len1)
                longer2 = false;
            int diff_pos = -1;
            for (int i = 0; i < counter; i++)
            {
                if (str1[i] != str2[i])
                {
                    diff_pos = i;
                    break;
                }
            }
            if (diff_pos == -1)
            {
                printf("yes\n");
                continue;
            }
            for (int i = diff_pos; i < counter; i++)
            {
                if (longer2)
                {
                    if (str1[i] != str2[i + 1])
                    {
                        printf("no\n");
                        break;
                    }
                }
                else
                {
                    if (str1[i + 1] != str2[i])
                    {
                        printf("no\n");
                        break;
                    }
                }
                if (i == counter - 1)
                    printf("yes\n");
            }
        }
        else
        {
            int diff1 = 0;
            int diff2 = 0;
            for (int i = 0; i < len1 - 1; i++)
            {
                if (str1[i] == str2[i + 1] && str1[i + 1] == str2[i] && str1[i] != str2[i])
                    diff1++;
                else if (str1[i] != str2[i] && !(str1[i - 1] == str2[i] && str1[i] == str2[i - 1]))
                    diff2++;
                else if (str1[len1 - 1] != str2[len1 - 1] && i == len1 - 2 && !(str1[len1 - 2] == str2[len1 - 1] && str1[len1 - 1] == str2[len2 - 2]))
                    diff2++;
            }
            // printf("%d%d\n", diff1, diff2);
            if (diff1 > 1 || diff2 > 0)
                printf("no\n");
            else
                printf("yes\n");
        }
    }
}