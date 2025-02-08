#include <stdio.h>
// #define debug

int main()
{
    int x[4] = {0}, y[4] = {0};
    int i = 0;
    while (scanf("%d%d", &x[i], &y[i]) != EOF)
    {
        if (i < 3)
        {
            i++;
            continue;
        }
#ifdef debug
        printf("%d %d %d %d %d %d %d %d\n", x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3]);
#endif
        int distA = (x[0] - x[3]) * (x[0] - x[3]) + (y[0] - y[3]) * (y[0] - y[3]);
        int distB = (x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]);
        int distC = (x[2] - x[3]) * (x[2] - x[3]) + (y[2] - y[3]) * (y[2] - y[3]);
        int min = distA;
        if (min > distB)
            min = distB;
        if (min > distC)
            min = distC;
#ifdef debug
        printf("%d ", min);
#endif
        int score = 0;
        int same_point = 0;
        if (min == distA)
        {
            score += 1;
            same_point++;
        }
        if (min == distB)
        {
            score += (2 + same_point);
            same_point++;
        }
        if (min == distC)
        {
            score += (3 + same_point);
        }
#ifdef debug
        printf("%d ", score);
#endif
        int ans = score % 9;
        printf("%d ", ans);
        i = 0;
    }
}