#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
// #define DEBUG

void find_solution(int vertex_num, int edge[vertex_num][vertex_num - 1], int degree[], bool used[], int now_map[], int now_max, int *best, int best_map[], int index)
{
    if (index == vertex_num)
    {
        if (now_max < *best)
        {
            *best = now_max;
            for (int i = 0; i < vertex_num; i++)
                best_map[i] = now_map[i];
#ifdef DEBUG
            printf("best: %d, ", *best);
            for (int i = 0; i < vertex_num; i++)
                printf("%d ", best_map[i]);
            printf("\n");
#endif
        }
        return;
    }
    if (now_max >= *best)
        return;
    for (int i = 0; i < vertex_num; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            now_map[index] = i;
            int new_max = now_max;
            for (int j = 0; j < degree[index]; j++)
            {
                int length = now_map[index] - now_map[edge[index][j]];
                if (length < 0)
                    length *= (-1);
                if (length > new_max)
                    new_max = length;
            }
            find_solution(vertex_num, edge, degree, used, now_map, new_max, best, best_map, index + 1);
            used[i] = false;
        }
    }
}

int cmp(const void *t1, const void *t2)
{
    return *(int *)t1 - *(int *)t2;
}

int main()
{
    int vertex_num, edge_num;
    scanf("%d%d", &vertex_num, &edge_num);
    int edge[vertex_num][vertex_num - 1];
    int degree[vertex_num];
    bool used[vertex_num];
    for (int i = 0; i < vertex_num; i++)
    {
        degree[i] = 0;
        used[i] = false;
    }
    for (int i = 0; i < edge_num; i++)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        v1 -= 1;
        v2 -= 1;
        if (v1 > v2)
        {
            int tmp = v1;
            v1 = v2;
            v2 = tmp;
        }
        edge[v2][degree[v2]] = v1;
        degree[v2]++;
    }
    for (int i = 0; i < vertex_num; i++)
        qsort(&(edge[i]), degree[i], sizeof(int), cmp);
#ifdef DEBUG
    for (int i = 0; i < vertex_num; i++)
    {
        printf("degree[%d] = %d, ", i, degree[i]);
        printf("%d's edge:", i);
        for (int j = 0; j < degree[i]; j++)
            printf(" %d", edge[i][j]);
        printf("\n");
    }
#endif
    int now_map[vertex_num];
    int best = INT32_MAX;
    int best_map[vertex_num];
    find_solution(vertex_num, edge, degree, used, now_map, 0, &(best), best_map, 0);
    printf("%d", best_map[0] + 1);
    for (int i = 1; i < vertex_num; i++)
        printf(" %d", best_map[i] + 1);
}