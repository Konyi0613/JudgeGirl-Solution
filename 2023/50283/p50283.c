#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void maximum_path(int set_size, int node_num, bool edge[node_num][set_size], char now_path[6000][node_num + 1], char best_path[6000][node_num + 1], int *best, int *now_path_num, int layer, int node_in_first_set)
{
}

int main()
{
    int set_size, node_num;
    scanf("%d%d", &set_size, &node_num);
    int edge_num;
    scanf("%d", &edge_num);
    bool edge[node_num][set_size];
    int degree[node_num];
    for (int i = 0; i < node_num; i++)
    {
        degree[i] = 0;
        for (int j = 0; j < set_size; j++)
            edge[i][j] = false;
    }
    for (int i = 0; i < edge_num; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        b %= set_size;
        edge[a][b] = true;
        degree[a]++;
    }
    char now_path[6000][node_num + 1];
    char best_path[6000][node_num + 1];
    int now_path_num = 0;
    int best = 0;
    maximum_path(set_size, node_num, edge, now_path, best_path, &best, &now_path_num, 0, 0);
    // output best_path
}