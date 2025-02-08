#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int t1_x, t1_y, t2_x, t2_y;
    int w1, h1, w2, h2;
    scanf("%d%d%d%d", &t1_x, &t1_y, &w1, &h1);
    int area_sum = w1 * h1;
    for (int j = 0; j < n - 1; j++)
    {
        scanf("%d%d%d%d", &t2_x, &t2_y, &w2, &h2);
        // consider R1 overlap R3

        int target_w = t1_x + w1 - t2_x, target_h = t1_y + h1 - t2_y;
        area_sum += (w2 * h2 - (target_w * target_h));
        t1_x = t2_x;
        t1_y = t2_y;
        w1 = w2;
        h1 = h2;
    }
    printf("%d", area_sum);
}