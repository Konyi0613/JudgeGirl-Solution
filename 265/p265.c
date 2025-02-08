#include <stdio.h>

int main()
{
    int x, y, xmin, xmax, ymin, ymax;
    int count = 0;
    while (scanf("%d%d", &x, &y) != EOF)
    {
        if (count == 0)
        {
            xmin = x;
            xmax = x;
            ymin = y;
            ymax = y;
            count = 1;
            continue;
        }
        if (x < xmin)
            xmin = x;
        else if (x > xmax)
            xmax = x;
        if (y < ymin)
            ymin = y;
        else if (y > ymax)
            ymax = y;
    }
    printf("%d", (xmax - xmin) * (ymax - ymin));
}