#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// #define DEBUG
bool has_triangle(int v, int edge[v][v - 1], int degree[], bool in_graph[v][v], int id, int tg)
{
    for (int i = 0; i < id; i++)
    {
        int count = 0;
        for (int j = 0; j < degree[i]; j++)
        {
            if ((edge[i][j] == id || edge[i][j] == tg) && in_graph[i][edge[i][j]])
                count++;
        }
        if (count == 2)
            return true;
    }
    return false;
}

void find_solution(int v, int e, int edge[v][v - 1], int degree[], bool in_graph[v][v], int now_edge_num, int left_edge_num, int id, int target, int now_arr[e][2], int *best, int best_arr[e][2])
{
    if (id == v)
    {
#ifdef DEBUG
        printf("now_edge_num: %d, best: %d\n", now_edge_num, *best);
        printf("now arr:\n");
        for (int i = 0; i < now_edge_num; i++)
            printf("%d %d\n", now_arr[i][0], now_arr[i][1]);
        printf("now arr end\n");
#endif
        if (now_edge_num > *best)
        {
            *best = now_edge_num;
            for (int i = 0; i < now_edge_num; i++)
            {
                best_arr[i][0] = now_arr[i][0];
                best_arr[i][1] = now_arr[i][1];
            }
        }
        return;
    }
    if (now_edge_num + left_edge_num <= *best)
        return;
    if (degree[id] == 0)
    {
        find_solution(v, e, edge, degree, in_graph, now_edge_num, left_edge_num, id + 1, 0, now_arr, best, best_arr);
        return;
    }
    int next_id, next_target;
    if (target == degree[id] - 1)
    {
        next_id = id + 1;
        next_target = 0;
    }
    else
    {
        next_id = id;
        next_target = target + 1;
    }
    if (!has_triangle(v, edge, degree, in_graph, id, edge[id][target]))
    {
        in_graph[id][edge[id][target]] = true;
        now_arr[now_edge_num][0] = id;
        now_arr[now_edge_num][1] = edge[id][target];
        find_solution(v, e, edge, degree, in_graph, now_edge_num + 1, left_edge_num - 1, next_id, next_target, now_arr, best, best_arr);
        in_graph[id][edge[id][target]] = false;
    }
    find_solution(v, e, edge, degree, in_graph, now_edge_num, left_edge_num - 1, next_id, next_target, now_arr, best, best_arr);
    return;
}

int cmp(const void *p1, const void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

int main()
{
    int v, e;
    scanf("%d%d", &v, &e);
    bool in_graph[v][v];
    int degree[v];
    for (int i = 0; i < v; i++)
    {
        degree[i] = 0;
        for (int j = 0; j < v; j++)
            in_graph[i][j] = false;
    }
    int edge[v][v - 1];
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        if (v2 < v1)
        {
            int tmp = v1;
            v1 = v2;
            v2 = tmp;
        }
        edge[v1][degree[v1]] = v2;
        degree[v1]++;
    }
    for (int i = 0; i < v; i++)
        qsort(&(edge[i][0]), degree[i], sizeof(int), cmp);
#ifdef DEBUG
    for (int i = 0; i < v; i++)
    {
        printf("%d's edge: ", i);
        for (int j = 0; j < degree[i]; j++)
            printf("%d ", edge[i][j]);
        printf("\n");
    }
#endif
    int now_arr[e][2];
    int best = 0;
    int best_arr[e][2];
    find_solution(v, e, edge, degree, in_graph, 0, e, 0, 0, now_arr, &(best), best_arr);
    for (int i = 0; i < best; i++)
        printf("%d %d\n", best_arr[i][0], best_arr[i][1]);
}