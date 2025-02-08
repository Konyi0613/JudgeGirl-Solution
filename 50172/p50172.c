#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char prev[31], now[31];
    bool cover = false;
    scanf("%s", prev);
    printf("%s", prev);
    int word_count = 1, len = strlen(prev) - 1;
    while (scanf("%s", now) != EOF)
    {
        char tmp[31];
        cover = false;
        if (prev[strlen(prev) - 1] == now[0])
        {
            cover = true;
            strcpy(tmp, &(now[1]));
        }
        else
            strcpy(tmp, now);
        if (word_count % 2 == 0)
        {
            if (!cover)
            {
                printf("\n");
                for (int i = 0; i < len; i++)
                    printf("*");
            }
            else
                len++;
            printf("%s", tmp);
            len += (strlen(tmp) - 1);
        }
        else
        {
            int tmp_len = strlen(tmp);
            printf("\n");
            for (int i = 0; i < tmp_len; i++)
            {
                for (int j = 0; j < len; j++)
                    printf("*");
                printf("%c", tmp[i]);
                if (i < tmp_len - 1)
                    printf("\n");
            }
        }
        strcpy(prev, now);
        word_count++;
    }
}