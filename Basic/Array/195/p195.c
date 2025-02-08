#include <stdio.h>
#include <stdbool.h>
int who_win(int x, int y, int board[3][3])
{
    if (board[x][y] != 0 && board[0][y] == board[1][y] && board[0][y] == board[2][y])
        return board[x][y];
    if (board[x][y] != 0 && board[x][0] == board[x][1] && board[x][0] == board[x][2])
        return board[x][y];
    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0];
    if (board[2][0] != 0 && board[2][0] == board[1][1] && board[2][0] == board[0][2])
        return board[2][0];
    return -1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int board[3][3] = {0};
    int x, y;
    int player = 1; // 1 = black, 2 = white
    for (int move = 0; move < n; move++)
    {
        scanf("%d%d", &x, &y);
        if (x > 2 || x < 0 || y > 2 || y < 0)
            continue;
        if (board[x][y] != 0)
            continue;
        board[x][y] = player;
        if (who_win(x, y, board) == -1)
        {
            player = (player == 1) ? 2 : 1;
        }
        else
        {
            if (who_win(x, y, board) == 1)
            {
                printf("Black wins.");
            }
            else
            {
                printf("White wins.");
            }
            return 0;
        }
    }
    printf("There is a draw.");
}