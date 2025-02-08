#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char str[2][1001][101];
    int str_num = 0;
    int t_count[2];
    int counter = 0;
    char input;
    while (scanf("%c", &input) != EOF)
    {
        if (isalpha(input))
        {
            str[str_num][t_count[str_num]][counter] = input;
            counter++;
        }
        else if (isspace(input) && input != '\n')
        {
            str[str_num][t_count[str_num]][counter] = '\0';
            t_count[str_num]++;
            counter = 0;
        }
        else if (input == '\n')
        {
            str[str_num][t_count[str_num]][counter] = '\0';
            t_count[str_num]++;
            counter = 0;
            str_num = 1;
        }
    }
    // printf("%d %d\n", t_count[0], t_count[1]);
    /*for (int i = 0; i < t_count[0]; i++)
        printf("%s ", str[0][i]);
    printf("\n");
    for (int i = 0; i < t_count[1]; i++)
        printf("%s ", str[1][i]);
    printf("\n");*/
    int now[2] = {0, 0};
    bool end0 = false;
    while (now[0] < t_count[0] && now[1] < t_count[1])
    {
        if (strcmp(str[0][now[0]], str[1][now[1]]) < 0)
        {
            printf("%s", str[0][now[0]]);
            now[0]++;
        }
        else
        {
            printf("%s", str[1][now[1]]);
            now[1]++;
        }
        if (now[0] == t_count[0])
            end0 = true;
    }
    int index = 0;
    if (end0)
        index = 1;
    for (int j = now[index]; j < t_count[index]; j++)
        printf("%s", str[index][j]);
}