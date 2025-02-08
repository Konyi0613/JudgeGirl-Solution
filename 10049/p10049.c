#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate random double in range [0, 1]
double frandom() {
    return rand() / (double)RAND_MAX;
}

// Function to calculate squared distance
double squared_distance(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    int N, A, B, t = 1;
    while (scanf("%d %d %d", &N, &A, &B) != EOF) {
        // Read girl positions
        int girls[N][2];
        for (int i = 0; i < N; i++)
            scanf("%d%d", &girls[i][0], &girls[i][1]);

        // Monte Carlo simulation parameters
        const int M = 1000000; // Number of random samples
        int counts[N];
        for (int i = 0; i < N; i++) counts[i] = 0;

        // Simulate random points
        srand(time(NULL));
        for (int i = 0; i < M; i++) {
            double x = frandom() * A;
            double y = frandom() * B;

            // Find the nearest girl using squared distances
            int nearest = 0;
            double min_dist_sq = squared_distance(x, y, girls[0][0], girls[0][1]);
            for (int j = 1; j < N; j++) {
                double d_sq = squared_distance(x, y, girls[j][0], girls[j][1]);
                if (d_sq < min_dist_sq) {
                    min_dist_sq = d_sq;
                    nearest = j;
                }
            }

            // Increment the count for the nearest girl
            counts[nearest]++;
        }

        // Calculate probabilities
        printf("Case #%d:\n", t);
        for (int i = 0; i < N; i++) {
            double probability = (counts[i] / (double)M) * 100.0;
            printf("%d\n", (int)(probability + 0.5)); // Round to nearest integer
        }
        t++;
    }

    return 0;
}
