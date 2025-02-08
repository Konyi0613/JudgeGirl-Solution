#include <stdio.h>

int main()
{
    int x[4], y[4];
    for (int i = 0; i < 4; i++)
        scanf("%d%d", &x[i], &y[i]);
    int perimeter = 2 * ((x[2] - x[0]) + (y[2] - y[0]));
    int area = (x[2] - x[0]) * (y[2] - y[0]) - (x[2] - x[1]) * (y[1] - y[0]) - (x[3] - x[0]) * (y[2] - y[3]);
    printf("%d\n%d\n", perimeter, area);
}