#include <stdio.h>

int valid(int row, int col, int matrix[row][col], int pos_r, int pos_c)
{
    if (pos_r < row && pos_c < col && matrix[pos_r][pos_c] == 1)
        return 1;
    else
        return 0;
}

int way_to_top(int row, int col, int matrix[row][col], int start_row, int start_col)
{
    if (start_row == row - 1 && start_col == col - 1)
        return 1;
    int right_r = start_row;
    int right_c = start_col + 1;
    int r = 0;
    if (valid(row, col, matrix, right_r, right_c) == 1)
        r = way_to_top(row, col, matrix, right_r, right_c);
    int up_r = start_row + 1;
    int up_c = start_col;
    int u = 0;
    if (valid(row, col, matrix, up_r, up_c) == 1)
        u = way_to_top(row, col, matrix, up_r, up_c);
    return r + u;
}

int main()
{
    int row, col;
    scanf("%d%d", &row, &col);
    int matrix[row][col];
    for (int i = row - 1; i >= 0; i--)
        for (int j = 0; j < col; j++)
            scanf("%d", &matrix[i][j]);
    printf("%d", way_to_top(row, col, matrix, 0, 0));
}