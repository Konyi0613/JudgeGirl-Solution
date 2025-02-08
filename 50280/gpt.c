#include <stdio.h>
#include <stdbool.h>
// #define DEBUG
int drow[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dcol[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool can_place_knight(int height, int width, int row, int col, int board[height][width])
{
    if (board[row][col] != 0)
        return false;
    for (int i = 0; i < 8; i++)
    {
        int attack_r = row + drow[i];
        int attack_c = col + dcol[i];
        if (attack_r >= 0 && attack_r < height && attack_c >= 0 && attack_c < width && board[attack_r][attack_c] == 1)
        {
            return false;
        }
    }
    return true;
}

int mark_attacked_cells(int height, int width, int row, int col, int board[height][width], int mark, int target)
{
    int reduce_space = 0;
    for (int i = 0; i < 8; i++)
    {
        int attack_r = row + drow[i];
        int attack_c = col + dcol[i];
        if (attack_r >= 0 && attack_r < height && attack_c >= 0 && attack_c < width && board[attack_r][attack_c] == target)
        {
            board[attack_r][attack_c] = mark; // Temporarily mark/unmark as attacked
            reduce_space++;
        }
    }
    return reduce_space;
}

void find_solution(int height, int width, int board[height][width], int knight_num, int *best, int now_row, int now_col, int available_space)
{
    if (knight_num + available_space <= *best)
        return; // Prune if can't improve best
    if (now_row == height)
    { // Reached end
        if (knight_num > *best)
        {
#ifdef DEBUG
            printf("available space: %d\n", available_space);
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

    int next_row = now_row + (now_col == width - 1);
    int next_col = (now_col + 1) % width;

    if (can_place_knight(height, width, now_row, now_col, board))
    {
        board[now_row][now_col] = 1; // Place knight
        int reduced_space = available_space - 1;

        int reduce = mark_attacked_cells(height, width, now_row, now_col, board, now_row * width + now_col + 10, 0); // Mark attacked cells
        reduced_space -= reduce;

        find_solution(height, width, board, knight_num + 1, best, next_row, next_col, reduced_space);
        board[now_row][now_col] = 0;
        mark_attacked_cells(height, width, now_row, now_col, board, 0, now_row * width + now_col + 10);
    }

    find_solution(height, width, board, knight_num, best, next_row, next_col, available_space);
}

int main()
{
    int height, width;
    scanf("%d%d", &height, &width);

    int board[height][width];
    int available_space = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            board[i][j] = 0;   // 0 represents empty cell
            available_space++; // Initially count all cells as available
        }
    }

    // Read rocks and mark them on board
    int row, col;
    while (scanf("%d%d", &row, &col) != EOF)
    {
        board[row][col] = 3; // 3 represents a rock
        available_space--;   // Rocks reduce available space
    }

    int best = 0;
    find_solution(height, width, board, 0, &best, 0, 0, available_space);
    printf("%d\n", best);
    return 0;
}
