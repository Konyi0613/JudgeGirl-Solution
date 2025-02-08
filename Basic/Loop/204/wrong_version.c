#include <stdio.h>
#include <stdbool.h>
// #define DEBUG
#define up 1
#define down 2
#define right -1
#define left -2
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
    // repeat 2(W+D) times with a counter 'i', and decide the initial direction by 'i'
    // use counters x,y to represent the initial coordinate
    //  use dx,dy to move
    // if touch mirror, change direction
    // if touch side, return number
    for (int i = 0; i < 2 * (W + D); i++)
    {
        int x, y;
        int direction;
        int flag;
        if ((0 <= i) && (i <= W - 1))
            flag = 0;
        else if ((W <= i) && (i <= W + D - 1))
            flag = 1;
        else if ((W + D <= i) && (i <= W + W + D - 1))
            flag = 2;
        else
            flag = 3;
        switch (flag)
        {
        case 0:
            x = i;
            y = 0;
            direction = up;
            break;
        case 2:
            x = W - (i - (W + D)) - 1;
            y = D - 1;
            direction = down;
            break;
        case 1:
            x = W - 1;
            y = (i - W);
            direction = left;
            break;
        case 3:
            x = 0;
            y = D - (i - W - W - D) - 1;
            direction = right;
            break;
        default:
            printf("flag wrong");
            break;
        }
#ifdef DEBUG
        printf("i: %d x: %d y: %d direction: %d\n", i, x, y, direction);
#endif
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int direction_transform = 0;
        while (x >= 0 && y >= 0 && x <= W - 1 && y <= D - 1)
        {
            if (mirror[x][y] == true)
                direction = (-1) * direction;
            // if (direction > 0)
            // direction_transform = direction - 1;
            // else
            // direction_transform = -direction + 1;
            switch (direction)
            {
            case up:
                direction_transform = 0;
                break;
            case down:
                direction_transform = 1;
                break;
            case left:
                direction_transform = 3;
                break;
            case right:
                direction_transform = 2;
                break;
            default:
                break;
            }
            // up to 0,down to 1,right to 2,left to 3
            x += dx[direction_transform];
            y += dy[direction_transform];
        }
        // x -= dx[direction_transform];
        // y -= dy[direction_transform];
#ifdef DEBUG
        printf("i: %d x: %d y: %d direction: %d\n", i, x, y, direction);
#endif
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