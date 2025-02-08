#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    int n;
    scanf("%d", &n);
    char food[n][65];
    char ingredient[n][11][65];
    int ingre_num[n];
    for (int i = 0; i < n; i++)
    {
        char name[65];
        scanf("%s", name);
        strcpy(food[i], name);
        scanf("%d", &ingre_num[i]);
        for (int j = 0; j < ingre_num[i]; j++)
        {
            scanf("%s", name);
            strcpy(ingredient[i][j], name);
        }
    }
    int query;
    scanf("%d", &query);
    for (int i = 0; i < query; i++)
    {
        char food1[65];
        char food2[65];
        scanf("%s%s", food1, food2);
        int food1_index, food2_index;
        for (int j = 0; j < n; j++)
        {
            if (strcmp(food[j], food1) == 0)
                food1_index = j;
            if (strcmp(food[j], food2) == 0)
                food2_index = j;
        }
        char common[11][65];
        int common_num = 0;
        for (int j = 0; j < ingre_num[food1_index]; j++)
        {
            for (int k = 0; k < ingre_num[food2_index]; k++)
            {
                if (strcmp(ingredient[food1_index][j], ingredient[food2_index][k]) == 0)
                {
                    strcpy(common[common_num], ingredient[food1_index][j]);
                    common_num++;
                    break;
                }
            }
        }
        if (common_num == 0)
        {
            printf("nothing\n");
            continue;
        }
        for (int j = common_num - 1; j >= 0; j--)
        {
            for (int k = 0; k < j; k++)
            {
                if (strcmp(common[k], common[k + 1]) > 0)
                {
                    char tmp[65];
                    strcpy(tmp, common[k]);
                    strcpy(common[k], common[k + 1]);
                    strcpy(common[k + 1], tmp);
                }
            }
        }
        printf("%s", common[0]);
        for (int j = 1; j < common_num; j++)
            printf(" %s", common[j]);
        printf("\n");
    }
}