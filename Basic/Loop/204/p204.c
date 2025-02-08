#include <stdio.h>
#include <stdbool.h>
int main()
{
    int W, D;
    scanf("%d%d", &W, &D);
    // input mirror
    bool mirror[W][D];
    for (int j = D - 1; j >= 0; j--)
        for (int i = 0; i < W; i++)
        {
            int temp;
            scanf("%d", &temp);
            mirror[i][j] = (temp == 1);
        }
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    int new_dir[4] = {3, 2, 1, 0};
    for (int i = 0; i < 2 * (W + D); i++)
    {
        int x, y;
        int direction;
        if ((0 <= i) && (i <= W - 1))
        {
            x = i;
            y = 0;
            direction = 0;
        }
        else if ((W <= i) && (i <= W + D - 1))
        {
            x = W - 1;
            y = (i - W);
            direction = 1;
        }
        else if ((W + D <= i) && (i <= W + W + D - 1))
        {
            x = W - (i - (W + D)) - 1;
            y = D - 1;
            direction = 2;
        }
        else
        {
            x = 0;
            y = D - (i - W - W - D) - 1;
            direction = 3;
        }
        while (x >= 0 && y >= 0 && x <= W - 1 && y <= D - 1)
        {
            if (mirror[x][y] == true)
                direction = new_dir[direction];
            x += dx[direction];
            y += dy[direction];
        }
        if (y >= D)
        {
            printf("%d\n", W + D - 1 + (W - x));
        }
        else if (y < 0)
        {
            printf("%d\n", x);
        }
        else if (x >= W)
        {
            printf("%d\n", W + y);
        }
        else
        {
            printf("%d\n", W + W + D + (D - y) - 1);
        }
    }
}