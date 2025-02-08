#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    char name[n][64];
    int board[n][m][m];
    int check_line[n][m][m];
    int brow[n][m * m + 1];
    int bcol[n][m * m + 1];
    bool bingo[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", name[i]);
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < m; col++)
            {
                scanf("%d", &board[i][row][col]);
                check_line[i][row][col] = 0;
                brow[i][board[i][row][col]] = row;
                bcol[i][board[i][row][col]] = col;
            }
        }
        bingo[i] = false;
    }
    int sequence[m * m];
    for (int i = 0; i < m * m; i++)
        scanf("%d", &sequence[i]);
    for (int i = 0; i < m * m; i++)
    {
        bool printf_seq = false;
        for (int player = 0; player < n; player++)
        {
            int row = brow[player][sequence[i]];
            int col = bcol[player][sequence[i]];
            bool lock_ho = false, lock_ver = false, lock_trace = false, lock_con_trace = false;

            if (sequence[i] == board[player][row][col])
            {
                check_line[player][row][col] = 1;
                for (int counter = 0; counter < m; counter++)
                {
                    if (check_line[player][row][counter] == 0)
                        lock_ho = true;
                    if (check_line[player][counter][col] == 0)
                        lock_ver = true;
                    if (check_line[player][counter][counter] == 0)
                        lock_trace = true;
                    if (check_line[player][counter][m - 1 - counter] == 0)
                        lock_con_trace = true;
                }
                if ((lock_ho == false || lock_ver == false || lock_trace == false || lock_con_trace == false))
                {
                    bingo[player] = true;
                    printf_seq = true;
                }
                row = m;
                col = m;
            }
        }
        if (printf_seq)
        {
            printf("%d", sequence[i]);
            for (int k = 0; k < n; k++)
            {
                if (bingo[k])
                    printf(" %s", name[k]);
            }
            return 0;
        }
    }
}