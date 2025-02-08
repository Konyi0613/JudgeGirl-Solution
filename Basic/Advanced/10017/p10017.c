#include <stdio.h>
#include <stdlib.h>

typedef struct step
{
    int row;
    int col;
} Step;

int find_distance(Step s1, Step s2)
{
    int dr = s1.row - s2.row;;
    int dc = s1.col - s2.col;
    if (dr < 0)
        dr *= (-1);
    if (dc < 0)
        dc *= (-1);
    return (dr + dc); 
}

int main()
{
    int n;
    scanf("%d", &n);
    Step Steve[(2 * n + 1) / 2];
    Step Kon[2 * n - (2 * n + 1) / 2];
    int t[2] = {0};
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i % 2 == 1)
            scanf("%d%d", &Steve[t[0]].row, &Steve[t[0]].col);
        else
            scanf("%d%d", &Kon[t[1]].row, &Kon[t[1]].col);
        if (i > 1)
        {
            if (i % 2 == 1)
            {
                int min = find_distance(Steve[t[0]], Kon[0]);
                for (int j = 1; j < t[1]; j++)
                {
                    int dis = find_distance(Steve[t[0]], Kon[j]);
                    if (dis < min)
                        min = dis;
                }
                printf("%d\n", min);
            }
            else
            {
                int min = find_distance(Kon[t[1]], Steve[0]);
                for (int j = 1; j < t[0]; j++)
                {
                    int dis = find_distance(Kon[t[1]], Steve[j]);
                    if (dis < min)
                        min = dis;
                }
                printf("%d\n", min);
            }
        }
        t[(i + 1) % 2]++;
    }
}