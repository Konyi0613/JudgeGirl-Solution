#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int area = 0;
    int x1, y1, x2, y2;
    scanf("%d%d", &x1, &y1);
    int head_x = x1, head_y = y1;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &x2, &y2);
        area += (x1 * y2 - x2 * y1);
        x1 = x2;
        y1 = y2;
    }
    area += (x1 * head_y - y1 * head_x);
    printf("%d", area);
}