#include <stdio.h>
#include <stdbool.h>
void insert_bishop(int col, int row, int size_col, int size_row, int a[size_col][size_row])
{
    // trace dir
    int col_counter = col + 1;
    int row_counter = row + 1;
    while (col_counter < size_col && row_counter < size_row)
    {
        if (a[col_counter][row_counter] != 1)
        {
            a[col_counter][row_counter] = 1;
        }
        else
            break;
        col_counter++;
        row_counter++;
    }
    col_counter = col - 1;
    row_counter = row - 1;
    while (col_counter >= 0 && row_counter >= 0)
    {
        if (a[col_counter][row_counter] != 1)
        {
            a[col_counter][row_counter] = 1;
        }
        else
            break;
        col_counter--;
        row_counter--;
    }
    // converse trace dir
    col_counter = col - 1;
    row_counter = row + 1;
    while (col_counter >= 0 && row_counter < size_row)
    {
        if (a[col_counter][row_counter] != 1)
        {
            a[col_counter][row_counter] = 1;
        }
        else
            break;
        col_counter--;
        row_counter++;
    }
    col_counter = col + 1;
    row_counter = row - 1;
    while (col_counter < size_col && row_counter >= 0)
    {
        if (a[col_counter][row_counter] != 1)
        {
            a[col_counter][row_counter] = 1;
        }
        else
            break;
        col_counter++;
        row_counter--;
    }
}
void insert_rook(int col, int row, int size_col, int size_row, int a[size_col][size_row])
{
    int col_counter = col + 1;
    int row_counter = row;
    while (col_counter < size_col)
    {
        if (a[col_counter][row_counter] != 1)
        {
            a[col_counter][row_counter] = 1;
        }
        else
            break;
        col_counter++;
    }
    col_counter = col - 1;
    row_counter = row;
    while (col_counter >= 0)
    {
        if (a[col_counter][row_counter] != 1)
        {
            a[col_counter][row_counter] = 1;
        }
        else
            break;
        col_counter--;
    }
    col_counter = col;
    row_counter = row + 1;
    while (row_counter < size_row)
    {
        if (a[col_counter][row_counter] != 1)
        {
            a[col_counter][row_counter] = 1;
        }
        else
            break;
        row_counter++;
    }
    col_counter = col;
    row_counter = row - 1;
    while (row_counter >= 0)
    {
        if (a[col_counter][row_counter] != 1)
        {
            a[col_counter][row_counter] = 1;
        }
        else
            break;
        row_counter--;
    }
}
void insert_queen(int col, int row, int size_col, int size_row, int a[size_col][size_row])
{
    insert_bishop(col, row, size_col, size_row, a);
    insert_rook(col, row, size_col, size_row, a);
}

void insert(int type, int col, int row, int size_col, int size_row, int a[size_col][size_row])
{
    if (type == 0)
        a[col][row] = 1;
    else if (type == 1)
        insert_queen(col, row, size_col, size_row, a);
    else if (type == 2)
        insert_bishop(col, row, size_col, size_row, a);
    else
        insert_rook(col, row, size_col, size_row, a);
}

int main()
{
    int size_col, size_row;
    scanf("%d%d", &size_row, &size_col);
    int a[size_col][size_row]; // a[col][row]
    for (int i = 0; i < size_col; i++)
        for (int j = 0; j < size_row; j++)
            a[i][j] = 0;
    int type = 0, col = 0, row = 0;
    while (scanf("%d%d%d", &type, &col, &row) != EOF)
    {
        a[col][row] = 1;
        insert(type, col, row, size_col, size_row, a);
    }
    for (int r = 0; r < size_row; r++)
    {
        for (int c = 0; c < size_col; c++)
        {
            if (c == size_col - 1)
                printf("%d\n", a[c][r]);
            else
                printf("%d ", a[c][r]);
        }
    }
}