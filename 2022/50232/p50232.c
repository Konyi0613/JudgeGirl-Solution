#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int input[n][n];
    int filter[k][k];
    int output[n - k + 1][n - k + 1];
    for (int row = 0; row < n; row++)
        for (int col = 0; col < n; col++)
            scanf("%d", &input[row][col]);
    for (int row = 0; row < k; row++)
        for (int col = 0; col < k; col++)
            scanf("%d", &filter[row][col]);
    for (int row = 0; row < n - k + 1; row++)
    {
        for (int col = 0; col < n - k + 1; col++)
        {
            output[row][col] = 0;
            for (int s = 0; s < k; s++)
            {
                for (int l = 0; l < k; l++)
                {
                    output[row][col] += input[s + row][l + col] * filter[s][l];
                }
            }
            if (col == n - k)
                printf("%d\n", output[row][col]);
            else
                printf("%d ", output[row][col]);
        }
    }
}