#include <stdio.h>
#include <stdbool.h>

int cross(int x1, int x2, int x3, int y1, int y2, int y3)
{
    if ((x2 - x1) * (y3 - y1) >= (y2 - y1) * (x3 - x1))
        return 1;
    else
        return -1;
}

int main()
{
    int x[3], y[3];
    for (int i = 0; i < 3; i++)
        scanf("%d%d", &x[i], &y[i]);
    if (cross(x[0], x[1], x[2], y[0], y[1], y[2]) < 0)
    {
        int tmp = x[1];
        x[1] = x[2];
        x[2] = tmp;

        tmp = y[1];
        y[1] = y[2];
        y[2] = tmp;
    }
    int lx = x[0], ly = y[0], rx = x[0], ry = y[0];
    for (int i = 1; i <= 2; i++)
    {
        if (x[i] < lx)
            lx = x[i];
        else if (x[i] > rx)
            rx = x[i];
        
        if (y[i] < ly)
            ly = y[i];
        else if (y[i] > ry)
            ry = y[i];
    }
    int num = 0;
    int dx[4] = {0, 0, 1, 1};
    int dy[4] = {0, 1, 0, 1};
    for (int i = lx; i <= rx; i++)
        for (int j = ly; j <= ry; j++)
        {
            bool in = true;
            for (int k = 0; k < 4; k++)
            {
                int new_x = i + dx[k];
                int new_y = j + dy[k];
                for (int s = 0; s < 3; s++)
                    if (cross(new_x, x[s % 3], x[(s + 1) % 3], new_y, y[s % 3], y[(s + 1) % 3]) < 0)
                    {
                        in = false;
                        break;
                    }
                if (!in)
                    break;
            }
            if (in)
                num++;
        }
    printf("%d\n", num);
}