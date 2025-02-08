#include <stdio.h>

int main()
{
    int x[3], y[3];
    scanf("%d%d%d%d%d%d", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
    for (int i = 0; i < 3; i++)
    {
        int vx[2], vy[2];
        vx[0] = x[(i + 1) % 3] - x[i];
        vx[1] = x[(i + 2) % 3] - x[i];
        vy[0] = y[(i + 1) % 3] - y[i];
        vy[1] = y[(i + 2) % 3] - y[i];
        printf("%d\n%d\n", x[i] + vx[0] + vx[1], y[i] + vy[0] + vy[1]);
    }
}