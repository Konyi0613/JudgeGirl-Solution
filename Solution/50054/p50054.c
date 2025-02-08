#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLEN 101
#define COLLISON 5000


int hash_func(char *str, int S)
{
    int len = strlen(str);
    int sum = 0;
    for (int i = 0; i < len; i++)
        if (isdigit(str[i]))
            sum += (str[i] - '0');
        else
            sum += str[i];
    return (sum % S);
}

int main()
{
    int S, N, Q;
    scanf("%d%d%d", &S, &N, &Q);
    char **table[1000];
    char buffer[MAXLEN];
    int num[S];
    for (int i = 0; i < S; i++)
    {
        num[i] = 0;
        table[i] = (char **)malloc(COLLISON * sizeof(char *));
        for (int j = 0; j < COLLISON; j++)
            table[i][j] = (char *)malloc(MAXLEN * sizeof(char));
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%s", buffer);
        int key = hash_func(buffer, S);
        strcpy(table[key][num[key]], buffer);
        num[key]++;
    }
    for (int i = 0; i < Q; i++)
    {
        scanf("%s", buffer);
        int key = hash_func(buffer, S);
        if (num[key] == 0)
            printf("-1\n");
        else
        {
            int found = -1;
            for (int j = 0; j < num[key]; j++)
                if (strcmp(table[key][j], buffer) == 0)
                {
                    found = 1;
                    break;
                }
            if (found == 1)
                printf("%d\n", key);
            else
                printf("-1\n");
        }
    }
}