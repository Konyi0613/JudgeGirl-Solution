#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 300
#define MAX_P 30

int villages[MAX_V + 1];
int dist[MAX_V + 1][MAX_V + 1];
int dp[MAX_V + 1][MAX_P + 1];

// Function to calculate distances
void computeDistances(int v) {
    for (int i = 1; i <= v; i++) {
        for (int j = i; j <= v; j++) {
            int mid = (i + j) / 2;  // Median of the range [i, j]
            dist[i][j] = 0;
            for (int k = i; k <= j; k++)
                dist[i][j] += abs(villages[k] - villages[mid]);
        }
    }
}

// Function to solve the problem using dynamic programming
int solve(int v, int p) {
    for (int i = 0; i <= v; i++) {
        for (int j = 0; j <= p; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    dp[0][0] = 0;  // Base case: no villages, no post offices

    for (int j = 1; j <= p; j++) // Number of post offices
        for (int i = 1; i <= v; i++) // Number of villages
            for (int k = 0; k < i; k++) // Last post office was placed in [1...k]
                if (dp[k][j - 1] != INT_MAX) 
                    dp[i][j] = dp[i][j] < dp[k][j - 1] + dist[k + 1][i] ? dp[i][j] : dp[k][j - 1] + dist[k + 1][i];
    return dp[v][p];
}

int main() {
    int v, p;
    while (scanf("%d %d", &v, &p) != EOF) {
        for (int i = 1; i <= v; i++)
            scanf("%d", &villages[i]);

        // Precompute distances
        computeDistances(v);

        // Solve using DP
        int result = solve(v, p);

        // Output the result
        printf("%d\n", result);
    }

    return 0;
}
