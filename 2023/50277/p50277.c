#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #define DEBUG

void find_max(char *string[], int str_count, int id, int *max, int pos[str_count][2], int len[])
{
    if (id == str_count - 1)
    {
        for (int i = pos[id][0]; i < len[id]; i++)
            for (int j = 0; j < pos[0][1]; j++)
                if (string[id][i] == string[0][j])
                {
                    pos[0][0] = j;
                    pos[id][1] = i;
                    int sum = 0;
                    for (int k = 0; k < str_count; k++)
                        sum += (pos[k][1] - pos[k][0]);
                    if (sum > *max)
                    {
                        *max = sum;
#ifdef DEBUG
    printf("max = %d\n", *max);
    for (int k = 0; k < str_count; k++)
        printf("pos[%d][%d] = %d, pos[%d][%d] = %d\n", k, 0, pos[k][0], k, 1, pos[k][1]);
#endif
                    }
                }
        return;
    }
    for (int i = pos[id][0]; i < len[id]; i++)
        for (int j = 0; j < len[id + 1] - 1; j++)
            if (string[id][i] == string[id + 1][j])
            {
                pos[id][1] = i;
                pos[id + 1][0] = j;
                find_max(string, str_count, id + 1, max, pos, len);
            }
    return;
}

int main()
{
    char *string[20];
    int str_count = 0;
    char buffer[101];
    while (scanf("%s", buffer) != EOF)
    {
        string[str_count] = (char *)malloc(101 * sizeof(char));
        strcpy(string[str_count], buffer);
        str_count++;
    }
    int max = 0, pos[str_count][2];
    pos[0][0] = 0;
    int len[str_count];
    for (int i = 0; i < str_count; i++)
        len[i] = strlen(string[i]);
    find_max(string, str_count, 0, &max, pos, len);
    printf("%d\n", max);
}