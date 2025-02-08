#include <stdio.h>
#include <string.h>
#define DEBUG 0

int main()
{
    char word[100000] = {""};
    int flag = 0;
    char command[10];
    while (scanf("%s", command) != EOF)
    {
        if (strcmp(command, "insert") == 0)
        {
            char dir[10] = {""}, value[100000] = {""};
            scanf("%s%s", dir, value);
            if (strcmp(dir, "left") == 0)
            {
                strcat(value, word);
                strcpy(word, value);
                flag++;
            }
            else if (strcmp(dir, "right") == 0)
            {
                strcat(word, value);
                flag++;
            }
            else
            {
                int len = strlen(dir), point = 0;
                for (int i = 0; i < len; i++)
                {
                    point = point * 10 + (dir[i] - '0');
                }
                strcat(value, &(word[point - 1]));
                strcpy(&(word[point - 1]), value);
                flag++;
            }
        }
        if (strcmp(command, "delete") == 0)
        {
            char dir[10] = {""}, temp[100000] = {""};
            scanf("%s", dir);
            if (strcmp(dir, "left") == 0)
            {
                strcpy(temp, (&word[1]));
                strcpy(word, temp);
                flag--;
            }
            else if (strcmp(dir, "right") == 0)
            {
                strncpy(temp, word, flag - 1);
                temp[flag - 1] = '\0';
                strcpy(word, temp);
                flag--;
            }
            else
            {
                int len = strlen(dir), point = 0;
                for (int i = 0; i < len; i++)
                {
                    point = point * 10 + (dir[i] - '0');
                }
                strncpy(temp, word, point - 1);
                temp[point - 1] = '\0';
                strcat(temp, (&word[point]));
                strcpy(word, temp);
                flag--;
            }
        }

#if DEBUG == 1
        printf("%s %d\n", word, flag);
#endif
    }

    int best = 0, l = 1;
    for (int i = 0; i < flag; i++)
    {
        if (word[i] == word[i + 1])
            l++;
        else
        {
            if (l > best)
                best = l;
            l = 1;
        }
    }

    for (int i = 0; i < flag; i++)
    {
        if (word[i] == word[i + 1])
            l++;
        else
        {
            if (l == best)
                printf("%c ", word[i]);
            l = 1;
        }
    }
    printf("%d\n", best);
    return 0;
}