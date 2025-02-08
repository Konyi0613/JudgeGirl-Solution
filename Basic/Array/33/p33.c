#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    int intersection = 0, t_junc = 0, turn = 0, dead_end = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (a[row][col] == 1)
            {
                int neighbor = 0;
                for (int drow = -1; drow <= 1; drow++)
                {
                    for (int dcol = -1; dcol <= 1; dcol++)
                    {
                        if ((drow * dcol != 0) || (row + drow >= n) || (row + drow < 0) || (col + dcol >= n) || (col + dcol < 0) || (drow == 0 && dcol == 0))
                            continue;
                        neighbor += (a[row + drow][col + dcol] == 1);
                    }
                }
                if (neighbor == 4)
                    intersection++;
                else if (neighbor == 3)
                    t_junc++;
                else if (neighbor == 2)
                {
                    bool horizon = false;
                    bool vertical = false;
                    if (!(row == 0 || row == n - 1))
                    {
                        if (((a[row - 1][col] == 1 && a[row + 1][col] == 1)))
                        {
                            horizon = true;
                        }
                    }
                    if (!(col == 0 || col == n - 1))
                    {
                        if (((a[row][col - 1] == 1 && a[row][col + 1] == 1)))
                        {
                            vertical = true;
                        }
                    }
                    if (!horizon && !vertical)
                        turn++;
                }
                else if (neighbor == 1)
                    dead_end++;
            }
        }
    }
    printf("%d\n%d\n%d\n%d\n", intersection, t_junc, turn, dead_end);
}