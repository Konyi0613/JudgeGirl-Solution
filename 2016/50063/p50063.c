#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void copy(int *arr1, int *arr2, int n) {
    for (int i = 0; i < n; ++i)
        arr1[i] = arr2[i];
    return;
}

void find_max(int n, bool **friend, bool *used, int layer, int now_max, int *now_sol, int *best_max, int *best_sol) {
    if (layer == n) {
        if (now_max < *best_max) {
            *best_max = now_max;
            copy(best_sol, now_sol, n);
        }
        return;
    }

    if (now_max >= *best_max)
        return;
    
    for (int i = 0; i < n; ++i) {
        if (used[i])
            continue;
        used[i] = true;
        now_sol[layer] = i;
        int new_max = now_max;
        for (int j = 0; j < layer; ++j)
            if (friend[i][now_sol[j]] && layer - j > new_max)
                new_max = layer - j;
        find_max(n, friend, used, layer + 1, new_max, now_sol, best_max, best_sol);
        used[i] = false;
    }

    return;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    bool **friend = (bool **)malloc(n * sizeof(bool *));
    for (int i = 0; i < n; ++i)
        friend[i] = (bool *)malloc(n * sizeof(bool));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            friend[i][j] = false;
    getchar();
    for (int i = 0; i < m; ++i) {
        char p1, p2;
        scanf("%c %c\n", &p1, &p2);
        int n1 = p1 - 'A';
        int n2 = p2 - 'A';
        friend[n1][n2] = true;
        friend[n2][n1] = true;
    }
    bool used[n];
    memset(used, false, n * sizeof(bool));
    int now_sol[n], best_sol[n];
    int best_max = INT32_MAX;
    find_max(n, friend, used, 0, 0, now_sol, &best_max, best_sol);
    printf("%d\n", best_max);
    printf("%c", 'A' + best_sol[0]);
    for (int i = 1; i < n; ++i)
        printf(" %c", 'A' + best_sol[i]);
    printf("\n");
    return 0;
}