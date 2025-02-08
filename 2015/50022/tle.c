#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void find_solution(int row, int col, int row_sum[], int col_sum[], int matrix[row][col], bool used[row * col], bool *end, int layer)
{
    int r = layer / col, c = layer % col;
    if (c == 0 && r > 0 && row_sum[r - 1] != 0)
        return;
    if (layer >= row * col)
    {
        for (int i = 0; i < row; i++)
        {
            printf("%d", matrix[i][0]);
            for (int j = 1; j < col; j++)
                printf(" %d", matrix[i][j]);
            printf("\n");
        }
        *end = true;
        return;
    }
    for (int i = 1; i <= row * col; i++)
    {
        if (used[i - 1] || row_sum[r] < i || col_sum[c] < i)
            continue;
        row_sum[r] -= i;
        col_sum[c] -= i;
        used[i - 1] = true;
        matrix[r][c] = i;
        find_solution(row, col, row_sum, col_sum, matrix, used, end, layer + 1);
        if (*end == true)
            return;
        row_sum[r] += i;
        col_sum[c] += i;
        used[i - 1] = false;
    }
    if (layer == 0)
        printf("no solution\n");
}

int main()
{
    int row, col;
    while (scanf("%d%d", &row, &col) != EOF)
    {
        int row_sum[row], col_sum[col], matrix[row][col];
        for (int i = 0; i < row; i++)
            scanf("%d", &row_sum[i]);
        for (int i = 0; i < col; i++)
            scanf("%d", &col_sum[i]);
        bool used[row * col];
        for (int i = 0; i < row * col; i++)
            used[i] = false;
        bool end = false;
        find_solution(row, col, row_sum, col_sum, matrix, used, &end, 0);
    }
}