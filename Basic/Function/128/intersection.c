#include <stdio.h>
#include <stdbool.h>
#include "intersection.h"

void intersection(int map[100][100], int result[4])
{
    int intersection = 0, t_junc = 0, turn = 0, dead_end = 0;
    for (int row = 0; row < 100; row++)
    {
        for (int col = 0; col < 100; col++)
        {
            if (map[row][col] == 1)
            {
                int neighbor = 0;
                for (int drow = -1; drow <= 1; drow++)
                {
                    for (int dcol = -1; dcol <= 1; dcol++)
                    {
                        if ((drow * dcol != 0) || (row + drow >= 100) || (row + drow < 0) || (col + dcol >= 100) || (col + dcol < 0) || (drow == 0 && dcol == 0))
                            continue;
                        neighbor += (map[row + drow][col + dcol] == 1);
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
                    if (!(row == 0 || row == 99))
                    {
                        if (((map[row - 1][col] == 1 && map[row + 1][col] == 1)))
                        {
                            horizon = true;
                        }
                    }
                    if (!(col == 0 || col == 99))
                    {
                        if (((map[row][col - 1] == 1 && map[row][col + 1] == 1)))
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
    result[0] = intersection;
    result[1] = t_junc;
    result[2] = turn;
    result[3] = dead_end;
}