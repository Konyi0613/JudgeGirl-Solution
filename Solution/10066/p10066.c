#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Generate random double in range [0, 1]
double frandom() {
    return rand() * 1.f / RAND_MAX;
}
// Function to calculate squared distance
double squared_distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
}

int main() {
    int R, N, t = 1;
    while (scanf("%d%d", &R, &N) != EOF) {
        // Read girl positions
        int girls[N][3];
        for (int i = 0; i < N; i++)
            scanf("%d%d%d", &girls[i][0], &girls[i][1], &girls[i][2]);

        // Monte Carlo simulation parameters
        const int M = 10000000; // Number of random samples
        int counts[N];
        for (int i = 0; i < N; i++) counts[i] = 0;

        // Simulate random points
        srand(time(NULL));
        for (int i = 0; i < M; i++) {
            double x = -R + 2 * frandom() * R;
            double r = sqrt(R * R - x * x);
            double y = -r + 2 * frandom() * r;
            double r2 = sqrt(R * R - x * x - y * y);
            double z = -r2 + 2 * r2 * frandom();
            // Find the nearest girl using squared distances
            int nearest = 0;
            double min_dist_sq = squared_distance(x, y, z, girls[0][0], girls[0][1], girls[0][2]);
            for (int j = 1; j < N; j++) {
                double d_sq = squared_distance(x, y, z, girls[j][0], girls[j][1], girls[j][2]);
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
