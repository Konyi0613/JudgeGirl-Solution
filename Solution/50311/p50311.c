#include <stdio.h>
#include <stdbool.h>
// #define DEBUG

void find_sol
(int n, int adj[n][n], int degree[], bool finish[], int left, int index, int *best, int *best_sol, int now, int now_sol[])
{
    if (index == n || left == 0)
    {
        if (left == 0 && now < *best)
        {
            *best = now;
            for (int i = 0; i < now; i++)
                best_sol[i] = now_sol[i];
        }
        return;
    }
    if (now >= *best)
        return;
    //pick
    int reduce = 0;
    int tmp[degree[index]];
    for (int i = 0; i < degree[index]; i++)
        if (!finish[adj[index][i]])
        {
            tmp[reduce] = adj[index][i];
            reduce++;
            finish[adj[index][i]] = true;
        }
    now_sol[now] = index;
    find_sol(n, adj, degree, finish, left - reduce, index + 1, best, best_sol, now + 1, now_sol);
    //not pick
    for (int i = 0; i < reduce; i++)
        finish[tmp[i]] = false;
    find_sol(n, adj, degree, finish, left, index + 1, best, best_sol, now, now_sol);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int adj[n][n];
    int degree[n];
    bool finish[n];
    for (int i = 0; i < n; i++)
    {
        degree[i] = 0;
        finish[i] = false;
    }
    for (int i = 0; i < m; i++)
    {
        int l1, l2;
        scanf("%d%d", &l1, &l2);
        l1--;
        l2--;
        adj[l1][degree[l1]] = l2;
        degree[l1]++;
        adj[l2][degree[l2]] = l1;
        degree[l2]++;
    }
    #ifdef DEBUG
    for (int i = 0; i < n; i++)
    {
        printf("i = %d, %d", i, adj[i][0]);
        for (int j = 1; j < degree[i]; j++)
            printf(" %d", adj[i][j]);
        printf("\n");
    }
    #endif
    int best = n + 1, best_sol[n], now_sol[n];
    find_sol(n, adj, degree, finish, n, 0, &(best), best_sol, 0, now_sol);
    printf("%d\n%d", best, best_sol[0] + 1);
    for (int i = 1; i < best; i++)
        printf(" %d", best_sol[i] + 1);
}