#include <stdio.h>

int way_to_top(int start_row, int start_col, int row, int col)
{
    if (start_row == row - 1 && start_col == col - 1)
        return 1;
    int r = 0;
    int c = 0;
    if (start_row < row - 1)
        r = way_to_top(start_row + 1, start_col, row, col);
    if (start_col < col - 1)
        c = way_to_top(start_row, start_col + 1, row, col);
    return r + c;
}

int main()
{
    int row, col;
    scanf("%d%d", &row, &col);
    printf("%d", way_to_top(0, 0, row, col));
}