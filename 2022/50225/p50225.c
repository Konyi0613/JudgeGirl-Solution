#include <stdio.h>

int main()
{
    int N, M, k;
    scanf("%d%d%d", &N, &M, &k);
    int x = 1, y = 1;
    while (k > 1)
    {
        k--;
        if ((x == M) && (((x >= y) + 1) % 2 == 0))
        {
            y++;
            x = y - 1;
            continue;
        }
        if ((y == N) && ((x >= y) == 0))
        {
            x++;
            y = x;
            continue;
        }
        x += (x >= y);
        y += ((x >= y) + 1) % 2;
    }
    printf("%d %d", y, x);
}