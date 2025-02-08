#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int a, b, c, d, e, p, q, r, s, x, y, F;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &p, &q, &r, &s, &x, &y, &F);
    int gold = 0;
    bool from_trans = false;
    while (F > 0)
    {
        if (x == p && y == q && !from_trans)
        {
            x = r;
            y = s;
            from_trans = true;
            continue;
        }
        else if (x == r && y == s && !from_trans)
        {
            x = p;
            y = q;
            from_trans = true;
            continue;
        }
        if (!from_trans)
            gold += abs(c*x + d*y) % e;
        else
            from_trans = false;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int dir = abs(a*x + b*y) % 4;
        x += dx[dir];
        y += dy[dir];
        F--;
    }
    if (x == p && y == q)
    {
        x = r;
        y = s;
    }
    else if (x == r && y == s)
    {
        x = p;
        y = q;
    }
    else
        gold += abs(c*x + d*y) % e;
    printf("%d\n%d %d\n", gold, x, y);
}