#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void find(int n, int matrix[n][n], bool used[], int *best, int *best_last, int layer, int id, int cost) {
    if (layer == n) {
        if (cost + matrix[id][0] < *best) {
            *best = cost + matrix[id][0];
            *best_last = id;
        }
        return;
    }

    if (cost >= (*best - matrix[*best_last][0]))
        return;
    
    for (int i = 1; i < n; i++) { // 0 is visited
        if (used[i])
            continue;
        used[i] = true;
        find(n, matrix, used, best, best_last, layer + 1, i, cost + matrix[id][i]);
        used[i] = false;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    int best = INT32_MAX;
    bool used[n];
    for (int i = 0; i < n; i++)
        used[i] = false;
    // used[0] = true;
    int best_last = 0;
    find(n, matrix, used, &best, &best_last, 1, 0, 0);
    printf("%d\n", best);
}