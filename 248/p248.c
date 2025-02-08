#include <stdio.h>
#include <stdlib.h>

void print(int attempt[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        printf("%d", attempt[i][0]);
        for (int j = 1; j < 9; j++)
            printf(" %d", attempt[i][j]);
        printf("\n");
    }
    exit(0);
}

int test(int board[9][9], int attempt[9][9], int index)
{
    for (int k = 0; k < index; k++)
    {
        int mine = 0;
        int i = k / 9;
        int j = k % 9;
        if ((i < 8 && k >= index - 10) || (index != 81 && k == index - 1))
            continue;
        if (attempt[i][j] == 1)
            mine++;
        if (i > 0 && j > 0 && attempt[i - 1][j - 1] == 1)
            mine++;
        if (i > 0 && attempt[i - 1][j] == 1)
            mine++;
        if (i > 0 && j < 8 && attempt[i - 1][j + 1] == 1)
            mine++;
        if (j > 0 && attempt[i][j - 1] == 1)
            mine++;
        if (j < 8 && attempt[i][j + 1] == 1)
            mine++;
        if (i < 8 && j > 0 && attempt[i + 1][j - 1] == 1)
            mine++;
        if (i < 8 && attempt[i + 1][j] == 1)
            mine++;
        if (i < 8 && j < 8 && attempt[i + 1][j + 1] == 1)
            mine++;
        if (mine != board[i][j])
            return 0;
    }
    return 1;
}

void find_solution(int board[9][9], int attempt[9][9], int row, int col)
{
    if (row >= 9)
    {
        if (test(board, attempt, row * 9 + col) == 1)
        {
            print(attempt);
            return;
        }
    }
    attempt[row][col] = 0;
    if (test(board, attempt, row * 9 + col) == 1)
    {
        if (col == 8)
            find_solution(board, attempt, row + 1, 0);
        else
            find_solution(board, attempt, row, col + 1);
    }
    attempt[row][col] = 1;
    if (test(board, attempt, row * 9 + col) == 1)
    {
        if (col == 8)
            find_solution(board, attempt, row + 1, 0);
        else
            find_solution(board, attempt, row, col + 1);
    }
    return;
}

int main()
{
    int board[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            scanf("%d", &board[i][j]);
    int attempt[9][9] = {0};
    find_solution(board, attempt, 0, 0);
    printf("no solution\n");
}