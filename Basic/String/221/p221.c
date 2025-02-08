#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    int m;
    scanf("%d", &m);
    char word[257][257];
    int word_count = 0;
    char input[257];
    int char_count = 0;
    while (scanf("%s", input) != EOF)
    {
        int len = strlen(input);
        if (char_count + len + word_count <= m)
        {
            strcpy(word[word_count], input);
            char_count += len;
            word_count++;
        }
        else
        {
            if (word_count == 1)
            {
                printf("%s", word[0]);
                for (int i = 0; i < m - char_count; i++)
                    printf(" ");
                printf("\n");
            }
            else
            {
                int space_num = m - char_count;
                int avg_space = space_num / (word_count - 1);
                int have_more_space = space_num - avg_space * (word_count - 1);
                for (int i = 0; i < word_count - 1; i++)
                {
                    printf("%s", word[i]);
                    for (int j = 0; j < avg_space; j++)
                        printf(" ");
                    if (i < have_more_space)
                        printf(" ");
                }
                printf("%s\n", word[word_count - 1]);
            }
            strcpy(word[0], input);
            word_count = 1;
            char_count = len;
        }
    }
    if (word_count == 1)
    {
        printf("%s", word[0]);
        for (int i = 0; i < m - char_count; i++)
            printf(" ");
        printf("\n");
    }
    else
    {
        int space_num = m - char_count;
        int avg_space = space_num / (word_count - 1);
        int have_more_space = space_num - avg_space * (word_count - 1);
        for (int i = 0; i < word_count - 1; i++)
        {
            printf("%s", word[i]);
            for (int j = 0; j < avg_space; j++)
                printf(" ");
            if (i < have_more_space)
                printf(" ");
        }
        printf("%s\n", word[word_count - 1]);
    }
}