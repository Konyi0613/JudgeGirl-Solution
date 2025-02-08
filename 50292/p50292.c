#include <stdio.h>

int quadrant(int x, int y)
{
    if (x >= 0 && y >= 0)
        return 1;
    else if (x < 0 && y >= 0)
        return 2;
    else if (x <= 0 && y < 0)
        return 3;
    else
        return 4;
}

int main()
{
    int lx, ly, rx, ry;
    scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
    int quadrant_l = quadrant(lx, ly), quadrant_r = quadrant(rx, ry);
    int area[4] = {0};
    int t = (rx - lx) * (ry - ly);
    if (quadrant_r == quadrant_l)
        area[quadrant_r - 1] = t;
    else if (quadrant_r == 1)
    {
        if (quadrant_l == 2)
        {
            area[0] = rx * (ry - ly);
            area[1] = t - area[0];
        }
        else if (quadrant_l == 3)
        {
            area[0] = rx * ry;
            area[1] = ry * (-lx);
            area[2] = lx * ly;
            area[3] = t - area[0] - area[1] - area[2];
        }
        else
        {
            area[0] = (rx - lx) * ry;
            area[3] = t - area[0];
        }
    }
    else if (quadrant_r == 2)
    {
        area[1] = (rx - lx) * ry;
        area[2] = t - area[1];
    }
    else
    {
        area[3] = rx * (ry - ly);
        area[2] = t - area[3];
    }
    printf("%d\n%d\n%d\n%d\n", area[0], area[1], area[2], area[3]);
}