#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int compute_cost(int *W, int l, int r) {
    int total_people = 0, prefix_sum = 0, median = l;
    for (int i = l; i <= r; i++) total_people += W[i];
    for (int i = l; i <= r; i++) {
        prefix_sum += W[i];
        if (prefix_sum * 2 >= total_people) {
            median = i;
            break;
        }
    }
    int cost = 0;
    for (int i = l; i <= r; i++) cost += W[i] * abs(i - median);
    return cost;
}

int min_total_movement(int N, int M, int *W) {
    int dp[N + 1][M + 1];
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
            dp[i][j] = INT_MAX;
    dp[0][0] = 0;

    int cost[N][N];
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            cost[i][j] = compute_cost(W, i, j);

    for (int m = 1; m <= M; m++) {
        for (int j = 0; j < N; j++) {
            for (int i = 0; i <= j; i++) {
                if (dp[i][m - 1] != INT_MAX)
                    dp[j + 1][m] = dp[j + 1][m] < dp[i][m - 1] + cost[i][j] ? dp[j + 1][m] : dp[i][m - 1] + cost[i][j];
            }
        }
    }
    return dp[N][M];
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {
        int W[N];
        for (int i = 0; i < N; i++) scanf("%d", &W[i]);
        printf("%d\n", min_total_movement(N, M, W));
    }
    return 0;
}
