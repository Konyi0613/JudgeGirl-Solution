#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
void link(char str[101][1001], int intersect[101][2], int id1, int id2)
{
    int pre_len = strlen(str[id1]);
    int now_len = strlen(str[id2]);
    bool found = false;
    for (int i = 0; i < pre_len && !found; i++)
        for (int j = 0; j < now_len; j++)
            if (str[id1][i] == str[id2][j])
            {
                intersect[id1][1] = i;
                intersect[id2][0] = j;
                found = true;
                break;
            }
}
int main()
{
    int perimeter = 0;
    char str[101][1001];
    int intersect[101][2];
    int str_num = 0;
    while (scanf("%s", str[str_num]) != EOF)
    {
        if (str_num == 0)
        {
            str_num++;
            continue;
        }
        link(str, intersect, str_num - 1, str_num);
        str_num++;
    }
    str_num--;
    link(str, intersect, str_num, 0);
    for (int i = 0; i < str_num + 1; i++)
        perimeter += abs(intersect[i][0] - intersect[i][1]);
    printf("%d", perimeter);
}