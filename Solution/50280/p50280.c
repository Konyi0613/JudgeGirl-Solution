#include <stdio.h>
#include <stdbool.h>
// #define DEBUG
void find_solution(int height, int width, int board[height][width], int knight_num, int *best, int now_row, int now_col)
{
    if (now_row == height)
    {
        if (knight_num > *best)
        {
#ifdef DEBUG
            printf("best: %d\n", *best);
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                    printf("%d ", board[i][j]);
                printf("\n");
            }
#endif
            *best = knight_num;
        }
        return;
    }
    if (knight_num + height * width - (now_row * width + now_col) <= *best)
        return;
    int drow[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dcol[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

    int next_row, next_col;
    if (now_col == width - 1)
    {
        next_col = 0;
        next_row = now_row + 1;
    }
    else
    {
        next_col = now_col + 1;
        next_row = now_row;
    }
    if (board[now_row][now_col] == 0)
    {
        board[now_row][now_col] = 1;
        for (int i = 0; i < 8; i++)
        {
            int attack_r = now_row + drow[i];
            int attack_c = now_col + dcol[i];
            if (attack_r >= 0 && attack_r < height && attack_c >= 0 && attack_c < width)
                if (board[attack_r][attack_c] == 0)
                    board[attack_r][attack_c] = now_row * width + now_col + 10;
        }
        find_solution(height, width, board, knight_num + 1, best, next_row, next_col);
        board[now_row][now_col] = 0;
        for (int i = 0; i < 8; i++)
        {
            int attack_r = now_row + drow[i];
            int attack_c = now_col + dcol[i];
            if (attack_r >= 0 && attack_r < height && attack_c >= 0 && attack_c < width)
                if (board[attack_r][attack_c] == now_row * width + now_col + 10)
                    board[attack_r][attack_c] = 0;
        }
    }
    find_solution(height, width, board, knight_num, best, next_row, next_col);
}

int main()
{
    int height, width;
    scanf("%d%d", &height, &width);
    int board[height][width];
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            board[i][j] = 0;
    int row, col;
    while (scanf("%d%d", &row, &col) != EOF)
        board[row][col] = 3;
    int best = 0;
    find_solution(height, width, board, 0, &(best), 0, 0);
    printf("%d", best);
}