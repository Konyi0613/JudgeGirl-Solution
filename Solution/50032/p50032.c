#include <stdio.h>
#include <stdbool.h>

bool find(int n, int k, int row[], int col[], int dg1[], int dg2[], char board[n][n], int now_row, int now_col, int left)
{
    if (left == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%c", board[i][j]);
            printf("\n");
        }
        return true;
    }
    else if (now_row == n)
        return false;
    if (row[now_row] == k)
        return find(n, k, row, col, dg1, dg2, board, now_row + 1, 0, left);
    int next_row, next_col;
    if (now_col == n - 1)
    {
        next_row = now_row + 1;
        next_col = 0;
    }
    else
    {
        next_row = now_row;
        next_col = now_col + 1;
    }
    //pick
    if (col[now_col] < k && dg1[now_row - now_col + (n - 1)] < k && dg2[now_row + now_col] < k)
    {
        row[now_row]++;
        col[now_col]++;
        dg1[now_row - now_col + (n - 1)]++;
        dg2[now_row + now_col]++;
        board[now_row][now_col] = 'o';
        if (find(n, k, row, col, dg1, dg2, board, next_row, next_col, left - 1))
            return true;
        row[now_row]--;
        col[now_col]--;
        dg1[now_row - now_col + (n - 1)]--;
        dg2[now_row + now_col]--;
        board[now_row][now_col] = '.';
    }
    //not_pick
    if (find(n, k, row, col, dg1, dg2, board, next_row, next_col, left))
        return true;
    else
        return false;
}

int main()
{
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        int row[n], col[n], dg1[2 * n - 1], dg2[2 * n - 1];
        char board[n][n];
        for (int i = 0; i < n; i++)
        {
            row[i] = 0;
            col[i] = 0;
            for (int j = 0; j < n; j++)
                board[i][j] = '.';
        }
        for (int i = 0; i < 2 * n - 1; i++)
        {
            dg1[i] = 0;
            dg2[i] = 0;
        }
        if (!find(n, k, row, col, dg1, dg2, board, 0, 0, m))
            printf("N\n");
    }
}