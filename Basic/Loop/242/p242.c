#include <stdio.h>
// #define DEBUG
typedef struct
{
    long long x;
    long long y;
    long long r;
} Circle;

long long distance_square(long long x, long long y, Circle c)
{
    return ((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y));
}
int main()
{
    // scanf c1 c2 c3
    int n;
    scanf("%d", &n);
    Circle circle[3];
    int in_1 = 0;
    int in_3 = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &circle[0].x, &circle[0].y, &circle[0].r, &circle[1].x, &circle[1].y, &circle[1].r, &circle[2].x, &circle[2].y, &circle[2].r);
#ifdef DEBUG
        printf("\n%d %d %d\n%d %d %d\n%d %d %d\n", circle[0].x, circle[0].y, circle[0].r, circle[1].x, circle[1].y, circle[1].r, circle[2].x, circle[2].y, circle[2].r);
        return 0;
#endif
        // horizontal count
        // vertical count
        // do vertical count while doing horizontal count
        // 0 to i
        // 1 to (i+1)%3
        // 2 to (i+2)%3
        for (int i = 0; i < 3; i++)
        {
            int l0 = i, l1 = (i + 1) % 3, l2 = (i + 2) % 3;
            for (long long counter_x = circle[l0].x - circle[l0].r; counter_x <= circle[l0].x + circle[l0].r; counter_x++)
            {
                // from (circle[0].x,circle[0].y) go up and go down
                long long counter_y = circle[l0].y;
                while (distance_square(counter_x, counter_y, circle[l0]) <= circle[l0].r * circle[l0].r)
                {
                    // go up
                    if ((distance_square(counter_x, counter_y, circle[l1]) > circle[l1].r * circle[l1].r) &&
                        (distance_square(counter_x, counter_y, circle[l2]) > circle[l2].r * circle[l2].r))
                    {
                        in_1++;
                        // printf("in_1_circle[%d]: (%lld,%lld)\n", l0, counter_x, counter_y);
                    }
                    else if (l0 == 0 && ((distance_square(counter_x, counter_y, circle[l1]) <= circle[l1].r * circle[l1].r) &&
                                         (distance_square(counter_x, counter_y, circle[l2]) <= circle[l2].r * circle[l2].r)))
                    {
                        in_3++;
                        // printf("in_3_circle[%d]: (%lld,%lld)\n", l0, counter_x, counter_y);
                    }
                    counter_y++;
                }
                counter_y = circle[l0].y - 1;
                while (distance_square(counter_x, counter_y, circle[l0]) <= circle[l0].r * circle[l0].r)
                {
                    // go down
                    if ((distance_square(counter_x, counter_y, circle[l1]) > circle[l1].r * circle[l1].r) &&
                        (distance_square(counter_x, counter_y, circle[l2]) > circle[l2].r * circle[l2].r))
                    {
                        in_1++;
                        // printf("in_1_circle[%d]: (%lld,%lld)\n", l0, counter_x, counter_y);
                    }
                    else if (l0 == 0 && ((distance_square(counter_x, counter_y, circle[l1]) <= circle[l1].r * circle[l1].r) &&
                                         (distance_square(counter_x, counter_y, circle[l2]) <= circle[l2].r * circle[l2].r)))
                    {
                        in_3++;
                        // printf("in_3_circle[%d]: (%lld,%lld)\n", l0, counter_x, counter_y);
                    }
                    counter_y--;
                }
            }
        }
        // printf("in_1: %d in_3: %d\n", in_1, in_3);
        printf("%d\n", in_1 + in_3);
        in_1 = 0;
        in_3 = 0;
    }
}