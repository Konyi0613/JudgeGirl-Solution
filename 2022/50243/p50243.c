#include <stdio.h>
#include <stdbool.h>
// #define DEBUG

void arr_cpy(int arr1[], int arr2[], int size)
{
#ifdef DEBUG
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        arr1[i] = arr2[i];
        printf("%d%c", arr1[i], (i == size - 1) ? '\n' : ' ');
    }
#endif
#ifndef DEBUG
    for (int i = 0; i < size; i++)
        arr1[i] = arr2[i];
#endif
}

void find_solution(int vertex_num, int edge_num, int degree[], bool covered[vertex_num][vertex_num], int edge[vertex_num][vertex_num - 1],
                   int *smallest, int *now_arr, int *best_arr, int covered_edge, int layer, int in_set_num)
{
    if (layer == vertex_num || covered_edge == edge_num)
    {
#ifdef DEBUG
        printf("covered_edge: %d, now_arr: ", covered_edge);
        for (int i = 0; i < in_set_num; i++)
            printf("%d%c", now_arr[i], (i == in_set_num - 1) ? '\n' : ' ');
#endif
        if (in_set_num < *smallest && covered_edge == edge_num)
        {
            *smallest = in_set_num;
            arr_cpy(best_arr, now_arr, *smallest);
        }
        return;
    }
    if (in_set_num == *smallest)
        return;
    if (degree[layer] == 0)
    {
        find_solution(vertex_num, edge_num, degree, covered, edge, smallest, now_arr, best_arr, covered_edge, layer + 1, in_set_num);
        return;
    }
    int new_cover_num = 0;
    int new_cover[vertex_num];
    for (int i = 0; i < degree[layer]; i++)
    {
#ifdef DEBUG
        printf("edge[%d][%d]: %d\n", layer, i, edge[layer][i]);
#endif
        if (!covered[layer][edge[layer][i]])
        {
            covered[layer][edge[layer][i]] = true;
            covered[edge[layer][i]][layer] = true;
            new_cover[new_cover_num] = edge[layer][i];
            new_cover_num++;
        }
    }
#ifdef DEBUG
    for (int i = 0; i < new_cover_num; i++)
        printf("%d ", new_cover[i]);
    printf("\n");
    printf("covered_edge: %d, new_cover_num: %d, layer: %d, in_set_num: %d\n", covered_edge, new_cover_num, layer, in_set_num);
#endif
    now_arr[in_set_num] = layer;
    find_solution(vertex_num, edge_num, degree, covered, edge, smallest, now_arr, best_arr, covered_edge + new_cover_num, layer + 1, in_set_num + 1);
    for (int i = 0; i < new_cover_num; i++)
    {
        covered[layer][new_cover[i]] = false;
        covered[new_cover[i]][layer] = false;
    }
    find_solution(vertex_num, edge_num, degree, covered, edge, smallest, now_arr, best_arr, covered_edge, layer + 1, in_set_num);
}

int main()
{
    int vertex_num, edge_num;
    scanf("%d%d", &vertex_num, &edge_num);
    int degree[vertex_num];
    bool covered[vertex_num][vertex_num];
    for (int i = 0; i < vertex_num; i++)
    {
        degree[i] = 0;
        for (int j = 0; j < vertex_num - 1; j++)
            covered[i][j] = false;
    }
    int edge[vertex_num][vertex_num - 1];
    for (int i = 0; i < edge_num; i++)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        edge[v1][degree[v1]] = v2;
        edge[v2][degree[v2]] = v1;
        degree[v1]++;
        degree[v2]++;
    }
#ifdef DEBUG
    for (int i = 0; i < vertex_num; i++)
    {
        printf("vertex[%d]:", i);
        for (int j = 0; j < degree[i]; j++)
            printf(" %d", edge[i][j]);
        printf("\n");
    }
    for (int i = 0; i < vertex_num; i++)
        printf("degree[%d] = %d\n", i, degree[i]);
#endif
    int smallest = vertex_num + 1;
    int now_arr[vertex_num];
    int best_arr[vertex_num];
    int covered_people = 0;
    find_solution(vertex_num, edge_num, degree, covered, edge, &(smallest), now_arr, best_arr, 0, 0, 0);
#ifdef DEBUG
    printf("smallest: %d\n", smallest);
#endif
    for (int i = 0; i < smallest; i++)
        printf("%d\n", best_arr[i]);
}